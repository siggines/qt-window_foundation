#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget * parent = nullptr);

private slots:
	void OnFileNew();
	void OnFileOpen();
	void OnFileSave();
};
