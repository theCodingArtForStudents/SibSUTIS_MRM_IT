TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgdi32 # Пока нигде, но понадобится для картинок
LIBS += -lcomctl32 # Некоторые виджеты типа WSpinBox

LIBS += -lwininet
LIBS += -luser32
LIBS += -lwinhttp

SOURCES += \
    autorun.cpp \
    ftpconnect.cpp \
    ftpuserdata.cpp \
    httprequest.cpp \
    main.cpp

HEADERS += \
    autorun.h \
    ftpconnect.h \
    ftpuserdata.h \
    httprequest.h
