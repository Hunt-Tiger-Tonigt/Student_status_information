/********************************************************************************
** Form generated from reading UI file 'Inquire.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INQUIRE_H
#define UI_INQUIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inquire
{
public:

    void setupUi(QWidget *Inquire)
    {
        if (Inquire->objectName().isEmpty())
            Inquire->setObjectName(QString::fromUtf8("Inquire"));
        Inquire->resize(400, 300);

        retranslateUi(Inquire);

        QMetaObject::connectSlotsByName(Inquire);
    } // setupUi

    void retranslateUi(QWidget *Inquire)
    {
        Inquire->setWindowTitle(QApplication::translate("Inquire", "Inquire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inquire: public Ui_Inquire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INQUIRE_H
