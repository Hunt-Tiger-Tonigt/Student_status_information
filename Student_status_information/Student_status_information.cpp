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
#include "Input.h"

#define N 80

using namespace std;

//学生基本信息结构体
struct StuInfo
{
	char name[20];   //姓名
	char sex[10];     //性别
	char stuNo[20];        //学号
	int  domNum;   //宿舍号 
	char  tel[12];        //电话号码 
};   

Student_status_information::Student_status_information(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	StuInfo d[N];
	int stuNum = 0;
	
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
	connect(&i, &Inquire::mysignal, this, &Student_status_information::dealinquire);
	connect(&a2, &QPushButton::clicked, this, &Student_status_information::cw2input);
	connect(&p, &Input::psignal, this, &Student_status_information::dealinput);
	connect(&p, &Input::p2signal, this, &Student_status_information::deal2input);

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

void Student_status_information::deal2input()
{
	ifstream ifile("C://Users//wyc//source//repos//wyc//Student_status_information//lins//flag.txt");
	ostringstream buf;
	char ch;
	while (buf&&ifile.get(ch))
		buf.put(ch);
	string flag= buf.str();
	int a = atoi(flag.c_str());
	a++;
	ofstream fout;
	fout.open("C:\\Users\\wyc\\source\\repos\\wyc\\Student_status_information\\lins\\flag.txt", ios::out | ios::trunc);
	fout << a << endl;
	fout.close();

	ifstream ifile1("C://Users//wyc//source//repos//wyc//Student_status_information//lins//name.txt");
	ostringstream buf1;
	char ch1;
	while (buf1&&ifile1.get(ch1))
		buf1.put(ch1);
	string name = buf1.str();
	const char* charname = name.c_str();
	char cname[20];
	strncpy_s(cname, charname, 20);

	ifstream ifile2("C://Users//wyc//source//repos//wyc//Student_status_information//lins//gender.txt");
	ostringstream buf2;
	char ch2;
	while (buf2&&ifile2.get(ch2))
		buf2.put(ch2);
	string gender = buf2.str();
	const char* chargender = gender.c_str();
	char cgender[20];
	strncpy_s(cgender, chargender, 3);

	ifstream ifile3("C://Users//wyc//source//repos//wyc//Student_status_information//lins//ID.txt");
	ostringstream buf3;
	char ch3;
	while (buf3&&ifile3.get(ch3))
		buf3.put(ch3);
	string ID = buf3.str();
	//int id = atoi(ID.c_str());
	const char* charID = ID.c_str();
	char cid[12];
	strncpy_s(cid, charID, 12);

	ifstream ifile4("C://Users//wyc//source//repos//wyc//Student_status_information//lins//dormitory.txt");
	ostringstream buf4;
	char ch4;
	while (buf4&&ifile4.get(ch4))
		buf4.put(ch4);
	string dormitory = buf4.str();
	int dor = atoi(dormitory.c_str());
	//const char* chardormitory = dormitory.c_str();

	ifstream ifile5("C://Users//wyc//source//repos//wyc//Student_status_information//lins//number.txt");
	ostringstream buf5;
	char ch5;
	while (buf5&&ifile5.get(ch5))
		buf5.put(ch5);
	string number = buf5.str();
	const char* charnumber = number.c_str();
	char cnumber[13];
	strncpy_s(cnumber, charnumber, 13);

	//string str = to_string(a);
	//string node = "Student";
	//string nodename = node + str;
	//string nodeName = "Student";
	QMessageBox messagebox;
	StuInfo *t = new StuInfo[5];
	strcpy(t->name, cname);
	strcpy(t->sex, cgender);
	strcpy(t->tel, cnumber);
	strcpy(t->stuNo, cid);
	t->domNum = dor;

	ofstream outFile;
	outFile.open("D:\\test.txt", ios::app | ios::binary);
	messagebox.information(NULL, QStringLiteral("SUCCESS"), QStringLiteral("上传成功！"));

	if (!outFile)
	{
		messagebox.information(NULL, QStringLiteral("警告"), QStringLiteral("上传失败！"));
		abort();
	}
	else
	{
		outFile << t->name;
		outFile << t->sex << endl;
		outFile << t->stuNo;
		outFile << t->domNum << endl;
		outFile << t->tel << endl;
		//outFile << t->name << t->sex << t->stuNo << t->domNum << t->tel << endl;
		//outFile.write((char*)&t, sizeof(StuInfo));
		outFile.close();
	}
}

