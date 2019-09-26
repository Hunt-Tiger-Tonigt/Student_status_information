#include "modify.h"
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

modify::modify(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//���ô���ͼ��
	QIcon icon("C:/Users/wyc/source/repos/wyc/Student_status_information/Icon/icon2.ico");
	setWindowIcon(icon);

	this->resize(800, 600);

	//���ñ���ͼƬ
	QLabel* mLabel = new QLabel(this);
	QPixmap photo;
	photo.load("C:/Users/wyc/source/repos/wyc/Student_status_information/Student_status_information/wyc.jpg");
	mLabel->setPixmap(photo);
	mLabel->setGeometry(QRect(0, 0, 800, 600));
	mLabel->setScaledContents(true);

	//������ʾ�ı���ѧ����Ϣ¼��
	QLabel *pQlabel = new QLabel(this);
	pQlabel->setText(QStringLiteral("ѧ����Ϣ�޸�"));
	pQlabel->setStyleSheet("color:rgb(227,23,13);font-size:75px;font:bold 75px");
	pQlabel->setAlignment(Qt::AlignCenter);
	pQlabel->setGeometry(QRect(80, 50, 640, 100));

	//��������
	modifyinquire = new QLineEdit(this);
	modifyinquire->setPlaceholderText(QStringLiteral("����������"));
	modifyinquire->setEchoMode(QLineEdit::Normal);
	modifyinquire->setAlignment(Qt::AlignLeft);
	modifyinquire->move(100, 200);
	modifyinquire->resize(600, 50);
	modifyinquire->setFont(QFont("Timers", 15, QFont::Bold));
	
	//�޸�������
	numberinquire = new QLineEdit(this);
	numberinquire->setPlaceholderText(QStringLiteral("�������޸���"));
	numberinquire->setEchoMode(QLineEdit::Normal);
	numberinquire->setAlignment(Qt::AlignLeft);
	numberinquire->move(100, 300);
	numberinquire->resize(600, 50);
	numberinquire->setFont(QFont("Timers", 15, QFont::Bold));
	
	//�޸���������
	modifyinf = new QLineEdit(this);
	modifyinf->setPlaceholderText(QStringLiteral("�������޸�����"));
	modifyinf->setEchoMode(QLineEdit::Normal);
	modifyinf->setAlignment(Qt::AlignLeft);
	modifyinf->move(100, 400);
	modifyinf->resize(600, 50);
	modifyinf->setFont(QFont("Timers", 15, QFont::Bold));

	this->setWindowTitle(QStringLiteral("ѧ����Ϣ�޸�"));

	//���ذ�ť
	ma1.setText(QStringLiteral("����"));
	ma1.move(500, 500);
	ma1.setParent(this);
	connect(&ma1, &QPushButton::clicked, this, &modify::mback);

	//�ϴ���ť
	ma2.setText(QStringLiteral("�޸�"));
	ma2.move(150, 500);
	ma2.setParent(this);
	connect(&ma2, &QPushButton::pressed, this, &modify::mfind);
}

modify::~modify()
{
}

void modify::mback()
{
	emit mmysignal();
}

string mCharToStr(char * contentChar)
{
	string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}

void ModifyLineData(int lineNum, char* lineData)
{
	ifstream in;
	in.open("test.txt");

	string strFileData = "";
	int line = 1;
	char tmpLineData[1024] = { 0 };
	while (in.getline(tmpLineData, sizeof(tmpLineData)))
	{
		if (line == lineNum)
		{
			strFileData += mCharToStr(lineData);
			strFileData += "\n";
		}
		else
		{
			strFileData += mCharToStr(tmpLineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();

	//д���ļ�
	ofstream out;
	out.open("test.txt");
	out.flush();
	out << strFileData;
	out.close();
}

void modify::mfind()
{
	//��ȡ������Ϣ
	QString qstr1 = modifyinquire->text();
	string str1 = qstr1.toStdString();
	const char *char1 = str1.c_str();
	
	QString qstr2 = numberinquire->text();
	string str2 = qstr2.toStdString();
	const char *char2 = str2.c_str();
	int x=atoi(char2);
	
	QString qstr3 = modifyinf->text();
	string str3 = qstr3.toStdString();
	const char *char3 = str3.c_str();

	ofstream outFile;
	outFile.open("1.txt", ios::out | ios::binary);
	outFile << char1;
	outFile.close();
	ifstream ifile("1.txt");
	ostringstream buf;
	char ch;
	while (buf&&ifile.get(ch))
		buf.put(ch);
	string wyc1 = buf.str();
	
	ofstream outFile1;
	outFile1.open("2.txt", ios::out | ios::binary);
	outFile1 << char3;
	outFile1.close();
	ifstream ifile1("2.txt");
	ostringstream buf1;
	char ch1;
	while (buf1&&ifile1.get(ch))
		buf1.put(ch);
	string wyc2 = buf1.str();
	const char* wyc3 = wyc2.c_str();
	char* wyc4= const_cast<char*>(wyc3);

	QMessageBox messagebox;
	if (qstr1.isEmpty())
	{
		QMessageBox message;
		message.warning(NULL, QStringLiteral("����"), QStringLiteral("  δ��д������Ϣ��  "));
	}

	int i = 0, j = 0;
	ifstream in("test.txt");
	string  s;
	while (getline(in, s))
	{
		i++;
		if (wyc1 == s)
		{
			j++;
			break;
		}
	}
	if (j == 0)
	{
		messagebox.warning(NULL, QStringLiteral("����"), QStringLiteral("δ��ѯ����Ϣ����¼��!"));
	}
	else
	{
		messagebox.warning(NULL, QStringLiteral("ѧ����Ϣ"), QStringLiteral("��ȷ��Ҫ�޸���"));
		switch (x)
		{
		case 1:
			ModifyLineData(i, wyc4);
			break;
		case 2:
			ModifyLineData(i + 1, wyc4);
			break;
		case 3:
			ModifyLineData(i + 2, wyc4);
			break;
		case 4:
			ModifyLineData(i + 3, wyc4);
			break;
		case 5:
			ModifyLineData(i + 4, wyc4);
			break;
		}
		messagebox.warning(NULL, QStringLiteral("ѧ����Ϣ"), QStringLiteral("ѧ����Ϣ���޸�!"));
	}
	i = 0;
	j = 0;
}
