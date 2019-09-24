#include "Student_status_information.h"
#include <qlabel.h>
#include <qpixmap.h>


Student_status_information::Student_status_information(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//���ñ���ͼƬ
	QLabel* mLabel = new QLabel(this);
	QPixmap photo;
	photo.load("C:/Users/wyc/source/repos/Student_status_information/Student_status_information/wyc.jpg");
	mLabel->setPixmap(photo);
	mLabel->setGeometry(QRect(0, 0, 800, 600));
	mLabel->setScaledContents(true);

	//������ʾ�ı���ѧ����Ϣ����ϵͳ
	QLabel *pQlabel = new QLabel(this);
	pQlabel->setText(QStringLiteral("ѧ����Ϣ����ϵͳ"));
	pQlabel->setStyleSheet("color:rgb(227,23,13);font-size:75px;font:bold 75px");
	pQlabel->setAlignment(Qt::AlignCenter);
	pQlabel->setGeometry(QRect(80, 50, 640, 100));

	//���ð�ť1����ѯ
	a1.setText(QStringLiteral("ѧ����Ϣ��ѯ"));
	a1.setParent(this);
	a1.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }" 
	);
	a1.resize(300, 100);
	a1.move(50, 200);

	//���ð�ť2��¼��
	a2.setText(QStringLiteral("ѧ����Ϣ¼��"));
	a2.setParent(this);
	a2.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }"
	);
	a2.resize(300, 100);
	a2.move(450, 200);

	//���ð�ť3���޸�
	a3.setText(QStringLiteral("ѧ����Ϣ�޸�"));
	a3.setParent(this);
	a3.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }"
	);
	a3.resize(300, 100);
	a3.move(50, 400);

	//���ð�ť4��ɾ��
	a4.setText(QStringLiteral("ѧ����Ϣɾ��"));
	a4.setParent(this);
	a4.setStyleSheet
	(
		"QPushButton{background-color:rgb(255,215,0); color: rgb(25,25,112); border-radius: 20px; border: 2px groove gray;font:bold 25px;font-size:40px;}"
		"QPushButton:hover{background-color:red; color: black;}"
		"QPushButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }"
	);
	a4.resize(300, 100);
	a4.move(450, 400);

}