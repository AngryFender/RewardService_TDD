QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_rewardstesting.cpp \
    mock_eligibilityservice.cpp \
    rewardservice.cpp

HEADERS += \
    mock_eligibilityservice.h \
    rewardservice.h
