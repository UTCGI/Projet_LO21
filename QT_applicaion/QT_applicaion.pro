QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Carte_Monument.cpp \
    buildfonctions.cpp \
    create_database.cpp \
    dialog.cpp \
    effets_monuments.cpp \
    etablissement.cpp \
    etablissements_speciaux.cpp \
    jeu.cpp \
    joueur.cpp \
    main.cpp \
    miniville.cpp \
    monument.cpp \
    partie.cpp \
    pile_etablissement.cpp \
    pioche.cpp \
    principal.cpp \
    reserve.cpp \
    sqlite3.c

HEADERS += \
    Carte_Monument.h \
    buildfonctions.h \
    create_database.h \
    dialog.h \
    effets_monuments.h \
    etablissement.h \
    etablissements_speciaux.h \
    jeu.h \
    joueur.h \
    miniville.h \
    monument.h \
    partie.h \
    pile_etablissement.h \
    pioche.h \
    principal.h \
    reserve.h \
    sqlite3.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CMakeLists.txt \
    Final.sql
