/* 
* @Author: gicque_p
* @Date:   2015-02-12 15:52:13
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-12 16:45:55
*/

#include "Tab.hpp"

Tab::Tab(Window *window) : QTabWidget(window) {
	this->setGeometry(30, 20, 300, 150);

	this->_firstLayout = new Layout;
	this->_secondLayout = new Layout;
	this->_thirdLayout = new Layout;

	QWidget *firstPage = new QWidget;
	QWidget *secondPage = new QWidget;
	QWidget *thirdPage = new QWidget;

	firstPage->setLayout(this->_firstLayout);
	secondPage->setLayout(this->_secondLayout);
	thirdPage->setLayout(this->_thirdLayout);

	this->addTab(firstPage, "Player VS Cpu");
	this->addTab(secondPage, "Player VS Player");
	this->addTab(thirdPage, "Options");
}

Tab::~Tab() {
	delete this->_firstLayout;
	delete this->_secondLayout;
	delete this->_thirdLayout;
}
