#pragma once

#include <QWidget>
#include "ui_Inquire.h"
#include "ui_Student_status_information.h"
#include <qpushbutton.h>

class Inquire : public QWidget
{
	Q_OBJECT

public:
	Inquire(QWidget *parent = Q_NULLPTR);
	~Inquire();

	QPushButton ia1;
	QPushButton ia2;

	void iback();
	void ifind();

signals:
	void mysignal();

private:
	Ui::Inquire ui;

	QLineEdit* nameinquire;
};
