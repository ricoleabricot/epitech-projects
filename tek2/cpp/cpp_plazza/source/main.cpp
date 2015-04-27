/* 
* @Author: gicque_p
* @Date:   2015-04-14 10:59:05
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-04-22 14:20:07
*/

#include <iostream>

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "MainWindow.hpp"
#include "Reception.hpp"
#include "Misc.hpp"
#include "Error.hpp"

QCoreApplication* createApplication(int &argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		if (!qstrcmp(argv[i], "-no-gui")) {
			return new QCoreApplication(argc, argv);
		}
	}

	return new QApplication(argc, argv);
}

int main(int argc, char **argv) {
	if (argc != 4) {
		Misc::usage(argv);
		return -1;
	} else {
		QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

		if (qobject_cast<QApplication *>(app.data())) {
			QString locale = QLocale::system().name().section('_', 0, 0);
			QTranslator translator;

			translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
			app->installTranslator(&translator);	

			double prepareCook(Misc::stringToNumber(argv[1]));
			int numberCook(Misc::stringToNumber(argv[2]));
			int replaceStock(Misc::stringToNumber(argv[3]));

			Reception reception(prepareCook, numberCook, replaceStock);
			try {
				reception.init();
			} catch (const Error &error) {
				std::cerr << error.where() << ": " << error.what() << std::endl;
				return -1;
			}

			MainWindow window(NULL, &reception);
			window.show();

			return app->exec();
		} else {
			return -1;
		}
	}
}