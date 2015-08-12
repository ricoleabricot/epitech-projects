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

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT;

 private:
	Ui::MainWindow *_ui;

 public:
	explicit MainWindow(QWidget *parent);
	~MainWindow(void);

 public slots:
	void quitWindow(void);

	void launchServer(void);
	void launchClient(void);

	void addTeamList(void);
	void clearTeamList(void);

	void openMan(void);
	void openQt(void);
};

#endif /* MAINWINDOW_HPP_ */
