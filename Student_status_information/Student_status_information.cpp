#include "Student_status_information.h"
#include <qlabel.h>
#include <qpixmap.h>
#include <qdialog.h>
#include <qmessagebox.h>
#include <resource.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Input.h"
#include "Inquire.h"
#include "Delete.h"
#include "modify.h"

#define N 80

using namespace std;

Student_status_information::Student_status_information(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//设置窗口图标
	QIcon icon("C:/Users/wyc/source/repos/Student_status_information/Icon/icon1.ico");
	setWindowIcon(icon);

	//显示开发者信息
	QMessageBox messagebox;
	messagebox.information(NULL, QStringLiteral("开发者信息"), QStringLiteral("   开发者：王艺宸   \n\n   版本号：1.0.0   \n\n   维护时间：2019年9月17日   \n\n   联系方式：18398621916   \n"));
	messagebox.show();

	//设置背景图片
	QLabel* mLabel = new QLabel(this);
	QPixmap photo;
	photo.load("C:/Users/wyc/source/repos/Student_status_information/Student_status_information/wyc.jpg");
	mLabel->setPixmap(photo);
	mLabel->setGeometry(QRect(0, 0, 800, 600));
	mLabel->setScaledContents(true);

	//顶部显示文本：学籍信息管理系统
	QLabel *pQlabel = new QLabel(this);
	pQlabel->setText(QStringLiteral("学籍信息管理系统"));
	pQlabel->setStyleSheet("color:rgb(227,23,13);font-size:75px;font:bold 75px");
	pQlabel->setAlignment(Qt::AlignCenter);
	pQlabel->setGeometry(QRect(80, 50, 640, 100));

	//设置按钮1：查询
	a1.setText(QStringLiteral("学籍信息查询"));
	a1.setParent(this);
	a1.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }"
	);
	a1.resize(300, 100);
	a1.move(50, 200);

	//设置按钮2：录入
	a2.setText(QStringLiteral("学籍信息录入"));
	a2.setParent(this);
	a2.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }"
	);
	a2.resize(300, 100);
	a2.move(450, 200);

	//设置按钮3：修改
	a3.setText(QStringLiteral("学籍信息修改"));
	a3.setParent(this);
	a3.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }"
	);
	a3.resize(300, 100);
	a3.move(50, 400);

	//设置按钮4：删除
	a4.setText(QStringLiteral("学籍信息删除"));
	a4.setParent(this);
	a4.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }"
	);
	a4.resize(300, 100);
	a4.move(450, 400);

	//按钮信号处理
	connect(&a1, &QPushButton::clicked, this, &Student_status_information::cw2inquire);
	connect(&a2, &QPushButton::clicked, this, &Student_status_information::cw2input);
	connect(&a3, &QPushButton::pressed, this, &Student_status_information::cw2modify);
	connect(&a3, &QPushButton::clicked, this, &Student_status_information::cw22modify);
	connect(&a4, &QPushButton::clicked, this, &Student_status_information::cw2delete);

	connect(&i, &Inquire::mysignal, this, &Student_status_information::dealinquire);
	connect(&p, &Input::psignal, this, &Student_status_information::dealinput);
	connect(&m, &modify::mmysignal, this, &Student_status_information::dealmodify);
	connect(&d, &Delete::dmysignal, this, &Student_status_information::dealdelete);
}

void Student_status_information::cw2inquire()
{
	i.show();
	this->hide();
}

void Student_status_information::cw2input()
{
	p.show();
	this->hide();
}

void Student_status_information::cw2modify()
{
	m.show();
	this->hide();
}

void Student_status_information::cw22modify()
{
	//显示开发者信息
	QMessageBox messagebox;
	messagebox.information(NULL, QStringLiteral("请输入修改项"), QStringLiteral("  1：修改姓名  \n  2：修改性别  \n  3：修改学号  \n  4：修改宿舍号  \n  5：修改联系方式  "));
	messagebox.show();
}

void Student_status_information::cw2delete()
{
	d.show();
	this->hide();
}

void Student_status_information::dealinquire()
{
	i.hide();
	this->show();
}

void Student_status_information::dealinput()
{
	p.hide();
	this->show();
}

void Student_status_information::dealdelete()
{
	d.hide();
	this->show();
}

void Student_status_information::dealmodify()
{
	m.hide();
	this->show();
}
