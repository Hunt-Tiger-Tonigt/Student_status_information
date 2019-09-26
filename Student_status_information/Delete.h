#pragma once

#include <QWidget>
#include "ui_Delete.h"
#include <qpushbutton.h>

class Delete : public QWidget
{
	Q_OBJECT

public:
	Delete(QWidget *parent = Q_NULLPTR);
	~Delete();

	QPushButton da1;
	QPushButton da2;

	void dback();
	void dfind();

signals:
	void dmysignal();

private:
	Ui::Delete ui;

	QLineEdit* delateinquire;
};
