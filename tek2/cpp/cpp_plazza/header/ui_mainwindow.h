/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *actionNew_command;
    QAction *actionOpenMan;
    QAction *actionOpenLog;
    QAction *actionAchievment;
    QAction *actionOpenQt;
    QWidget *centralWidget;
    QFrame *line;
    QFrame *line2;
    QFrame *line3;
    QWidget *gridLayoutWidget;
    QGridLayout *newOrderLayout;
    QComboBox *boxPizzaType;
    QComboBox *boxPizzaSize;
    QLCDNumber *pizzaNumber;
    QLabel *numberOfPizzas;
    QLabel *pizzaSize;
    QLabel *pizzaType;
    QSlider *sliderPizzaNumber;
    QLabel *oldSchool;
    QPushButton *buttonOrder;
    QLabel *newOrder;
    QLineEdit *linePizzaOrder;
    QWidget *gridLayoutWidget_2;
    QGridLayout *stockLayout;
    QLabel *stockOfIngredients;
    QTableWidget *tableStock;
    QWidget *gridLayoutWidget_3;
    QGridLayout *ordersLayout;
    QLabel *awaitingPizzas;
    QLabel *finishedPizzas;
    QLabel *processingPizzas;
    QTableWidget *tableWaiting;
    QTableWidget *tableProcessing;
    QTableWidget *tableFinished;
    QWidget *gridLayoutWidget_4;
    QGridLayout *kitchensLayout;
    QLabel *kitchenList;
    QListWidget *tableKitchen;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *infoLayout;
    QLabel *labelWallet;
    QProgressBar *barAchievment;
    QLabel *labelInfos;
    QMenuBar *menuPlazza;
    QMenu *menuMainWindow;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1049, 725);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionNew_command = new QAction(MainWindow);
        actionNew_command->setObjectName(QString::fromUtf8("actionNew_command"));
        actionOpenMan = new QAction(MainWindow);
        actionOpenMan->setObjectName(QString::fromUtf8("actionOpenMan"));
        actionOpenMan->setEnabled(true);
        actionOpenMan->setVisible(true);
        actionOpenLog = new QAction(MainWindow);
        actionOpenLog->setObjectName(QString::fromUtf8("actionOpenLog"));
        actionAchievment = new QAction(MainWindow);
        actionAchievment->setObjectName(QString::fromUtf8("actionAchievment"));
        actionAchievment->setEnabled(false);
        actionOpenQt = new QAction(MainWindow);
        actionOpenQt->setObjectName(QString::fromUtf8("actionOpenQt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(230, 20, 20, 641));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line2 = new QFrame(centralWidget);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setGeometry(QRect(250, 260, 791, 21));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);
        line3 = new QFrame(centralWidget);
        line3->setObjectName(QString::fromUtf8("line3"));
        line3->setGeometry(QRect(640, 30, 20, 231));
        line3->setFrameShape(QFrame::VLine);
        line3->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(660, 20, 381, 231));
        newOrderLayout = new QGridLayout(gridLayoutWidget);
        newOrderLayout->setSpacing(6);
        newOrderLayout->setContentsMargins(11, 11, 11, 11);
        newOrderLayout->setObjectName(QString::fromUtf8("newOrderLayout"));
        newOrderLayout->setContentsMargins(0, 0, 0, 0);
        boxPizzaType = new QComboBox(gridLayoutWidget);
        boxPizzaType->setObjectName(QString::fromUtf8("boxPizzaType"));

        newOrderLayout->addWidget(boxPizzaType, 2, 0, 1, 1);

        boxPizzaSize = new QComboBox(gridLayoutWidget);
        boxPizzaSize->setObjectName(QString::fromUtf8("boxPizzaSize"));

        newOrderLayout->addWidget(boxPizzaSize, 3, 0, 1, 1);

        pizzaNumber = new QLCDNumber(gridLayoutWidget);
        pizzaNumber->setObjectName(QString::fromUtf8("pizzaNumber"));
        pizzaNumber->setSmallDecimalPoint(false);
        pizzaNumber->setProperty("intValue", QVariant(1));

        newOrderLayout->addWidget(pizzaNumber, 4, 1, 1, 1);

        numberOfPizzas = new QLabel(gridLayoutWidget);
        numberOfPizzas->setObjectName(QString::fromUtf8("numberOfPizzas"));

        newOrderLayout->addWidget(numberOfPizzas, 4, 2, 1, 1);

        pizzaSize = new QLabel(gridLayoutWidget);
        pizzaSize->setObjectName(QString::fromUtf8("pizzaSize"));

        newOrderLayout->addWidget(pizzaSize, 3, 2, 1, 1);

        pizzaType = new QLabel(gridLayoutWidget);
        pizzaType->setObjectName(QString::fromUtf8("pizzaType"));

        newOrderLayout->addWidget(pizzaType, 2, 2, 1, 1);

        sliderPizzaNumber = new QSlider(gridLayoutWidget);
        sliderPizzaNumber->setObjectName(QString::fromUtf8("sliderPizzaNumber"));
        sliderPizzaNumber->setMinimum(1);
        sliderPizzaNumber->setOrientation(Qt::Horizontal);

        newOrderLayout->addWidget(sliderPizzaNumber, 4, 0, 1, 1);

        oldSchool = new QLabel(gridLayoutWidget);
        oldSchool->setObjectName(QString::fromUtf8("oldSchool"));

        newOrderLayout->addWidget(oldSchool, 7, 0, 1, 1);

        buttonOrder = new QPushButton(gridLayoutWidget);
        buttonOrder->setObjectName(QString::fromUtf8("buttonOrder"));

        newOrderLayout->addWidget(buttonOrder, 6, 0, 1, 1);

        newOrder = new QLabel(gridLayoutWidget);
        newOrder->setObjectName(QString::fromUtf8("newOrder"));

        newOrderLayout->addWidget(newOrder, 1, 0, 1, 1);

        linePizzaOrder = new QLineEdit(gridLayoutWidget);
        linePizzaOrder->setObjectName(QString::fromUtf8("linePizzaOrder"));

        newOrderLayout->addWidget(linePizzaOrder, 8, 0, 1, 3);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(260, 20, 371, 231));
        stockLayout = new QGridLayout(gridLayoutWidget_2);
        stockLayout->setSpacing(6);
        stockLayout->setContentsMargins(11, 11, 11, 11);
        stockLayout->setObjectName(QString::fromUtf8("stockLayout"));
        stockLayout->setContentsMargins(0, 0, 0, 0);
        stockOfIngredients = new QLabel(gridLayoutWidget_2);
        stockOfIngredients->setObjectName(QString::fromUtf8("stockOfIngredients"));

        stockLayout->addWidget(stockOfIngredients, 0, 0, 1, 1);

        tableStock = new QTableWidget(gridLayoutWidget_2);
        if (tableStock->columnCount() < 2)
            tableStock->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableStock->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableStock->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableStock->setObjectName(QString::fromUtf8("tableStock"));
        tableStock->setEnabled(true);
        tableStock->setMinimumSize(QSize(369, 206));
        tableStock->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableStock->horizontalHeader()->setDefaultSectionSize(220);
        tableStock->horizontalHeader()->setMinimumSectionSize(100);
        tableStock->horizontalHeader()->setStretchLastSection(true);

        stockLayout->addWidget(tableStock, 1, 0, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(250, 280, 791, 381));
        ordersLayout = new QGridLayout(gridLayoutWidget_3);
        ordersLayout->setSpacing(6);
        ordersLayout->setContentsMargins(11, 11, 11, 11);
        ordersLayout->setObjectName(QString::fromUtf8("ordersLayout"));
        ordersLayout->setContentsMargins(0, 0, 0, 0);
        awaitingPizzas = new QLabel(gridLayoutWidget_3);
        awaitingPizzas->setObjectName(QString::fromUtf8("awaitingPizzas"));

        ordersLayout->addWidget(awaitingPizzas, 0, 0, 1, 1);

        finishedPizzas = new QLabel(gridLayoutWidget_3);
        finishedPizzas->setObjectName(QString::fromUtf8("finishedPizzas"));

        ordersLayout->addWidget(finishedPizzas, 0, 2, 1, 1);

        processingPizzas = new QLabel(gridLayoutWidget_3);
        processingPizzas->setObjectName(QString::fromUtf8("processingPizzas"));

        ordersLayout->addWidget(processingPizzas, 0, 1, 1, 1);

        tableWaiting = new QTableWidget(gridLayoutWidget_3);
        if (tableWaiting->columnCount() < 2)
            tableWaiting->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWaiting->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWaiting->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWaiting->setObjectName(QString::fromUtf8("tableWaiting"));
        tableWaiting->setEnabled(true);
        tableWaiting->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWaiting->horizontalHeader()->setDefaultSectionSize(150);
        tableWaiting->horizontalHeader()->setStretchLastSection(true);

        ordersLayout->addWidget(tableWaiting, 3, 0, 1, 1);

        tableProcessing = new QTableWidget(gridLayoutWidget_3);
        if (tableProcessing->columnCount() < 2)
            tableProcessing->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableProcessing->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableProcessing->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        tableProcessing->setObjectName(QString::fromUtf8("tableProcessing"));
        tableProcessing->setEnabled(true);
        tableProcessing->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableProcessing->horizontalHeader()->setDefaultSectionSize(150);
        tableProcessing->horizontalHeader()->setStretchLastSection(true);

        ordersLayout->addWidget(tableProcessing, 3, 1, 1, 1);

        tableFinished = new QTableWidget(gridLayoutWidget_3);
        if (tableFinished->columnCount() < 2)
            tableFinished->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableFinished->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableFinished->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        tableFinished->setObjectName(QString::fromUtf8("tableFinished"));
        tableFinished->setEnabled(true);
        tableFinished->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableFinished->horizontalHeader()->setDefaultSectionSize(150);
        tableFinished->horizontalHeader()->setStretchLastSection(true);

        ordersLayout->addWidget(tableFinished, 3, 2, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 221, 641));
        kitchensLayout = new QGridLayout(gridLayoutWidget_4);
        kitchensLayout->setSpacing(6);
        kitchensLayout->setContentsMargins(11, 11, 11, 11);
        kitchensLayout->setObjectName(QString::fromUtf8("kitchensLayout"));
        kitchensLayout->setContentsMargins(0, 0, 0, 0);
        kitchenList = new QLabel(gridLayoutWidget_4);
        kitchenList->setObjectName(QString::fromUtf8("kitchenList"));

        kitchensLayout->addWidget(kitchenList, 0, 0, 1, 1);

        tableKitchen = new QListWidget(gridLayoutWidget_4);
        tableKitchen->setObjectName(QString::fromUtf8("tableKitchen"));

        kitchensLayout->addWidget(tableKitchen, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 670, 1031, 27));
        infoLayout = new QHBoxLayout(horizontalLayoutWidget);
        infoLayout->setSpacing(6);
        infoLayout->setContentsMargins(11, 11, 11, 11);
        infoLayout->setObjectName(QString::fromUtf8("infoLayout"));
        infoLayout->setContentsMargins(0, 0, 0, 0);
        labelWallet = new QLabel(horizontalLayoutWidget);
        labelWallet->setObjectName(QString::fromUtf8("labelWallet"));
        labelWallet->setMaximumSize(QSize(200, 100));

        infoLayout->addWidget(labelWallet);

        barAchievment = new QProgressBar(horizontalLayoutWidget);
        barAchievment->setObjectName(QString::fromUtf8("barAchievment"));
        barAchievment->setMaximumSize(QSize(200, 100));
        barAchievment->setValue(1);

        infoLayout->addWidget(barAchievment);

        labelInfos = new QLabel(horizontalLayoutWidget);
        labelInfos->setObjectName(QString::fromUtf8("labelInfos"));

        infoLayout->addWidget(labelInfos);

        MainWindow->setCentralWidget(centralWidget);
        menuPlazza = new QMenuBar(MainWindow);
        menuPlazza->setObjectName(QString::fromUtf8("menuPlazza"));
        menuPlazza->setGeometry(QRect(0, 0, 1049, 25));
        menuMainWindow = new QMenu(menuPlazza);
        menuMainWindow->setObjectName(QString::fromUtf8("menuMainWindow"));
        menuHelp = new QMenu(menuPlazza);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuPlazza);

        menuPlazza->addAction(menuHelp->menuAction());
        menuPlazza->addAction(menuMainWindow->menuAction());
        menuMainWindow->addAction(actionAchievment);
        menuMainWindow->addSeparator();
        menuMainWindow->addAction(actionQuit);
        menuHelp->addAction(actionOpenMan);
        menuHelp->addAction(actionOpenQt);
        menuHelp->addAction(actionOpenLog);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Plazza", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Esc", 0, QApplication::UnicodeUTF8));
        actionNew_command->setText(QApplication::translate("MainWindow", "New command", 0, QApplication::UnicodeUTF8));
        actionOpenMan->setText(QApplication::translate("MainWindow", "About Plazza", 0, QApplication::UnicodeUTF8));
        actionOpenMan->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionOpenLog->setText(QApplication::translate("MainWindow", "Open Logs", 0, QApplication::UnicodeUTF8));
        actionOpenLog->setShortcut(QApplication::translate("MainWindow", "F3", 0, QApplication::UnicodeUTF8));
        actionAchievment->setText(QApplication::translate("MainWindow", "Reach $1.000.000 to unlock", 0, QApplication::UnicodeUTF8));
        actionOpenQt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionOpenQt->setShortcut(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        boxPizzaType->clear();
        boxPizzaType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Regina", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Margarita", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Americana", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fantasia", 0, QApplication::UnicodeUTF8)
        );
        boxPizzaSize->clear();
        boxPizzaSize->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "M", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "XL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "XXL", 0, QApplication::UnicodeUTF8)
        );
        numberOfPizzas->setText(QApplication::translate("MainWindow", "Number of Pizzas", 0, QApplication::UnicodeUTF8));
        pizzaSize->setText(QApplication::translate("MainWindow", "Pizza Size", 0, QApplication::UnicodeUTF8));
        pizzaType->setText(QApplication::translate("MainWindow", "Pizza Type", 0, QApplication::UnicodeUTF8));
        oldSchool->setText(QApplication::translate("MainWindow", "Old School Command Line:", 0, QApplication::UnicodeUTF8));
        buttonOrder->setText(QApplication::translate("MainWindow", "CHIEF, MY ORDER !", 0, QApplication::UnicodeUTF8));
        newOrder->setText(QApplication::translate("MainWindow", "New Order:", 0, QApplication::UnicodeUTF8));
        stockOfIngredients->setText(QApplication::translate("MainWindow", "Stock of Ingredients: ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableStock->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Ingredient", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableStock->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Stock", 0, QApplication::UnicodeUTF8));
        awaitingPizzas->setText(QApplication::translate("MainWindow", "Awaiting pizzas:", 0, QApplication::UnicodeUTF8));
        finishedPizzas->setText(QApplication::translate("MainWindow", "Finished pizzas :", 0, QApplication::UnicodeUTF8));
        processingPizzas->setText(QApplication::translate("MainWindow", "Processing pizzas :", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWaiting->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWaiting->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableProcessing->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableProcessing->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableFinished->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableFinished->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        kitchenList->setText(QApplication::translate("MainWindow", "Kitchen List: ", 0, QApplication::UnicodeUTF8));
        labelWallet->setText(QApplication::translate("MainWindow", "Your wallet: $10.000", 0, QApplication::UnicodeUTF8));
        labelInfos->setText(QApplication::translate("MainWindow", "Last informations: ", 0, QApplication::UnicodeUTF8));
        menuMainWindow->setTitle(QApplication::translate("MainWindow", "Plazza", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
