/* 
* @Author: gicque_p
* @Date:   2015-04-19 11:57:42
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-26 21:08:10
*/

#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent, Reception *reception) : QMainWindow(parent), _ui(new Ui::MainWindow), _reception(reception) {
	QTimer *timer = new QTimer(this);
	QTimer *day = new QTimer(this);

	timer->start(500);
	day->start(this->_reception->getPreparePizza() * this->_reception->getReplaceStock() * 30);

	this->_ui->setupUi(this);

	QObject::connect(this->_ui->actionQuit, SIGNAL(triggered()), this, SLOT(quitWindow()));
	QObject::connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(quitWindow()));

	QObject::connect(this->_ui->tableKitchen, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)), SLOT(switchItem(QListWidgetItem *, QListWidgetItem *)));

	QObject::connect(this->_ui->sliderPizzaNumber, SIGNAL(valueChanged(int)), this->_ui->pizzaNumber, SLOT(display(int)));
	QObject::connect(this->_ui->buttonOrder, SIGNAL(clicked()), SLOT(getOrderFromForm()));
	QObject::connect(this->_ui->linePizzaOrder, SIGNAL(returnPressed()), SLOT(getOrderFromLine()));

	QObject::connect(this->_ui->actionOpenMan, SIGNAL(triggered()), this, SLOT(openMan()));
	QObject::connect(this->_ui->actionOpenQt, SIGNAL(triggered()), this, SLOT(openQt()));
	QObject::connect(this->_ui->actionOpenLog, SIGNAL(triggered()), this, SLOT(openLog()));
	QObject::connect(this->_ui->actionAchievment, SIGNAL(triggered()), this, SLOT(openAchievment()));

	QObject::connect(timer, SIGNAL(timeout()), SLOT(refresh()));
	QObject::connect(day, SIGNAL(timeout()), SLOT(newDay()));
};

MainWindow::~MainWindow(void) {
	delete this->_ui;
}

void MainWindow::quitWindow(void) {
	this->_reception->stop();
	qApp->quit();
}

void MainWindow::switchItem(QListWidgetItem *current, QListWidgetItem *previous) {
	(void)previous;

	if (current != NULL) {
		for (std::list<Kitchen>::iterator it = this->_reception->getKitchens()->begin(); it != this->_reception->getKitchens()->end(); it++) {
			if (it->getName() == current->text().toStdString()) {
				this->_reception->setCurrentKitchen(*it);
				break;
			}
		}
		this->refresh();
	}
}

void MainWindow::getOrderFromForm(void) {
	std::stringstream stream;

	stream << this->_ui->boxPizzaType->currentText().toStdString();
	stream << " ";
	stream << this->_ui->boxPizzaSize->currentText().toStdString();
	stream << " x";
	stream << this->_ui->sliderPizzaNumber->value();
	stream << ";";

	Parsing parsing;
	bool errorFlag(false);

	try {
		parsing.prepareOrders(this->_reception, stream.str());
	} catch (const ParsingError &error) {
		QMessageBox::critical(this, "Pizza Order", error.what());
		this->_reception->_log.write(error.what());
		errorFlag = true;
	}

	if (!errorFlag) {
		QMessageBox::information(this, "Pizza Order", stream.str().c_str());
	}

	this->_ui->boxPizzaType->setCurrentIndex(0);
	this->_ui->boxPizzaSize->setCurrentIndex(0);
	this->_ui->sliderPizzaNumber->setValue(1);
	this->_ui->tableKitchen->clear();

	try {
		this->_reception->run();	
	} catch (const Error &error) {
		QMessageBox::critical(this, error.where(), error.what());
		this->_reception->_log.write(error.what());
		this->quitWindow();
	}

	for (std::list<Kitchen>::iterator it = this->_reception->getKitchens()->begin(); it != this->_reception->getKitchens()->end(); it++) {
		this->_ui->tableKitchen->addItem(it->getName().c_str());
	}
}

