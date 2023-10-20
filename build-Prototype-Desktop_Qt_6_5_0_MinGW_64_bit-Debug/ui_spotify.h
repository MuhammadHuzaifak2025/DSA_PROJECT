/********************************************************************************
** Form generated from reading UI file 'spotify.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPOTIFY_H
#define UI_SPOTIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_spotify
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *spotify)
    {
        if (spotify->objectName().isEmpty())
            spotify->setObjectName("spotify");
        spotify->resize(832, 475);
        label = new QLabel(spotify);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -180, 831, 841));
        label->setStyleSheet(QString::fromUtf8("image: url(:/images/background2.jpg);"));
        label_2 = new QLabel(spotify);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 70, 701, 131));
        label_2->setStyleSheet(QString::fromUtf8("color: #FFF;\n"
"\n"
"font-family: Inter;\n"
"font-size: 63px;\n"
"font-style: normal;\n"
"font-weight: 700;\n"
"line-height: normal;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(spotify);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 210, 701, 131));
        label_3->setStyleSheet(QString::fromUtf8("color: #FFF;\n"
"\n"
"font-family: Inter;\n"
"font-size: 63px;\n"
"font-style: normal;\n"
"font-weight: 700;\n"
"line-height: normal;"));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(spotify);

        QMetaObject::connectSlotsByName(spotify);
    } // setupUi

    void retranslateUi(QDialog *spotify)
    {
        spotify->setWindowTitle(QCoreApplication::translate("spotify", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("spotify", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("spotify", "Spotify", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class spotify: public Ui_spotify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOTIFY_H
