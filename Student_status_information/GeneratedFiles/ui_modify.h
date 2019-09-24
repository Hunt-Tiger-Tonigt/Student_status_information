/********************************************************************************
** Form generated from reading UI file 'modify.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFY_H
#define UI_MODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_modify
{
public:

    void setupUi(QWidget *modify)
    {
        if (modify->objectName().isEmpty())
            modify->setObjectName(QString::fromUtf8("modify"));
        modify->resize(400, 300);

        retranslateUi(modify);

        QMetaObject::connectSlotsByName(modify);
    } // setupUi

    void retranslateUi(QWidget *modify)
    {
        modify->setWindowTitle(QApplication::translate("modify", "modify", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modify: public Ui_modify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFY_H
