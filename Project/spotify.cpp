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
#include "playlistselectiondialog.h"
#include "SoundWaves.h"

spotify::spotify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::spotify)
{
    ui->setupUi(this);
    u = user::get_instance();

    // Loads History From the File to the stack class
    u->History.Load_to_file("Users/" + u->get_userName() + "/History.txt");

    QIcon home(":/icons/homeW.png");
    QIcon search(":/icons/searchW.png");
    listStyle ="QListWidget { background-color: rgba(40, 40, 40, 0.7); color: white; selection-background-color: #a0a0a0; border: 1px rgba(40, 40, 40, 0.7); border-radius: 15px; }"
    "QListWidget::item { background-color: rgba(40, 40, 40, 0.7); padding: 10px; border: 1px rgba(40, 40, 40, 0.7); border-radius: 15px; }"
    "QListWidget::item:hover { background-color: rgba(40, 40, 40, 0.3); border: 1px rgba(40, 40, 40, 0.7); border-radius: 15px; }"
    "QScrollBar:vertical, QScrollBar:horizontal { background-color: rgba(40, 40, 40, 0.7); width: 10px; margin: 0px 0px 0px 0px; border: 1px rgba(40, 40, 40, 0.7); border-radius: 5px 0 0 5px; }"
    "QScrollBar::handle:vertical, QScrollBar::handle:horizontal { background: #a0a0a0; min-height: 20px; border: 1px rgba(40, 40, 40, 0.7); border-radius: 5px 0 0 5px; }"
    "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical, QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal { border: none; background: none; border: 1px rgba(40, 40, 40, 0.7); border-radius: 5px 0 0 5px; }"
    "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical, QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal { background: none; border: 1px rgba(40, 40, 40, 0.7); border-radius: 5px 0 0 5px; }";

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

    songList =  s.get_songs();
    for (Song* song : songList) {
        ui->listWidget->addItem(song->get_song());
    }

    for(Song* song: songList){

        suggestion.append(song->get_song());
        songs.append(song->get_song());
    }

    ui->SearchList->addItems(songs);
    ui->SearchList->hide();

//    songList2 =  u->get_playlist_song();
    playlists = u->getPlaylistNames();


    Playlist = new QListWidget;
    connect(Playlist, &QListWidget::itemClicked, this, &spotify::onItemClicked);

    Playlist->setStyleSheet(listStyle);
    ui->listLayout->addWidget(Playlist);


    for(QString a: playlists){

        Playlist->addItem(a);
    }
//    for (Song* song : songList2) {
//        ui->Playlist->addItem(song->get_song());
//        playlists.append(song->get_song());
//    }

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
        connect(buttonCard, &ButtonCard::addToPlaylistRequested, this, &spotify::handleAddToPlaylist);
        connect(buttonCard, &ButtonCard::addToQueueRequested, this, &spotify::handleAddToQueue);
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
            connect(buttonCard, &ButtonCard::addToPlaylistRequested, this, &spotify::handleAddToPlaylist);
            connect(buttonCard, &ButtonCard::addToQueueRequested, this, &spotify::handleAddToQueue);
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
            connect(buttonCard, &ButtonCard::addToPlaylistRequested, this, &spotify::handleAddToPlaylist);
            connect(buttonCard, &ButtonCard::addToQueueRequested, this, &spotify::handleAddToQueue);

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
    ui->volumeSlider->setMaximum(100);
    ui->volumeSlider->setMinimum(0);
    ui->volumeSlider->setValue(10);


    audioOutput->setVolume(ui->volumeSlider->value());

    ui->play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->skip_foward_button->setIcon(style()->standardIcon((QStyle::SP_MediaSkipForward)));
    ui->skip_behind_button->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->mute_button->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    ui->skip_ten_seconds_back->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->skip_ten_seconds_foward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

    QTimer *updateTimer;
    updateTimer = new QTimer(this);
    updateTimer->start(5000);

    connect(ui->search_bar, &QLineEdit::textChanged, this, &spotify::updateSongList);
    connect(ui->search_bar, &QLineEdit::editingFinished, this, &spotify::hideList);
    connect(ui->search_bar, &QLineEdit::selectionChanged, this, &spotify::showList);
    connect(ui->search_bar, &QLineEdit::cursorPositionChanged, this, &spotify::showList);
    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this, &spotify::on_play_button_clicked);
    connect(Playlist, &QListWidget::itemSelectionChanged, this, &spotify::on_play_button_clicked);

    ui->musicTimer->hide();

