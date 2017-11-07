QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Документы/OOP/main.cpp \
    ../Документы/OOP/THexagon.cpp \
    ../Документы/OOP/TOctergon.cpp \
    ../Документы/OOP/Tree.cpp \
    ../Документы/OOP/TreeItem.cpp \
    ../Документы/OOP/TTriangle.cpp \
    ../Документы/OOP/IPolygon.cpp

HEADERS += \
    ../Документы/OOP/THexagon.h \
    ../Документы/OOP/TOctergon.h \
    ../Документы/OOP/Tree.h \
    ../Документы/OOP/TreeItem.h \
    ../Документы/OOP/TTriangle.h \
    ../Документы/OOP/IFigure.h \
    ../Документы/OOP/IPolygon.h \
    ../Документы/OOP/TIterator.h
