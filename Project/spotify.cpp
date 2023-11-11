#include "spotify.h"
#include "ui_spotify.h"
#include "user.h"
#include <QtCore>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QFileInfo>
#include <song.h>
#include <QMessageBox>
#include <ButtonCard.h>


spotify::spotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spotify)
{
    ui->setupUi(this);
    user* u = user::get_instance();

    QIcon home(":/icons/homeW.png");
    QIcon search(":/icons/searchW.png");

    ui->Home_Button->setIcon(home);
    ui->Search_Button->setIcon(search);
    ui->Pages->setCurrentIndex(0);



    ui->Home_Button->setText("Home");
    ui->Search_Button->setText("Search");

    ui->greeting->setText("Good Evening " + u->get_userName());

    QPixmap image(":icons/song.png");

    /* Hard coded Button Cards */

    ButtonCard *card1 = new ButtonCard("Song 1");
    ButtonCard *card2 = new ButtonCard("Song 2");
    ButtonCard *card3 = new ButtonCard("Song 3");
    ButtonCard *card4 = new ButtonCard("Song 4");

    card1->setImage(image);
    card2->setImage(image);
    card3->setImage(image);
    card4->setImage(image);

    ui->Layout->addWidget(card1);
    ui->Layout->addWidget(card2);
    ui->Layout->addWidget(card3);
    ui->Layout->addWidget(card4);

    ui->Layout->setSpacing(15);

    ButtonCard *card5 = new ButtonCard("Song 1");
    ButtonCard *card6 = new ButtonCard("Song 2");
    ButtonCard *card7 = new ButtonCard("Song 4");
    ButtonCard *card8 = new ButtonCard("Song 3");

    card5->setImage(image);
    card6->setImage(image);
    card7->setImage(image);
    card8->setImage(image);


    ui->Layout_2->addWidget(card5);
    ui->Layout_2->addWidget(card6);
    ui->Layout_2->addWidget(card7);
    ui->Layout_2->addWidget(card8);

    ButtonCard *card9 = new ButtonCard("Song 1");
    ButtonCard *card10 = new ButtonCard("Song 2");
    ButtonCard *card11 = new ButtonCard("Song 4");
    ButtonCard *card12 = new ButtonCard("Song 3");

    card9->setImage(image);
    card10->setImage(image);
    card11->setImage(image);
    card12->setImage(image);

    ui->Layout_3->addWidget(card9);
    ui->Layout_3->addWidget(card10);
    ui->Layout_3->addWidget(card11);
    ui->Layout_3->addWidget(card12);

    ui->Layout_2->setSpacing(15);
    ui->Layout_3->setSpacing(15);

    /* Hard coded Button Cards */

    Player = new QMediaPlayer;
    Song s;
    QList<Song*> songList =  s.get_songs();
    for (Song* song : songList) {
        ui->listWidget->addItem(song->get_song());
    }
    audioOutput = new QAudioOutput;
    Player->setAudioOutput(audioOutput);
//    audioOutput->setBufferSize(32768);
    ui->volumeSlider->setMaximum(100);
    ui->volumeSlider->setMinimum(0);
    ui->volumeSlider->setValue(10);


    audioOutput->setVolume(ui->volumeSlider->value());
//    ui->label_3->setText(u->get_userName());

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
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (selectedItem) {
        QString selectedSongName = selectedItem->text();

        // Assuming you have a QList<Song*> songList = s.get_songs(); defined elsewhere
        Song s;
        QList<Song*> songList = s.get_songs();
        for (Song* song : songList) {
            if (song->get_song() == selectedSongName) {
                Player->setSource(QUrl::fromLocalFile(song->get_path()));
                break;
            }
        }

        // Update the SongName label
        ui->SongName->setText(selectedSongName);
    } else {

    }

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

void spotify::on_pushButton_clicked()
{
//    QMessageBox::warning(NULL, "Path Not Selected", "Please select a path");
}

ButtonCard::ButtonCard(const QString &text, QWidget *parent) :
    QFrame(parent),
    imageLabel(new QLabel()),
    textLabel(new QLabel(text)),
    text_(text),
    backgroundColor(QColor(255, 255, 255, 50))
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    layout->addWidget(imageLabel);

    layout->addWidget(textLabel);

    imageLabel->setStyleSheet("border-radius: 10px");
    textLabel->setStyleSheet("font: 16pt bold; color: white; background-color:rgba(50,50,50,0)");
    this->setStyleSheet("background-color: rgba(50,50,50, 0.7)");




    this->setBackgroundColor(backgroundColor);

//    connect(this, &ButtonCard::clicked, this, &ButtonCard::onButtonClicked);


}

void ButtonCard::setText(const QString &text)
{
    text_ = text;
    textLabel->setText(text);
}

QString ButtonCard::text() const
{
    return text_;
}

void ButtonCard::onButtonClicked()
{
    QMessageBox::warning(NULL, "Click Successful", "Button Clicked");
}

void ButtonCard::setImage(const QPixmap &image)
{
    imageLabel->setPixmap(image);
    imageLabel->setScaledContents(true);
}

void ButtonCard::setBackgroundColor(const QColor &color)
{
    // Set the background color of the QFrame
    QPalette palette;
    palette.setColor(QPalette::Button, color);
    setPalette(palette);
    backgroundColor = color;
}

void spotify::on_scrollArea_customContextMenuRequested(const QPoint &pos)
{

}


void spotify::on_Pages_currentChanged(int arg1)
{

}


void spotify::on_Home_Button_clicked()
{
    ui->Pages->setCurrentIndex(0);
}




void spotify::on_Search_Button_clicked()
{
    ui->Pages->setCurrentIndex(1);
}

