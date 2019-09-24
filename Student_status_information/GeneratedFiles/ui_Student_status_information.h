/********************************************************************************
** Form generated from reading UI file 'Student_status_information.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_STATUS_INFORMATION_H
#define UI_STUDENT_STATUS_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Student_status_informationClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Student_status_informationClass)
    {
        if (Student_status_informationClass->objectName().isEmpty())
            Student_status_informationClass->setObjectName(QString::fromUtf8("Student_status_informationClass"));
        Student_status_informationClass->resize(600, 400);
        menuBar = new QMenuBar(Student_status_informationClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Student_status_informationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Student_status_informationClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Student_status_informationClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Student_status_informationClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Student_status_informationClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Student_status_informationClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Student_status_informationClass->setStatusBar(statusBar);

        retranslateUi(Student_status_informationClass);

        QMetaObject::connectSlotsByName(Student_status_informationClass);
    } // setupUi

    void retranslateUi(QMainWindow *Student_status_informationClass)
    {
        Student_status_informationClass->setWindowTitle(QApplication::translate("Student_status_informationClass", "Student_status_information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student_status_informationClass: public Ui_Student_status_informationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_STATUS_INFORMATION_H
