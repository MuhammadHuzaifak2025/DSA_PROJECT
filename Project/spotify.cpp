#include "spotify.h"
#include "ui_spotify.h"
#include "user.h"
#include <QtCore>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QFileInfo>
#include <song.h>
#include <ButtonCard.h>
#include <QDir>
#include <Data_structures.h>
#include <QTextStream>
#include <vector>

spotify::spotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spotify)
{
    ui->setupUi(this);
    user* u = user::get_instance();

//    u->S1->Load_from_File(u->get_userName());
//    u->add_all_playlist();

    QIcon home(":/icons/homeW.png");
    QIcon search(":/icons/searchW.png");

    ui->Home_Button->setIcon(home);
    ui->Search_Button->setIcon(search);
    ui->Pages->setCurrentIndex(0);



    ui->Home_Button->setText("Home");
    ui->Search_Button->setText("Search");

    ui->greeting->setText("Good Evening " + u->get_userName());
    ui->Your_playlist->setText(u->get_userName() + "'s Playlists");

    QPixmap image(":icons/song.png");
    QPixmap playImage(":icons/playbtn.png");

    Song s;

    QList<Song*> songList =  s.get_songs();
    for (Song* song : songList) {
        ui->listWidget->addItem(song->get_song());
    }

    QList<Song*> songList2 =  u->get_playlist_song();
    for (Song* song : songList2) {
        ui->Playlist->addItem(song->get_song());
    }

    QList <ButtonCard*> buttonCards;

    int count = 0;
    for(Song* song: songList) {

        if(count == 4){
            break;
        }
        ButtonCard* buttonCard = new ButtonCard(song->get_song());
        buttonCard->setImage(image);
        buttonCard->setFixedSize(212,210);
        buttonCard->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->Layout->addWidget(buttonCard);
        connect(buttonCard, &ButtonCard::Clicked, this, &spotify::handleTextFromButtonCard);
        buttonCards.append(buttonCard);
        count++;
    }

    ui->Layout->setSpacing(25);
    ui->Layout->setAlignment(Qt::AlignLeft);

    count = 0;
    for(Song* song: songList) {

        if(count == 4){
            break;
        }
        ButtonCard* buttonCard = new ButtonCard(song->get_song());
        buttonCard->setImage(image);
        buttonCard->setFixedSize(212,210);
        buttonCard->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->Layout_2->addWidget(buttonCard);
        connect(buttonCard, &ButtonCard::Clicked, this, &spotify::handleTextFromButtonCard);


        buttonCards.append(buttonCard);
        count++;
    }

    ui->Layout_2->setSpacing(25);

    QList <Song*> lastFour;

    count = 0;
    if(songList.length() >= 4){
        lastFour = songList.mid(songList.size() - 4);

        for(Song* song: lastFour){

            if(count == 4){
                break;
            }
            ButtonCard* buttonCard = new ButtonCard(song->get_song());
            buttonCard->setImage(image);
            buttonCard->setFixedSize(212,210);
            buttonCard->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            ui->Layout_3->addWidget(buttonCard);
            connect(buttonCard, &ButtonCard::Clicked, this, &spotify::handleTextFromButtonCard);
            buttonCards.append(buttonCard);
            count++;

        }
    }

    if(songList.length() < 4){

        for(Song* song: songList) {

            if(count == 4){
                break;
            }
            ButtonCard* buttonCard = new ButtonCard(song->get_song());
            buttonCard->setImage(image);
            buttonCard->setFixedSize(212,210);
            buttonCard->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            ui->Layout_3->addWidget(buttonCard);
            connect(buttonCard, &ButtonCard::Clicked, this, &spotify::handleTextFromButtonCard);


            buttonCards.append(buttonCard);
            count++;
        }
    }

    ui->Layout_2->setSpacing(25);
    ui->Layout_3->setSpacing(25);

    /* Hard coded Button Cards */

    Player = new QMediaPlayer;




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

spotify::~spotify(){
    QMessageBox::warning(NULL, "Click Successful", "Button Clicked");
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
    QPixmap playImage(":icons/playbtn");
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);
    playButton = new QPushButton();
    connect(playButton, &QPushButton::clicked, this, &ButtonCard::on_playButton_clicked);

    layout->addWidget(imageLabel);
    QHBoxLayout *hbox = new QHBoxLayout;

    hbox->addWidget(textLabel);
    this->setPlay(playImage);
    hbox->addWidget(playButton);

    layout->addLayout(hbox);

    imageLabel->setStyleSheet("border-radius: 10px");
    textLabel->setStyleSheet("font: 16pt bold; color: white; background-color:rgba(50,50,50,0)");
    this->setStyleSheet("background-color: rgba(50,50,50, 0.7)");

    this->setBackgroundColor(backgroundColor);
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

//void spotify::on_scrollArea_customContextMenuRequested(const QPoint &pos)
//{

//}


//void spotify::on_Pages_currentChanged(int arg1)
//{

//}


void spotify::on_Home_Button_clicked()
{
    ui->Pages->setCurrentIndex(0);
}


void spotify::deleteAllFilesInDirectory(const QString &directoryPath) {
    QDir directory(directoryPath);

    if (!directory.exists()) {
        qDebug() << "Directory does not exist:" << directoryPath;
        return;
    }

    QFileInfoList fileList = directory.entryInfoList(QDir::Files);

    for (const QFileInfo &fileInfo : fileList) {
        QString filePath = fileInfo.filePath();

        if (QFile::remove(filePath)) {
            qDebug() << "File deleted:" << filePath;
        } else {
            qDebug() << "Failed to delete file:" << filePath;
        }
    }
}

void spotify::on_Search_Button_clicked()
{
    ui->Pages->setCurrentIndex(1);
}

void spotify::closeEvent(QCloseEvent *event) {
    user* u = user::get_instance();

    // Delete all files in the playlist directory
    QDir dir("Users/" + u->get_userName() + "/playlist/");
    deleteAllFilesInDirectory(dir.path());

    // Save the playlists to files
    QVector<linked_list*> copyList = u->getPlaylist();
    for (linked_list* list : copyList) {
        QFile file(list->Name);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream stream(&file);
            Node* temp = list->head;
            do {
                stream << temp->object->get_song() + " | " << temp->object->get_path() + " | "
                       << temp->object->get_genre() + " | " << temp->object->get_artist() + " | " << "\n";

                temp = temp->Next;
            } while (temp != list->head);

            file.close();
        } else {
            qDebug() << "Failed to open file for writing:" << file.fileName();
        }
    }
}

