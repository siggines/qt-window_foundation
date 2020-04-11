#include "MainWindow.h"

#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextStream>
#include <QFile>
#include <QFileDevice>
#include <QInputDialog>
#include <QString>
#include <QLineEdit>
#include <QDir>

MainWindow::MainWindow(QWidget * parent)
	: QMainWindow(parent)
{
	// == WINDOW SETTINGS ==
	setWindowTitle("Basic Application");

	setMinimumSize(800, 450);

	// == MENU BAR ==
	QMenuBar * menuBar = new QMenuBar(this);
	setMenuBar(menuBar);

	// -- File menu --
	QMenu * menu = menuBar->addMenu("&File");

	// New
	QAction * action = new QAction("&New", this);
	connect(action, &QAction::triggered, this, &MainWindow::OnFileNew);
	menu->addAction(action);

	// Open
	action = new QAction("&Open", this);
	connect(action, &QAction::triggered, this, &MainWindow::OnFileOpen);
	menu->addAction(action);

	// Save
	action = new QAction("&Save", this);
	connect(action, &QAction::triggered, this, &MainWindow::OnFileSave);
	menu->addAction(action);

	// separator
	menu->addSeparator();

	// Exit
	action = new QAction("&Exit", this);
	connect(action, &QAction::triggered, this, &MainWindow::close);
	menu->addAction(action);

	// == STATUS BAR ==
	QStatusBar * statusBar = new QStatusBar(this);
	setStatusBar(statusBar);

	bool search;
    QString text = QInputDialog::getText(this,tr("QInputDialog::getText()"),tr("Search: "),QLineEdit::Normal,QDir::home().dirName(),&search);
	if(search){
    		QFile file0("/home/jacob/text");
            file0.open(QFile::WriteOnly | QFile::Truncate);
            QTextStream out(&file0);
            out << text;

    }


}

// == PRIVATE SLOTS ==
void MainWindow::OnFileNew()
{
	statusBar()->showMessage("File -> New");
}

void MainWindow::OnFileOpen()
{
	statusBar()->showMessage("File -> Open");
}

void MainWindow::OnFileSave()
{
	statusBar()->showMessage("File -> Save");
}
