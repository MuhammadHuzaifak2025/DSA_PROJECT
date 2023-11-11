/********************************************************************************
** Form generated from reading UI file 'admin2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN2_H
#define UI_ADMIN2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_admin2
{
public:

    void setupUi(QDialog *admin2)
    {
        if (admin2->objectName().isEmpty())
            admin2->setObjectName("admin2");
        admin2->resize(400, 300);

        retranslateUi(admin2);

        QMetaObject::connectSlotsByName(admin2);
    } // setupUi

    void retranslateUi(QDialog *admin2)
    {
        admin2->setWindowTitle(QCoreApplication::translate("admin2", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin2: public Ui_admin2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN2_H
