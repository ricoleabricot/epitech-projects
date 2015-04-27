#ifndef MAINWINDOW_HPP_
# define MAINWINDOW_HPP_

# include <iostream>
# include <sstream>
# include <QMainWindow>
# include <QDialogButtonBox>
# include <QMessageBox>
# include <QTimer>
# include <QTime>

# include "ui_mainwindow.h"

# include "Reception.hpp"
# include "Error.hpp"

namespace Ui {
	class MainWindow;
}

class Reception;

class MainWindow : public QMainWindow {
	Q_OBJECT;

 private:
	Ui::MainWindow *_ui;
	Reception *_reception;

 public:
	explicit MainWindow(QWidget *parent, Reception *reception);
	~MainWindow(void);

	void refreshList(void);
	void refreshWallet(void);
	void refreshStock(void);
	void refreshPizzas(void);

 public slots:
	void quitWindow(void);
	void switchItem(QListWidgetItem *, QListWidgetItem *);

	void getOrderFromForm(void);
	void getOrderFromLine(void);

	void refresh(void);
	void newDay(void);

	void openMan(void);
	void openQt(void);
	void openLog(void);
	void openAchievment(void);
  void	pipes(void);
};

#endif /* MAINWINDOW_HPP_ */
