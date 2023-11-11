#include "admin2.h"
#include "ui_admin2.h"

admin2::admin2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin2)
{
    ui->setupUi(this);
}

admin2::~admin2()
{
    delete ui;
}
