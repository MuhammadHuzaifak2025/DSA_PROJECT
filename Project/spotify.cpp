#include "spotify.h"
#include "ui_spotify.h"
#include "user.h"
#include <QtCore>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QFileInfo>



spotify::spotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spotify)
{
    ui->setupUi(this);
    user* u = user::get_instance();

    Player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    Player->setAudioOutput(audioOutput);
//    audioOutput->setBufferSize(32768);
    ui->volumeSlider->setMaximum(100);
    ui->volumeSlider->setMinimum(0);
    ui->volumeSlider->setValue(10);


    audioOutput->setVolume(ui->volumeSlider->value());
    ui->label_3->setText(u->get_userName());

    ui->play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->skip_foward_button->setIcon(style()->standardIcon((QStyle::SP_MediaSkipForward)));
    ui->skip_behind_button->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->mute_button->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->skip_ten_seconds_back->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->skip_ten_seconds_foward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

    connect(Player, &QMediaPlayer::durationChanged, this, &spotify::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &spotify::positionChanged);
    ui->musicTimer->setRange(0,Player->duration() / 1000);
}

spotify::~spotify()
{
    delete ui;
}

void spotify::updateDuration(qint64 duration)
{
    QString timestr;
    if(duration || PlayerDuration){
        QTime CurrentTime((duration / 3600) % 60, (duration / 60) % 60, (duration * 1000) % 1000);
        QTime totalTime((PlayerDuration/ 3600) % 60, (PlayerDuration / 60) & 60, (PlayerDuration * 1000) % 1000);
//        QString format = "mm:ss";

//        ui->songDuration->setText(totalTime.toString(format));
    }
}

void spotify::durationChanged(qint64 duration)
{
    PlayerDuration = duration / 1000;
    ui->musicTimer->setMaximum(PlayerDuration);
}

void spotify::positionChanged(qint64 position)
{
    if(!ui->musicTimer->isSliderDown()){
        ui->musicTimer->setValue(position / 1000);
    }

    updateDuration(position / 1000);
}

void spotify::on_play_button_clicked()
{

    if(isPlaying == false){
        Player->play();
        ui->play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        isPlaying = true;

    }

    else{
        ui->play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        isPlaying = false;
        Player->pause();
    }
}


void spotify::on_mute_button_clicked()
{
    if(isMuted == false){
        ui->mute_button->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        isMuted = true;
    }

    else{
        ui->mute_button->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        isMuted = false;
    }
}


void spotify::on_pushButton_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"",tr("MP3 Files (*.mp3)"));
    Player->setSource(QUrl::fromLocalFile(FileName));
    QFileInfo fileInfo(FileName);
    ui->SongName->setText(fileInfo.fileName());
}


void spotify::on_volumeSlider_valueChanged(int value)
{
    ui->volumeSlider->setValue(value);
    audioOutput->setVolume(ui->volumeSlider->value());
}


void spotify::on_musicTimer_valueChanged(int value)
{
    Player->setPosition(value * 1000);
}


void spotify::on_skip_ten_seconds_back_clicked()
{
    ui->musicTimer->setValue(ui->musicTimer->value() - 10);
    Player->setPosition(ui->musicTimer->value() * 1000);
}


void spotify::on_skip_ten_seconds_foward_clicked()
{
    ui->musicTimer->setValue(ui->musicTimer->value() + 10);
    Player->setPosition(ui->musicTimer->value() * 1000);
}

