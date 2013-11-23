#-------------------------------------------------
#
# Project created by QtCreator 2013-11-08T13:44:11
#
#-------------------------------------------------

QT       -= core gui

TARGET = bigint
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    BigUnsignedInABase.cc \
    BigUnsigned.cc \
    BigIntegerUtils.cc \
    BigIntegerAlgorithms.cc \
    BigInteger.cc

HEADERS += \
    NumberlikeArray.hh \
    BigUnsignedInABase.hh \
    BigUnsigned.hh \
    BigIntegerUtils.hh \
    BigIntegerLibrary.hh \
    BigIntegerAlgorithms.hh \
    BigInteger.hh
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
