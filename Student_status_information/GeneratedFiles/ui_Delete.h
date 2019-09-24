/********************************************************************************
** Form generated from reading UI file 'Delete.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETE_H
#define UI_DELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Delete
{
public:

    void setupUi(QWidget *Delete)
    {
        if (Delete->objectName().isEmpty())
            Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->resize(400, 300);

        retranslateUi(Delete);

        QMetaObject::connectSlotsByName(Delete);
    } // setupUi

    void retranslateUi(QWidget *Delete)
    {
        Delete->setWindowTitle(QApplication::translate("Delete", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delete: public Ui_Delete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETE_H
