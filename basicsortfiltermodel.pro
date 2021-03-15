QT += widgets
requires(qtConfig(combobox))

HEADERS     = window.h \
    extra_functions.h \
    team.h
SOURCES     = main.cpp \
              addTeam.cpp \
              createTeamModel.cpp \
              team.cpp \
              window.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/basicsortfiltermodel
INSTALLS += target

DISTFILES += \
    nfl.csv

FORMS += \
    mainwindow.ui

