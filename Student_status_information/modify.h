#pragma once

#include <QWidget>
#include "ui_modify.h"

class modify : public QWidget
{
	Q_OBJECT

public:
	modify(QWidget *parent = Q_NULLPTR);
	~modify();

private:
	Ui::modify ui;
};
