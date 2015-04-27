#ifndef TAB_HPP_
# define TAB_HPP_

# include <QObject>
# include <QWidget>
# include <QTabWidget>

# include "Layout.hpp"

class Window;
// class Layout;

class Tab : public QTabWidget {

 public:
	Layout *_firstLayout;
	Layout *_secondLayout;
	Layout *_thirdLayout;

 public:
	Tab(Window *);
	~Tab();
};

# include "Window.hpp"

#endif /* !TAB_HPP_ */
