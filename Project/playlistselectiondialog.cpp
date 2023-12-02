#include "PlaylistSelectionDialog.h"

PlaylistSelectionDialog::PlaylistSelectionDialog(const QStringList &playlistNames, QWidget *parent)
    : QDialog(parent), createNewPlaylistSelected(false) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    playlistComboBox = new QComboBox(this);
    playlistComboBox->addItems(playlistNames);

    newPlaylistLineEdit = new QLineEdit(this);
    newPlaylistLineEdit->setPlaceholderText("Enter new playlist name");

    okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &PlaylistSelectionDialog::acceptSelection);

    QPushButton *createNewPlaylistButton = new QPushButton("Create New Playlist", this);
    connect(createNewPlaylistButton, &QPushButton::clicked, this, &PlaylistSelectionDialog::createNewPlaylist);

    layout->addWidget(playlistComboBox);
    layout->addWidget(newPlaylistLineEdit);
    layout->addWidget(okButton);
    layout->addWidget(createNewPlaylistButton);

    setLayout(layout);
    setWindowTitle("Select or Create Playlist");

    // stylesheets

    playlistComboBox->setStyleSheet("QComboBox { padding: 8px; font-size: 14px; color:white; }");
    newPlaylistLineEdit->setStyleSheet("QLineEdit { padding: 8px; font-size: 14px; color:white; }");
    okButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; padding: 10px; border: none; font-size: 14px; }");
    createNewPlaylistButton->setStyleSheet("QPushButton { background-color: #008CBA; color: white; padding: 10px; border: none; font-size: 14px; }");
    setStyleSheet("QDialog { background-color: #f4f4f4; color: white; }");
}

bool PlaylistSelectionDialog::isNewPlaylistSelected() const {
    return createNewPlaylistSelected;
}

QString PlaylistSelectionDialog::selectedPlaylist() const {
    return createNewPlaylistSelected ? newPlaylistLineEdit->text() : selectedPlaylistName;
}

void PlaylistSelectionDialog::acceptSelection() {
    selectedPlaylistName = playlistComboBox->currentText();
    createNewPlaylistSelected = false;
    accept();
}

void PlaylistSelectionDialog::createNewPlaylist() {
    selectedPlaylistName = newPlaylistLineEdit->text();
    createNewPlaylistSelected = true;
    accept();
}

