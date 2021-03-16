QT += widgets
requires(qtConfig(combobox))

HEADERS     = window.h \
    extra_functions.h \
    login.h \
    team.h
SOURCES     = main.cpp \
              addTeam.cpp \
              createTeamModel.cpp \
              login.cpp \
              team.cpp \
              window.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/basicsortfiltermodel
INSTALLS += target

DISTFILES += \
    nfl.csv

FORMS +=




