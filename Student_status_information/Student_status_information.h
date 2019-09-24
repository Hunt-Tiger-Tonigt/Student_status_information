#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Student_status_information.h"
#include<qpushbutton.h>

class Student_status_information : public QMainWindow
{
	Q_OBJECT

public:
	Student_status_information(QWidget *parent = Q_NULLPTR);
	QPushButton a1;
	QPushButton a2;
	QPushButton a3;
	QPushButton a4;

private:
	Ui::Student_status_informationClass ui;
};
