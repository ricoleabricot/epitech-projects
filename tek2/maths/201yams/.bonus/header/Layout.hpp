#ifndef LAYOUT_HPP_
# define LAYOUT_HPP_

# include <QObject>
# include <QWidget>
# include <QPushButton>
# include <QSlider>
# include <QLCDNumber>
# include <QProgressBar>
# include <QGridLayout>

class Tab;

class Layout : public QGridLayout {
 protected:
	QPushButton *_button;
	QPushButton *_button2;
	QPushButton *_button3;

	QSlider *_slider;
	QLCDNumber *_number;
	QProgressBar *_bar;

 public:
 	Layout();
	~Layout();

	QPushButton *getButton(void) const;
	QPushButton *getButton2(void) const;
	QPushButton *getButton3(void) const;
	QSlider *getSlider(void) const;
	QLCDNumber *getNumber(void) const;
	QProgressBar *getBar(void) const;
};

# include "Tab.hpp"

#endif /* !LAYOUT_HPP_ */
