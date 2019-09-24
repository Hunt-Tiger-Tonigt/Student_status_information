#include "Inquire.h"

Inquire::Inquire(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(QStringLiteral("学籍信息查询"));

	ia1.setText(QStringLiteral("学籍信息查询"));
	ia1.setParent(this);

	connect(&ia1, &QPushButton::clicked, this, &Inquire::back);

}

Inquire::~Inquire()
{
}

void Inquire::back()
{
	emit mysignal();
}
