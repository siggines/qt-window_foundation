#include "mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("test");
    setMinimumSize(800,450);

    //menu bar
    QMenuBar * menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu * menu = menuBar->addMenu("&File"); // alt-f

    QAction * action = new QAction("&Exit",this);
    connect(action,&QAction::triggered,this,&MainWindow::close);
    menu->addAction(action);

    //menu acitons requiring special build:
    /*
    QAction * action = new QAction("&New",this);
    connect(action,&QAction::triggered,this,&MainWindow::OnFileNew);
    menu->addAction(action);

    action = new QAction("&Open",this);
    connect(action,&QAction::triggered,this,&MainWindow::OnFileOpen);
    menu->addAction(action);
    */

    QStatusBar * statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    menu->addSeparator();

}


MainWindow::~MainWindow()
{
}

