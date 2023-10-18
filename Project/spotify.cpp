#include "spotify.h"
#include "ui_spotify.h"

spotify::spotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spotify)
{
    ui->setupUi(this);
}

spotify::~spotify()
{
    delete ui;
}
