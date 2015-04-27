CONFIG			+=	qt
QT				+=	core gui

greaterThan(QT_MAJOR_VERSION, 4):
QT 				+=	widgets

TARGET			=	plazza
TEMPLATE		=	app

SOURCES			+=	source/main.cpp
SOURCES			+=	class/Reception.cpp
SOURCES			+=	class/Kitchen.cpp
SOURCES			+=	class/Pizza.cpp
SOURCES			+=	class/Process.cpp
SOURCES			+=	class/Thread.cpp
SOURCES			+=	class/Mutex.cpp
SOURCES			+=	class/ScopedLock.cpp
SOURCES			+=	class/CondVar.cpp
SOURCES			+=	class/NamedPipe.cpp
SOURCES			+=	class/PipeData.cpp
SOURCES			+=	class/Stock.cpp
SOURCES			+=	class/Parsing.cpp
SOURCES			+=	class/Log.cpp
SOURCES			+=	class/Misc.cpp
SOURCES			+=	class/Error.cpp
SOURCES			+=	class/Cook.cpp

SOURCES			+=	class/MainWindow.cpp
HEADERS			+=	header/MainWindow.hpp

HEADERS			+=	header/Reception.hpp
HEADERS			+=	header/Kitchen.hpp
HEADERS			+=	header/Pizza.hpp
HEADERS			+=	header/Process.hpp
HEADERS			+=	header/Thread.hpp
HEADERS			+=	header/Mutex.hpp
HEADERS			+=	header/ScopedLock.hpp
HEADERS			+=	header/CondVar.hpp
HEADERS 		+=	header/NamedPipe.hpp
HEADERS 		+=	header/PipeData.hpp
HEADERS			+=	header/Stock.hpp
HEADERS			+=	header/Parsing.hpp
HEADERS			+=	header/Log.hpp
HEADERS			+=	header/Misc.hpp
HEADERS			+=	header/Error.hpp
HEADERS			+=	header/Cook.hpp

QMAKE_CXXFLAGS	+=	-Wno-unused-result -lpthread -I header/

FORMS			+=	form/mainwindow.ui
UI_HEADERS_DIR	=	header/
MOC_DIR			=	class/
