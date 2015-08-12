/* 
* @Author: gicque_p
* @Date:   2015-06-23 22:06:16
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-06-24 10:43:11
*/

#include <iostream>

#include <QApplication>
#include <QDesktopWidget>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "MainWindow.hpp"

QCoreApplication* createApplication(int &argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        if (!qstrcmp(argv[i], "-no-gui")) {
            return new QCoreApplication(argc, argv);
        }
    }

    return new QApplication(argc, argv);
}

int main(int argc, char **argv) {
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

    if (qobject_cast<QApplication *>(app.data())) {
        QString locale = QLocale::system().name().section('_', 0, 0);
        QTranslator translator;

        translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
        app->installTranslator(&translator);    

        MainWindow window(NULL);

        window.move(QApplication::desktop()->screen()->rect().center() - window.rect().center());
        window.show();

        return app->exec();
    } else {
        return -1;
    }
}
