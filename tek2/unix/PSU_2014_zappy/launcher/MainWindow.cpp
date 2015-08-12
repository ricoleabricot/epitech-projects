/* 
* @Author: gicque_p
* @Date:   2015-06-23 22:06:31
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-07-01 15:41:24
*/

#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), _ui(new Ui::MainWindow) {
    this->_ui->setupUi(this);

    QObject::connect(this->_ui->actionQuit, SIGNAL(triggered()), this, SLOT(quitWindow()));
    QObject::connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(quitWindow()));

    QObject::connect(this->_ui->actionOpenMan, SIGNAL(triggered()), this, SLOT(openMan()));
    QObject::connect(this->_ui->actionOpenQt, SIGNAL(triggered()), this, SLOT(openQt()));

    QObject::connect(this->_ui->teamLineEdit, SIGNAL(returnPressed()), SLOT(addTeamList()));
    QObject::connect(this->_ui->teamButtonAdd, SIGNAL(clicked()), SLOT(addTeamList()));
    QObject::connect(this->_ui->teamButtonClear, SIGNAL(clicked()), SLOT(clearTeamList()));

    QObject::connect(this->_ui->launchServer, SIGNAL(clicked()), SLOT(launchServer()));
    QObject::connect(this->_ui->launchClient, SIGNAL(clicked()), SLOT(launchClient()));
};

MainWindow::~MainWindow(void) {
    delete this->_ui;
}

void MainWindow::quitWindow(void) {
    qApp->quit();
}

void MainWindow::launchServer(void) {
    int port(this->_ui->serverPortSpinbox->value());
    int width(this->_ui->mapWidthSpinbox->value());
    int height(this->_ui->mapHeightSpinbox->value());
    int maxClients(this->_ui->maxClientsSpinbox->value());
    int delay(this->_ui->delaySpinbox->value());
    bool verbose(this->_ui->verboseRadio->isChecked());


    std::ostringstream stream;

    stream << "./zappy_server ";
    stream << "-p " << port << " -x " << width << " -y " << height << " -c " << maxClients << " -t " << delay;

    stream << " -n ";
    for (int i = 0; i < this->_ui->teamList->count(); i++) {
        stream << this->_ui->teamList->item(i)->text().toStdString() << " ";
    }

    if (verbose) {
        stream << "--verbose";
    }

    this->close();
    system(stream.str().c_str());
}

void MainWindow::launchClient(void) {
    int port(this->_ui->portSpinBox->value());
    std::string team(this->_ui->teamNameLineEdit->text().toStdString());
    std::string address(this->_ui->ipLineEdit->text().toStdString());
    bool graphic(this->_ui->graphicRadio->isChecked());

    std::ostringstream stream;
    std::ostringstream stream2;

    stream << "./zappy_ai ";
    stream << "-p " << port << " -n " << team << " -h " << address;

    this->close();

    if (graphic) {
        stream2 << "./zappy_graphic ";
        stream2 << address << " " << port << " &";
        system(stream2.str().c_str());
    }

    system(stream.str().c_str());
}

void MainWindow::addTeamList(void) {
    std::string team(this->_ui->teamLineEdit->text().toStdString());

    if (!team.empty()) {
        this->_ui->teamList->addItem(new QListWidgetItem(this->_ui->teamLineEdit->text()));
        this->_ui->teamLineEdit->clear();
    } else {
        QMessageBox::warning(this, "Empty String", "Team name cannot be empty");
    }
}

void MainWindow::clearTeamList(void) {
    this->_ui->teamList->clear();
}

void MainWindow::openMan(void) {
    std::ostringstream stream;

    stream << "<b>Welcome in Zappy Manual</b><br>";
    stream << "<i>Zappy Project is project using C server application and C++ client application</i><br><br>";
    stream << "The aim is to create a game <b>hosted in the server and playable by all clients</b><br>";
    stream << "Every each specific clients is represented by an <b>IA</b> on the game<br>";
    stream << "You can also, if you choose to, launch a <b>graphic client</b> to represent game's world<br><br>";
    stream << "<i>List of server's arguments:</i>";
    stream << "<ul><li><b>Port Number</b>: Port of the connection to launch the server <i>(default: 8080)</i></li>";
    stream << "<li><b>Map Width</b>: Width of the generated world <i>(default: 100 - minimum: 10)</i></li>";
    stream << "<li><b>Map Height</b>: Height of the generated world <i>(default: 100 - minimum: 10)</i></li>";
    stream << "<li><b>Max Clients</b>: Maximum number of clients per team <i>(default: 10 - minimum: 1)</i></li>";
    stream << "<li><b>Delay time</b>: Delay time between each eaction multiply by 1/7 <i>(default: 100 - minimum: 1)</i></li>";
    stream << "<li><b>Teams name</b>: Name of playable teams chosen by clients</li></ul>";

    stream << "<i>List of clients's arguments:<i>";
    stream << "<ul><li><b>Port Machine:</b>: Port of the server's connection <i>(default: 8080)</i></li>";
    stream << "<li><b>Team Name:</b>: Name of the client's team</li>";
    stream << "<li><b>Machine Address</b>: <i>(Optionnal)</i>Address of the server's connection <i>(default: 127.0.0.1)</i></li></ul>";

    stream << "<i>Project created by Pierrick Gicquelais, Christian Boisson, Nicolas Ribeiro-Texeira, Nayden Makusa, Rodolphe Rousse, Gabriele Marsili<br>";
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
