CONFIG			+=	qt
QT				+=	core gui

greaterThan(QT_MAJOR_VERSION, 4):
QT 				+=	widgets

TARGET			=	../zappy
TEMPLATE		=	app

SOURCES			+=	main.cpp
SOURCES			+=	MainWindow.cpp
HEADERS			+=	MainWindow.hpp

QMAKE_CXXFLAGS	+=	-Wno-unused-result

FORMS			+=	mainwindow.ui
UI_HEADERS_DIR	=	./
MOC_DIR			=	./
