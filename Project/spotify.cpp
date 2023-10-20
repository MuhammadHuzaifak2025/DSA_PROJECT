#include "spotify.h"
#include "ui_spotify.h"
#include "user.h"

spotify::spotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spotify)
{
    ui->setupUi(this);
    user* u = user::get_instance();
    ui->label_3->setText(u->get_userName());
}

spotify::~spotify()
{
    delete ui;
}
