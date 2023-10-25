#include "admin.h"
#include "ui_admin.h"
#include <QtCore>
#include <QtWidgets>
#include <QFileInfo>
#include <song.h>

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_Register_Song_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"",tr("MP3 Files (*.mp3)"));
    ui->label_3->setText(FileName);
}



void Admin::on_Save_clicked()
{

    QString FileName = ui->label_3->text();

    QString Song_Name = ui->lineEdit->text();
    QString Author_Name = ui->lineEdit_2->text();
    QString Genre= ui->lineEdit_3->text();
    if (FileName.isEmpty()) {
        QMessageBox::warning(NULL, "Path Not Selected", "Please select a path");
        this->on_Register_Song_clicked();
    } else if (Song_Name.isEmpty()) {
        ui->lineEdit->setFocus();  //
    } else if (Author_Name.isEmpty()) {
        ui->lineEdit_2->setFocus();
    } else if (Genre.isEmpty()) {
        ui->lineEdit_3->setFocus();
    } else {
        Song S1;
        S1.register_song(Song_Name, FileName, Genre, Author_Name);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->label_3->clear();
    }

}


void Admin::on_Back_clicked()
{
    MainWindow *s1 = new MainWindow;
    s1->show();
    this->close();
}

