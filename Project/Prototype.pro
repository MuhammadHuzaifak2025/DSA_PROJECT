T += core gui multimedia
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data_structures.cpp \
    admin.cpp \
    admin2.cpp \
    main.cpp \
    mainwindow.cpp \
    newuser.cpp \
    playlistselectiondialog.cpp \
    song.cpp \
    spotify.cpp \
    stack.cpp \
    user.cpp

HEADERS += \
    ButtonCard.h \
    Data_structures.h \
    SoundWaves.h \
    admin.h \
    admin2.h \
    mainwindow.h \
    newuser.h \
    playlistselectiondialog.h \
    song.h \
    spotify.h \
    stack.h \
    user.h

FORMS += \
    admin.ui \
    admin2.ui \
    mainwindow.ui \
    newuser.ui \
    spotify.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    C:/Users/devda/Downloads/testsong.mp3 \
    images/LoginPage.png
