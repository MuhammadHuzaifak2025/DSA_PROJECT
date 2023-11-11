/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QLabel *label;
    QPushButton *Register_Song;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *Save;
    QPushButton *Back;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(764, 355);
        label = new QLabel(Admin);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 30, 171, 81));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color: black;"));
        Register_Song = new QPushButton(Admin);
        Register_Song->setObjectName("Register_Song");
        Register_Song->setGeometry(QRect(350, 110, 80, 24));
        label_2 = new QLabel(Admin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(188, 160, 91, 20));
        label_3 = new QLabel(Admin);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 160, 291, 16));
        lineEdit = new QLineEdit(Admin);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(310, 200, 113, 24));
        lineEdit_2 = new QLineEdit(Admin);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(310, 240, 113, 24));
        lineEdit_3 = new QLineEdit(Admin);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(310, 290, 113, 24));
        label_4 = new QLabel(Admin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 200, 91, 20));
        label_5 = new QLabel(Admin);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 240, 91, 20));
        label_6 = new QLabel(Admin);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 290, 91, 20));
        Save = new QPushButton(Admin);
        Save->setObjectName("Save");
        Save->setGeometry(QRect(330, 320, 80, 24));
        Back = new QPushButton(Admin);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(570, 240, 80, 24));

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Admin", "Register Song", nullptr));
        Register_Song->setText(QCoreApplication::translate("Admin", "Register Song", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "Path Chosen", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("Admin", "Song Name", nullptr));
        label_5->setText(QCoreApplication::translate("Admin", "Author Name", nullptr));
        label_6->setText(QCoreApplication::translate("Admin", "Genre", nullptr));
        Save->setText(QCoreApplication::translate("Admin", "Save", nullptr));
        Back->setText(QCoreApplication::translate("Admin", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
