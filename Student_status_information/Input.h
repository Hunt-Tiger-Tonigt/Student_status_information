#pragma once

#include <QWidget>
#include "ui_Input.h"
#include <qpushbutton.h>
#include <qtextedit.h>

using namespace std;

class Input : public QWidget
{
	Q_OBJECT

public:
	Input(QWidget *parent = Q_NULLPTR);
	~Input();

	QPushButton pa1;
	QPushButton pa2;


	void back();
	void save2txt();
	
signals:
	void psignal();

private:
	Ui::Input ui;
	QLineEdit *nameinput;
	QLineEdit *genderinput;
	QLineEdit *IDinput;
	QLineEdit *dormitoryinput;
	QLineEdit *numberinput;
};



