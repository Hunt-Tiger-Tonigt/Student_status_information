#pragma once

#include <QWidget>
#include "ui_modify.h"
#include <qpushbutton.h>

class modify : public QWidget
{
	Q_OBJECT

public:
	modify(QWidget *parent = Q_NULLPTR);
	~modify();

	QPushButton ma1;
	QPushButton ma2;

	void mback();
	void mfind();

signals:
	void mmysignal();

private:
	Ui::modify ui;

	QLineEdit* modifyinquire;
	QLineEdit* numberinquire;
	QLineEdit* modifyinf;
};
