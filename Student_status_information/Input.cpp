#include "Input.h"

#include <qpushbutton.h>
#include <qlabel.h>
#include <qpixmap.h>
#include <qmessagebox.h>
#include <resource.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <QtSql/qsqldatabase.h>

#include <iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

Input::Input(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//设置窗口图标
	QIcon icon("C:/Users/wyc/source/repos/wyc/Student_status_information/Icon/icon2.ico");
	setWindowIcon(icon);

	this->resize(800, 800);

	//设置背景图片
	QLabel* mLabel = new QLabel(this);
	QPixmap photo;
	photo.load("C:/Users/wyc/source/repos/wyc/Student_status_information/Student_status_information/wyc.jpg");
	mLabel->setPixmap(photo);
	mLabel->setGeometry(QRect(0, 0, 800, 800));
	mLabel->setScaledContents(true);

	//顶部显示文本：学籍信息录入
	QLabel *pQlabel = new QLabel(this);
	pQlabel->setText(QStringLiteral("学籍信息录入"));
	pQlabel->setStyleSheet("color:rgb(227,23,13);font-size:75px;font:bold 75px");
	pQlabel->setAlignment(Qt::AlignCenter);
	pQlabel->setGeometry(QRect(80, 50, 640, 100));

	//姓名输入
	nameinput = new QLineEdit(this);
	nameinput->setPlaceholderText(QStringLiteral("请输入姓名"));
	nameinput->setEchoMode(QLineEdit::Normal);
	nameinput->setAlignment(Qt::AlignLeft);
	nameinput->move(100, 200);
	nameinput->resize(600, 50);
	nameinput->setFont(QFont("Timers", 15, QFont::Bold));

	//性别输入
	genderinput = new QLineEdit(this);
	genderinput->setPlaceholderText(QStringLiteral("请输入性别"));
	genderinput->setEchoMode(QLineEdit::Normal);
	genderinput->setAlignment(Qt::AlignLeft);
	genderinput->move(100, 300);
	genderinput->resize(600, 50);
	genderinput->setFont(QFont("Timers", 15, QFont::Bold));

	//学号输入
	IDinput = new QLineEdit(this);
	IDinput->setPlaceholderText(QStringLiteral("请输入学号"));
	IDinput->setEchoMode(QLineEdit::Normal);
	IDinput->setAlignment(Qt::AlignLeft);
	IDinput->move(100, 400);
	IDinput->resize(600, 50);
	IDinput->setFont(QFont("Timers", 15, QFont::Bold));

	//宿舍号输入
	dormitoryinput = new QLineEdit(this);
	dormitoryinput->setPlaceholderText(QStringLiteral("请输入宿舍号"));
	dormitoryinput->setEchoMode(QLineEdit::Normal);
	dormitoryinput->setAlignment(Qt::AlignLeft);
	dormitoryinput->move(100, 500);
	dormitoryinput->resize(600, 50);
	dormitoryinput->setFont(QFont("Timers", 15, QFont::Bold));

	//联系方式输入
	numberinput = new QLineEdit(this);
	numberinput->setPlaceholderText(QStringLiteral("请输入联系方式"));
	numberinput->setEchoMode(QLineEdit::Normal);
	numberinput->setAlignment(Qt::AlignLeft);
	numberinput->move(100, 600);
	numberinput->resize(600, 50);
	numberinput->setFont(QFont("Timers", 15, QFont::Bold));

	//返回按钮
	pa1.setText(QStringLiteral("返回"));
	pa1.move(500, 700);
	pa1.setParent(this);
	connect(&pa1, &QPushButton::clicked, this, &Input::back);

	//上传按钮
	pa2.setText(QStringLiteral("上传"));
	pa2.move(150, 700);
	pa2.setParent(this);
	connect(&pa2, &QPushButton::pressed, this, &Input::save2txt);
}

Input::~Input()
{
}

void Input::back()
{
	emit psignal();
}

void Input::save2txt()
{
	//获取输入信息
	QString qstrname = nameinput->text();
	string strname = qstrname.toStdString();
	const char *charname = strname.c_str();

	QString qstrgender = genderinput->text();
	string strgender = qstrgender.toStdString();
	const char *chargender = strgender.c_str();

	QString qstrID = IDinput->text();
	string strID = qstrID.toStdString();
	const char *charID = strID.c_str();

	QString qstrdormitory = dormitoryinput->text();
	string strdormitory = qstrdormitory.toStdString();
	const char *chardormitory = strdormitory.c_str();

	QString qstrnumber = numberinput->text();
	string strnumber = qstrnumber.toStdString();
	const char *charnumber = strnumber.c_str();

	//检查输入信息是否为空
	if (qstrname.isEmpty())
	{
		QMessageBox message;
		message.warning(NULL, QStringLiteral("错误"), QStringLiteral("  未填写姓名！  "));
	}
	else if (qstrgender.isEmpty())
	{
		QMessageBox message;
		message.warning(NULL, QStringLiteral("错误"), QStringLiteral("  未填写性别！  "));
	}
	else if (qstrID.isEmpty())
	{
		QMessageBox message;
		message.warning(NULL, QStringLiteral("错误"), QStringLiteral("  未填写学号！  "));
	}
	else if (qstrdormitory.isEmpty())
	{
		QMessageBox message;
		message.warning(NULL, QStringLiteral("错误"), QStringLiteral("  未填写宿舍号！  "));
	}
	else if (qstrnumber.isEmpty())
	{
		QMessageBox message;
		message.warning(NULL, QStringLiteral("错误"), QStringLiteral("  未填写联系方式！  "));
	}
	else
	{
		QMessageBox messagebox;
		ofstream outFile;
		outFile.open("test.txt", ios::app | ios::binary);
		if (!outFile)
		{
			messagebox.information(NULL, QStringLiteral("警告"), QStringLiteral("上传失败！"));
			abort();
		}
		else
		{
			outFile << charname << endl;
			outFile << chargender << endl;
			outFile << charID << endl;
			outFile << chardormitory << endl;
			outFile << charnumber << endl;
			outFile.close();
			messagebox.information(NULL, QStringLiteral("SUCCESS"), QStringLiteral("上传成功！"));
		}
	}
}