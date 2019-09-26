#include "Inquire.h"
#include <qlabel.h>
#include <qpixmap.h>
#include <qmessagebox.h>
#include <resource.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <QtSql/qsqldatabase.h>

#include<windows.h>
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

Inquire::Inquire(QWidget *parent)
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
	pQlabel->setText(QStringLiteral("学籍信息查询"));
	pQlabel->setStyleSheet("color:rgb(227,23,13);font-size:75px;font:bold 75px");
	pQlabel->setAlignment(Qt::AlignCenter);
	pQlabel->setGeometry(QRect(80, 50, 640, 100));

	//姓名输入
	nameinquire = new QLineEdit(this);
	nameinquire->setPlaceholderText(QStringLiteral("请输入姓名"));
	nameinquire->setEchoMode(QLineEdit::Normal);
	nameinquire->setAlignment(Qt::AlignLeft);
	nameinquire->move(100, 200);
	nameinquire->resize(600, 50);
	nameinquire->setFont(QFont("Timers", 15, QFont::Bold));

	this->setWindowTitle(QStringLiteral("学籍信息查询"));

	//返回按钮
	ia1.setText(QStringLiteral("返回"));
	ia1.move(500, 400);
	ia1.setParent(this);
	connect(&ia1, &QPushButton::clicked, this, &Inquire::iback);

	//上传按钮
	ia2.setText(QStringLiteral("查询"));
	ia2.move(150, 400);
	ia2.setParent(this);
	connect(&ia2, &QPushButton::pressed, this, &Inquire::ifind);
}

Inquire::~Inquire()
{
}

void Inquire::iback()
{
	emit mysignal();
}

string readTxt(int line)
{
	//line行数限制 1 - lines
	ifstream text;
	text.open("test.txt", ios::in);
	vector<string> strVec;
	while (!text.eof())  //行0 - 行lines对应strvect[0] - strvect[lines]
	{
		string inbuf;
		getline(text, inbuf, '\n');
		strVec.push_back(inbuf);
	}
	return strVec[line - 1];
}

string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

QString str2qstr(const string str)
{
	return QString::fromLocal8Bit(str.data());
}

void Inquire::ifind()
{
	//获取输入信息
	QString qstrname = nameinquire->text();
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

	int m = 0, n = 0;
	ifstream in("test.txt");
	string  s;
	while (getline(in, s))
	{
		m++;
		if (name == s)
		{
			n++;
			break;
		}
	}
	if (n == 0)
	{
		messagebox.warning(NULL, QStringLiteral("警告"), QStringLiteral("未查询到信息！请录入!"));
	}
	else
	{
		string l1 = readTxt(m);
		string l11 = UTF8ToGB(l1.c_str());
		string l2 = readTxt(m + 1);
		string l22 = UTF8ToGB(l2.c_str());
		string l3 = readTxt(m + 2);
		string l4 = readTxt(m + 3);
		string l5 = readTxt(m + 4);
		string g = "\n";
		string m1 = "姓名：";
		string m2 = "性别：";
		string m3 = "学号：";
		string m4 = "宿舍号：";
		string m5 = "联系方式：";
		string wyc = m1 + l11 + g + m2 + l22 + g + m3 + l3 + g + m4 + l4 + g + m5 + l5;
		messagebox.information(NULL, QStringLiteral("学籍信息"), QString(str2qstr(wyc)));
	}
	m = 0;
	n = 0;
}