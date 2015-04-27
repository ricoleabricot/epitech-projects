/* 
* @Author: gicque_p
* @Date:   2015-02-08 15:19:12
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-10 17:33:36
*/

#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include "Window.hpp"

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	QString locale = QLocale::system().name().section('_', 0, 0);
	QTranslator translator;
	Window window;
	
	translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	app.installTranslator(&translator);

	window.show();
	
	return app.exec();
}
