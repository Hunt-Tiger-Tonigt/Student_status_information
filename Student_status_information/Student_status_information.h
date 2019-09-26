#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Student_status_information.h"
#include <qpushbutton.h>
#include <resource.h>

#include "Inquire.h"
#include "Input.h"
#include "modify.h"
#include "Delete.h"

class Student_status_information : public QMainWindow
{
	Q_OBJECT

public:
	Student_status_information(QWidget *parent = Q_NULLPTR);
	
	QPushButton a1;
	QPushButton a2;
	QPushButton a3;
	QPushButton a4;

	void cw2inquire();
	void cw2input();
	void cw2modify();
	void cw2delete();

	void dealinquire();
	void deal2inquire();
	void dealinput();

private:
	Ui::Student_status_informationClass ui;
	
	Inquire i;
	Input p;
	modify m;
	Delete d;
	
};
