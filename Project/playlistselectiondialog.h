#ifndef PLAYLISTSELECTIONDIALOG_H
#define PLAYLISTSELECTIONDIALOG_H

#include <QtWidgets>

class PlaylistSelectionDialog : public QDialog {
    Q_OBJECT

public:
    PlaylistSelectionDialog(const QStringList &playlistNames, QWidget *parent = nullptr);

    QString selectedPlaylist() const;
    bool isNewPlaylistSelected() const;

    QString getName(){
        return newPlaylistLineEdit->text();
    }


private slots:
    void acceptSelection();
    void createNewPlaylist();

private:
    QComboBox *playlistComboBox;
    QLineEdit *newPlaylistLineEdit;
    QPushButton *okButton;
    QString selectedPlaylistName;
    bool createNewPlaylistSelected;
};


#endif // PLAYLISTSELECTIONDIALOG_H
