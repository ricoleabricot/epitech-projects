/* 
* @Author: gicque_p
* @Date:   2015-02-08 15:23:31
* @Last Modified by:   gicque_p
* @Last Modified time: 2015-02-12 16:46:26
*/

#include "Window.hpp"

Window::Window() : QWidget() {
	this->_tab = new Tab(this);

	// QObject::connect(this->_tab->_firstLayout->getButton(), SIGNAL(clicked()), this, SLOT(dialog()));
	// QObject::connect(this->_tab->_firstLayout->getButton2(), SIGNAL(clicked()), this, SLOT(input()));
	QObject::connect(this->_tab->_thirdLayout->getButton3(), SIGNAL(clicked()), qApp, SLOT(quit()));
	// QObject::connect(this->_tab->_firstLayout->getSlider(), SIGNAL(valueChanged(int)), this->_tab->_firstLayout->getNumber(), SLOT(display(int)));
	// QObject::connect(this->_tab->_firstLayout->getSlider(), SIGNAL(valueChanged(int)), this->_tab->_firstLayout->getBar(), SLOT(setValue(int)));
	// QObject::connect(this->_layout->getSlider(), SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));
	// QObject::connect(this, SIGNAL(widthMax()), qApp, SLOT(quit())); // Connection class to implement
}

Window::~Window() {
	delete this->_tab;
}

void Window::setWidth(int width) {
	this->setFixedSize((width * 10) + 100, 150);
	if (width == 600) {
		emit widthMax();
	}
}

void Window::dialog(void) {
	QMessageBox::information(this, "Coucou konar", "Ceci est un content", QMessageBox::Yes | QMessageBox::No);
}

void Window::input(void) {
	QString dialog = QInputDialog::getText(this, "Coucou bitch", "Entre quelque chose d'inutile");
	if (!dialog.isEmpty()) {
		QMessageBox::information(this, "Réponse", dialog);
	}
}