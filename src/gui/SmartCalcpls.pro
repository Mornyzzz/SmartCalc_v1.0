QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# QMAKE_CXXFLAGS += -Wa,-mbig-obj
QMAKE_CXXFLAGS += -W

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../functions/calc.c \
    ../functions/expr_to_lexems.c \
    ../functions/help_funcs.c \
    ../functions/lexems_to_postfix.c \
    ../functions/op_calc.c \
    main.cpp \
    mainwindow.cpp \
    ../data_structures/queue.c \
    ../data_structures/stack.c \

HEADERS += \
    ../smartcalc.h \
    mainwindow.h \
    ../data_structures/queue.h \
    ../data_structures/stack.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
