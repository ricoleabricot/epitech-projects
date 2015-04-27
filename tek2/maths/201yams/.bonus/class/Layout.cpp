/* 
* @Author: gicque_p
* @Date:   2015-02-12 13:12:42
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-12 16:35:49
*/

#include "Layout.hpp"

Layout::Layout() : QGridLayout() {
	this->_button = new QPushButton("Message button");
	this->_button->setToolTip("Stop the programm");
	this->_button->setFont(QFont("Times New Roman"));
	this->_button->setCursor(Qt::PointingHandCursor);

	this->_button2 = new QPushButton("Input button");
	this->_button->setCursor(Qt::PointingHandCursor);
	this->_button2->setFont(QFont("Times new Roman"));

	this->_button3 = new QPushButton("End Button");
	this->_button->setCursor(Qt::PointingHandCursor);
	this->_button3->setFont(QFont("Times new Roman"));

	this->_slider = new QSlider(Qt::Horizontal);
	this->_slider->setGeometry(10, 60, 150, 20);

	this->_number = new QLCDNumber();
	this->_number->setSegmentStyle(QLCDNumber::Flat);

	this->_bar = new QProgressBar();
	this->_bar->setGeometry(10, 60, 150, 20);

	this->addWidget(this->_button, 0, 0);
	this->addWidget(this->_button2, 0, 1);
	this->addWidget(this->_button3, 1, 0, 1, 2);

	this->addWidget(this->_slider, 2, 0);
	this->addWidget(this->_bar, 3, 0);
	this->addWidget(this->_number, 2, 1);
}

Layout::~Layout() {
	delete this->_button;
	delete this->_button2;
	delete this->_button3;

	delete this->_slider;
	delete this->_bar;
	delete this->_number;
}

QPushButton *Layout::getButton(void) const {
	return this->_button;
}

QPushButton *Layout::getButton2(void) const {
	return this->_button2;
}

QPushButton *Layout::getButton3(void) const {
	return this->_button3;
}

QSlider *Layout::getSlider(void) const {
	return this->_slider;
}

QProgressBar *Layout::getBar(void) const {
	return this->_bar;
}

QLCDNumber *Layout::getNumber(void) const {
	return this->_number;
}