void MainWindow::getOrderFromLine(void) {
	Parsing parsing;
	bool errorFlag(false);

	try {
		parsing.prepareOrders(this->_reception, this->_ui->linePizzaOrder->text().toStdString());
	} catch (const ParsingError &error) {
		QMessageBox::warning(this, "Pizza Order", error.what());
		this->_reception->_log.write(error.what());
		errorFlag = true;
	}

	if (!errorFlag) {
		QMessageBox::information(this, "Pizza Order", this->_ui->linePizzaOrder->text());
	}
	this->_ui->linePizzaOrder->clear();

	try {
		this->_reception->run();	
	} catch (const Error &error) {
		QMessageBox::critical(this, error.where(), error.what());
		this->_reception->_log.write(error.what());
		this->quitWindow();
	}

	for (std::list<Kitchen>::iterator it = this->_reception->getKitchens()->begin(); it != this->_reception->getKitchens()->end(); it++) {
		this->_ui->tableKitchen->addItem(it->getName().c_str());
	}
}

void MainWindow::refresh(void) {
	if (this->_reception->getEarnedMoney() > 1000000) {
		this->_ui->actionAchievment->setEnabled(true);
	} else if (this->_reception->getEarnedMoney() <= 0) {
		QMessageBox::critical(this, "YOU LOOSE", "Out of business, you lost all your money");
		this->_reception->_log.write("Out of business\n");
		this->quitWindow();
	}

	if (this->_reception->verifyKitchenState()) {
		this->refreshList();	
	}

	this->refreshWallet();
	this->refreshStock();
	this->refreshPizzas();
}

void MainWindow::refreshList(void) {
	int row = this->_ui->tableKitchen->currentRow();

	this->_ui->tableKitchen->clear();

	for (std::list<Kitchen>::iterator it = this->_reception->getKitchens()->begin(); it != this->_reception->getKitchens()->end(); it++) {
		this->_ui->tableKitchen->addItem(it->getName().c_str());
	}

	if (this->_ui->tableKitchen->item(row) != NULL) {
		this->_ui->tableKitchen->item(row)->setSelected(true);
	}
}

void MainWindow::refreshWallet(void) {
	std::ostringstream stream;

	stream << "Your wallet: $";
	stream << this->_reception->getEarnedMoney();

	this->_ui->labelWallet->setText(stream.str().c_str());
	this->_ui->barAchievment->setValue(this->_reception->getEarnedMoney() / 10000.f);
}

void MainWindow::refreshStock(void) {
	std::ostringstream stream;

	this->_ui->tableStock->setRowCount(0);
	if (this->_reception->getCurrentKitchen() != NULL) {
		for (int i = 0; i < 9; i++) {
			stream.str("");
			stream.clear();

			this->_ui->tableStock->insertRow(i);
			stream << Misc::getIngredientName((StockType)i);

			QTableWidgetItem *item1 = new QTableWidgetItem();
			item1->setText(stream.str().c_str());
			this->_ui->tableStock->setItem(i, 0, item1);

			stream.str("");
			stream.clear();

			stream << this->_reception->getCurrentKitchen()->getStock((StockType)i) << " units";
			QTableWidgetItem *item2 = new QTableWidgetItem();
			item2->setText(stream.str().c_str());
			this->_ui->tableStock->setItem(i, 1, item2);
		}
	}
}

