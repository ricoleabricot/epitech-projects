#ifndef WINDOW_HPP_
# define WINDOW_HPP_

# include <QApplication>
# include <QObject>
# include <QWidget>
# include <QMessageBox>
# include <QInputDialog>
# include <QPushButton>
# include <QSlider>
# include <QLCDNumber>
# include <QProgressBar>
# include <QGridLayout>

# include "Tab.hpp"

class Window : public QWidget {
	Q_OBJECT

 protected:
	Tab *_tab;

 public:
	Window();
	~Window();

 public slots:
	void setWidth(int);
	void dialog(void);
	void input(void);

 signals:
	void widthMax(void);
};

#endif /* !WINDOW_HPP_ */
