#include "Delete.h"
#include <qlabel.h>
#include <qpixmap.h>
#include <qmessagebox.h>
#include <resource.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <QtSql/qsqldatabase.h>

#include<stdio.h>
#include <string.h>
#include<algorithm>
#include<cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <codecvt>
#include <stdint.h>
#include <tchar.h>
#include<iomanip>

using namespace std;

Delete::Delete(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//设置窗口图标
	QIcon icon("C:/Users/wyc/source/repos/wyc/Student_status_information/Icon/icon2.ico");
	setWindowIcon(icon);

	this->resize(800, 500);

	//设置背景图片
	QLabel* mLabel = new QLabel(this);
	QPixmap photo;
	photo.load("C:/Users/wyc/source/repos/wyc/Student_status_information/Student_status_information/wyc.jpg");
	mLabel->setPixmap(photo);
	mLabel->setGeometry(QRect(0, 0, 800, 500));
	mLabel->setScaledContents(true);

	//顶部显示文本：学籍信息录入
	QLabel *pQlabel = new QLabel(this);
	pQlabel->setText(QStringLiteral("学籍信息删除"));
	pQlabel->setStyleSheet("color:rgb(227,23,13);font-size:75px;font:bold 75px");
	pQlabel->setAlignment(Qt::AlignCenter);
	pQlabel->setGeometry(QRect(80, 50, 640, 100));

	//姓名输入
	delateinquire = new QLineEdit(this);
	delateinquire->setPlaceholderText(QStringLiteral("请输入姓名"));
	delateinquire->setEchoMode(QLineEdit::Normal);
	delateinquire->setAlignment(Qt::AlignLeft);
	delateinquire->move(100, 200);
	delateinquire->resize(600, 50);
	delateinquire->setFont(QFont("Timers", 15, QFont::Bold));

	this->setWindowTitle(QStringLiteral("学籍信息查询"));

	//返回按钮
	da1.setText(QStringLiteral("返回"));
	da1.move(500, 400);
	da1.setParent(this);
	connect(&da1, &QPushButton::clicked, this, &Delete::dback);

	//上传按钮
	da2.setText(QStringLiteral("删除"));
	da2.move(150, 400);
	da2.setParent(this);
	connect(&da2, &QPushButton::pressed, this, &Delete::dfind);
}

Delete::~Delete()
{
}

void Delete::dback()
{
	emit dmysignal();
}

string CharToStr(char * contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}


void DelLineData(int lineNum)
{
	ifstream in;
	in.open("test.txt");

	string strFileData = "";
	int line = 1;
	char lineData[1024] = { 0 };
	while (in.getline(lineData, sizeof(lineData)))
	{
		if (line == lineNum)
		{
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();

	//写入文件
	ofstream out;
	out.open("Dtest.txt");
	out.flush();
	out << strFileData;
	out.close();
}


void Delete::dfind()
{
	//获取输入信息
	QString qstrname = delateinquire->text();
	string strname = qstrname.toStdString();
	const char *charname = strname.c_str();

	ofstream outFile;
	outFile.open("name.txt", ios::out | ios::binary);
	outFile << charname;
	outFile.close();
	ifstream ifile("name.txt");
	ostringstream buf;
	char ch;
	while (buf&&ifile.get(ch))
		buf.put(ch);
	string name = buf.str();
	QMessageBox messagebox;
	if (qstrname.isEmpty())
	{
		QMessageBox message;
		message.warning(NULL, QStringLiteral("错误"), QStringLiteral("  未填写姓名信息！  "));
	}

	int p = 0, q = 0;
	ifstream in("test.txt");
	string  s;
	while (getline(in, s))
	{
		p++;
		if (name == s)
		{
			q++;
			break;
		}
	}
	if (q == 0)
	{
		messagebox.warning(NULL, QStringLiteral("警告"), QStringLiteral("未查询到信息！请录入!"));
	}
	else
	{
		messagebox.warning(NULL, QStringLiteral("学籍信息"), QStringLiteral("您确定要删除该生学籍信息吗？"));
		DelLineData(p);
		DelLineData(p +1);
		DelLineData(p +2);
		DelLineData(p +3);
		DelLineData(p +4);
		messagebox.warning(NULL, QStringLiteral("学籍信息"), QStringLiteral("学籍信息已删除!"));
	}
	p = 0;
	q = 0;
}