void MainWindow::refreshPizzas(void) {
	this->_ui->tableWaiting->setRowCount(0);
	this->_ui->tableProcessing->setRowCount(0);
	this->_ui->tableFinished->setRowCount(0);

	std::ostringstream stream;

	Kitchen *kitchen = this->_reception->getCurrentKitchen();
	if (kitchen != NULL and kitchen->getPizzas()->size() > 0) {
		QTableWidget *table;

		for (std::list<Pizza>::iterator it = kitchen->getPizzas()->begin(); it != kitchen->getPizzas()->end(); it++) {
			if (it->getState() == Awaiting) {
				table = this->_ui->tableWaiting;
			} else if (it->getState() == Processing) {
				table = this->_ui->tableProcessing;
			} else {
				table = this->_ui->tableFinished;
			}

			size_t i(table->rowCount());
			table->insertRow(i);

			stream.str("");
			stream.clear();
			stream << Misc::getPizzaTypeName(it->getType());

			QTableWidgetItem *item1 = new QTableWidgetItem();
			item1->setText(stream.str().c_str());
			table->setItem(i, 0, item1);

			stream.str("");
			stream.clear();
			stream << Misc::getPizzaSizeName(it->getSize());

			QTableWidgetItem *item2 = new QTableWidgetItem();
			item2->setText(stream.str().c_str());
			table->setItem(i, 1, item2);
		}
	}
}

void MainWindow::newDay(void) {
	std::ostringstream title;
	std::ostringstream message;
	int value(0);

	title << "Day number " << this->_reception->getDay() << " just finished";

	if ((value = this->_reception->rentNewDay()) < 0) {
		message << "You lost $" << abs(value) << " today :(";
	} else {
		message << "You won $" << abs(value) << " today :)";
	}

	QMessageBox::information(this, title.str().c_str(), message.str().c_str());
}

void MainWindow::openMan(void) {
	std::ostringstream stream;

	stream << "<b>Welcome in Plazza Manual</b><br>";
	stream << "<i>Plazza project is an C++ application wich using processes, threads, mutexes and Qt</i><br><br>";
	stream << "The aim is simple: you start at day one, and your wish is to became richer than Bill Gates himself";
	stream << "<ul><li>Every each specific timelapses, you switch to the next day and infos are given to you about the past day</li>";
	stream << "<li>At any moment, you can <b>order</b> by choising your pizza with a simple form or by entering an old-school command line</li>";
	stream << "<li>To show kitchen status, you simply have to <b>click</b> on its name in the kitchens list</li>";
	stream << "<li>Each <b>sold</b> pizza gives you money (depending on its size and its type)</li>";
	stream << "<li>Moreover, each stock replacement need to be <b>paid</b> (also depending on which ingredients)</li>";
	stream << "<li>Also, each day costs you a rent of <b>$100 by kitchens</b></li>";
	stream << "<li>By the way, if there is no kitchen opened, you will pay a rent of <b>$500</b></li>";
	stream << "<li>If you open a new kitchen it will costs <b>$300</b> but if you sold one, you will earn <b>$250</b></li>";
	stream << "<li>An achievment is unlockable if you reach <b>$1.000.000</b>, so have fun !</li></ul>";
	stream << "<i>Project created by Pierrick Gicquelais, Christian Boisson, Nicolas Ribeiro-Texeira<br>";
	stream << "GUI powered by QtCreator and designed by Pierrick Gicquelais</i>";

	QMessageBox box(this);

	box.setWindowTitle("About");
	box.setTextFormat(Qt::RichText);
	box.setText(stream.str().c_str());
	box.exec();
}

void MainWindow::openQt(void) {
	QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::openLog(void) {
	std::stringstream buffer;
	std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
	bool errorFlag(false);

	try {
		this->_reception->_log.display();
	} catch (const LogError &error) {
		QMessageBox::critical(this, "Logs", error.what());
		errorFlag = true;
	}
	std::cout.rdbuf(old);

	if (!errorFlag) {
		QMessageBox box(this);

		box.setWindowTitle("Logs");
		box.setTextFormat(Qt::RichText);
		box.setText("Here, you can find a log file of all actions of the current day");
		box.setDetailedText(buffer.str().c_str());
		box.exec();
	}
}

void MainWindow::openAchievment(void) {
	QMessageBox::information(this, "GOOD GAME WELL PLAY", "You've earned the reward of loosing your time for nothing, you fool :troll:");
}

void MainWindow::pipes(void)
{
  _reception->readPipes();
}