ButtonCard::on_playButton_clicked(){
    emit Clicked(textLabel->text());
}

void spotify::handleTextFromButtonCard(const QString &text){

    if (text.length() > 0) {

        Song s;
        QList<Song*> songList = s.get_songs();
        for (Song* song : songList) {
            if (song->get_song() == text) {
                Player->setSource(QUrl::fromLocalFile(song->get_path()));
                break;
            }
        }

        // Update the SongName label
        ui->SongName->setText(text);
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

//QFile File("Songs.txt");
//if (!File.exists()) {
//    // Create the file if it doesn't exist
//    if (File.open(QIODevice::ReadWrite)) {
//        File.close();  // Close the file after creating
//    } else {
//        QMessageBox::warning(nullptr, "ERROR", "Cannot create Songs.txt!");
//        return;
//    }
//}

//if (!File.open(QIODevice::ReadWrite | QIODevice::Text)) {
//    QMessageBox::warning(nullptr, "ERROR", "Cannot open Songs.txt for appending!");
//    return;
//}

//QTextStream stream(&File);

//while (!stream.atEnd()) {
//    QString Line = stream.readLine();
//    if (Line.section("|", 0, 0) == Name || Line.section("|", 1, 1) == (" "+Path + " ")) {
//        QMessageBox::warning(NULL, "Login", "Song Already Registered");
//        File.close();
//        return;
//    }
//}
//File.seek(File.size());
//stream << Name + " | " << Path + " | "<< genre + " | "<< artist + " | " << "\n";
//File.close();
//QMessageBox::warning(NULL, "Login", "Song Registered");

