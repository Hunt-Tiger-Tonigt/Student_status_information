/********************************************************************************
** Form generated from reading UI file 'Input.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_H
#define UI_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Input
{
public:

    void setupUi(QWidget *Input)
    {
        if (Input->objectName().isEmpty())
            Input->setObjectName(QString::fromUtf8("Input"));
        Input->resize(400, 300);

        retranslateUi(Input);

        QMetaObject::connectSlotsByName(Input);
    } // setupUi

    void retranslateUi(QWidget *Input)
    {
        Input->setWindowTitle(QApplication::translate("Input", "Input", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Input: public Ui_Input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_H
