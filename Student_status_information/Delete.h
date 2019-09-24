#pragma once

#include <QWidget>
#include "ui_Delete.h"

class Delete : public QWidget
{
	Q_OBJECT

public:
	Delete(QWidget *parent = Q_NULLPTR);
	~Delete();

private:
	Ui::Delete ui;
};
