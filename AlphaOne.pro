######################################################################
# Automatically generated by qmake (3.1) Fri Jun 19 19:11:45 2020
######################################################################

TEMPLATE = app
TARGET = AlphaOne
INCLUDEPATH += .
QT += widgets
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += alfiere.h \
           Arrocco_Exc.h \
           cavallo.h \
           chessbutton.h \
           controller.h \
           EnPassant_Exc.h \
           Mossa_illegale.h \
           Mossa_Imposs.h \
           mosseacroce.h \
           mosseax.h \
           pedone.h \
           pezzi.h \
           prombutton.h \
           Promozione.h \
           re.h \
           regina.h \
           scacchi.h \
           scacchiera.h \
           torre.h \
           vector.h \
           winner.h
SOURCES += alfiere.cpp \
           cavallo.cpp \
           chessbutton.cpp \
           controller.cpp \
           main.cpp \
           mosseacroce.cpp \
           mosseax.cpp \
           pedone.cpp \
           pezzi.cpp \
           prombutton.cpp \
           re.cpp \
           regina.cpp \
           scacchi.cpp \
           scacchiera.cpp \
           torre.cpp \
           vector.cpp
RESOURCES += resources.qrc