//    connect(Player, &QMediaPlayer::durationChanged, this, &spotify::durationChanged);
//    connect(ui->musicTimer, &QSlider::valueChanged, this, &spotify::on_musicTimer_valueChanged);
//    connect(updateTimer, &QTimer::timeout, this, &spotify::updateSliderPosition);
//    connect(Player, &QMediaPlayer::positionChanged, this, &spotify::positionChanged);


    connect(Player, &QMediaPlayer::mediaStatusChanged, this, &spotify::on_mediaStateChanged);

    ui->musicTimer->setRange(0,Player->duration() / 1000);
}

spotify::~spotify(){
    QMessageBox::warning(NULL, "Click Successful", "Button Clicked");
    delete ui;
}



void spotify::updateDuration(qint64 duration)
{
    if(duration || PlayerDuration){
        QTime CurrentTime((duration / 3600) % 60, (duration / 60) % 60, (duration * 1000) % 1000);
        QTime totalTime((PlayerDuration/ 3600) % 60, (PlayerDuration / 60) & 60, (PlayerDuration * 1000) % 1000);
//        QString format = "mm:ss";

//        ui->songDuration->setText(totalTime.toString(format));
    }
}

void spotify:: on_mediaStateChanged(QMediaPlayer::MediaStatus status)
{
    switch (status) {
    case QMediaPlayer::LoadingMedia:
        qDebug() << "Media is loading...";
        break;

    case QMediaPlayer::LoadedMedia:
        qDebug() << "Media loaded successfully.";
        break;

    case QMediaPlayer::StalledMedia:
        qDebug() << "Media playback stalled.";
        break;

    case QMediaPlayer::BufferingMedia:
        qDebug() << "Media buffering...";
        break;

    case QMediaPlayer::BufferedMedia:
        qDebug() << "Media buffered and ready to play.";
        break;

    case QMediaPlayer::EndOfMedia:
        qDebug() << "End of media.";
        if(songQueue.size() > 1){
            songQueue.removeFirst();
            Song s(songQueue.first()->get_song(), songQueue.first()->get_path(), songQueue.first()->get_genre(), songQueue.first()->get_artist());
            Player->setSource(songQueue.first()->get_path());
            Player->play();
            u->History.Push(s);
            ui->SongName->setText(songQueue.first()->get_song());
        }
        break;

    case QMediaPlayer::InvalidMedia:
        qDebug() << "Invalid media source.";
        break;

    default:
        qDebug() << "Default Case";
        break;
    }
}


void spotify::updateSliderPosition()
{
    qint64 position = Player->position();
    ui->musicTimer->setValue(position / 1000);
}

void spotify::durationChanged(qint64 duration)
{
    ui->musicTimer->setRange(0, duration / 1000);
}

void spotify::positionChanged(qint64 position)
{

    ui->musicTimer->setValue(position / 1000);
}


void spotify::on_play_button_clicked()
{
//    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    QListWidget* senderListWidget = qobject_cast<QListWidget*>(sender());

    if(senderListWidget == Playlist){
        return;
    }

    if (senderListWidget) {

        QListWidgetItem* selectedItem = senderListWidget->currentItem();
        QString selectedSongName = selectedItem->text();

        // Assuming you have a QList<Song*> songList = s.get_songs(); defined elsewhere
        Song s;
        QList<Song*> songList = s.get_songs();
        for (Song* song : songList) {
            if (song->get_song() == selectedSongName) {

                songQueue.append(song);                
                Player->setSource(songQueue.first()->get_path());
                u->History.Push(*song);
                qDebug() << "Hello\n";
                break;
            }
        }
        // Update the SongName label
        ui->SongName->setText(songQueue.first()->get_path());
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
    Player->setPosition((Player->position() - 10) * 1000);
}


void spotify::on_skip_ten_seconds_foward_clicked()
{
        Player->setPosition((Player->position() + 10) * 1000);
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
        qDebug() <<list->Name<<"\n";
        QFile file(("Users/" + u->get_userName() + "/playlist/")+list->Name+".txt");
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream stream(&file);
            Node* temp = list->head;
            if(list->head != NULL)
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
    u->History.File_History("Users/" + u->get_userName() + "/History.txt");
}

void ButtonCard::on_playButton_clicked(){
    emit Clicked(textLabel->text());
}

void spotify::handleTextFromButtonCard(const QString &text){

    if (text.length() > 0) {

        Song s;
        QList<Song*> songList = s.get_songs();
        for (Song* song : songList) {
            if (song->get_song() == text) {
                Player->setSource(QUrl::fromLocalFile(song->get_path()));
                u->History.Push(*song);
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
        ui->play_button->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        isPlaying = false;
        Sleep(200);
        Player->play();
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

void spotify::hideList(){
    ui->SearchList->hide();
}

void spotify::showList(){
    ui->SearchList->show();
}

void spotify::updateSongList(){
    QString currentText = ui->search_bar->text().toLower();

    ui->SearchList->clear();

    QStringList matchingSongs;
    for (const QString &song : songs) {
        if (song.toLower().contains(currentText)) {
            matchingSongs << song;
        }
    }

    ui->SearchList->addItems(matchingSongs);
}

bool spotify::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->search_bar) {
        if (event->type() == QEvent::FocusIn) {
            showList();
        } else if (event->type() == QEvent::FocusOut) {
            hideList();
        }
    }

    return QWidget::eventFilter(obj, event);
}

void spotify::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape) {
        if(ui->SearchList->isHidden()){
            event->ignore();
            return;
        }
        hideList();
    } else {
        QWidget::keyPressEvent(event);
    }
}


void spotify::handleAddToPlaylist(const QString &text){
    PlaylistSelectionDialog dialog(playlists, this);

    if (dialog.exec() == QDialog::Accepted) {

        QString selectedPlaylist = dialog.selectedPlaylist();

        if (dialog.isNewPlaylistSelected()) {

            QString newName = dialog.getName();
            qDebug() << "Create new playlist: " << newName;
            playlists.append(newName);
            for(Song *S : songList){

                if(text == S->get_song())
                    u->add_playlist(newName,S);
            }

        }

        else{

            for(Song *S : songList){
                if(text == S->get_song()){
                    QVector<linked_list*> New_list = u->getPlaylist();
                    for(linked_list* list : New_list){
                        if(list->Name == selectedPlaylist){
                            list->add_to_end_list(S);
                        }
                    }
                    u->SetPlaylist(New_list);
                    return;
                }

            }
        }
    }

    QStringList newplaylist;
    Playlist->clear();
    for(QString a: playlists){

        newplaylist << a;
    }

    Playlist->addItems(newplaylist);

}

void spotify::onItemClicked(QListWidgetItem *item){

    ui->Playlist_Name->setText(item->text());
    ui->Pages->setCurrentIndex(2);
    ui->label_9->setText("Now Playing");

    QList <Song*> slist  = u->get_linked_list_song(u->Playlist.at(Playlist->currentRow()));

    songQueue.clear();
    ui->playlistPlaying->clear();
//    u->History.Push();
    Player->play();
    for(Song* song : slist){

        ui->playlistPlaying->addItem(song->get_song());
        songQueue.append(song);
    }

    Player->setSource(songQueue.first()->get_path());

    qDebug() << Playlist->currentRow();
}

void spotify::handleAddToQueue(const QString &text){

    for(Song *S : songList){

        if(text == S->get_song())
            songQueue.append(S);
    }
}
