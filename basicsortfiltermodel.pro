QT += widgets
requires(qtConfig(combobox))

HEADERS     = window.h \
    extra_functions.h \
    teamInfo.h
SOURCES     = main.cpp \
              createDataSubset.cpp \
              teamInfo.cpp \
              window.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/basicsortfiltermodel
INSTALLS += target

DISTFILES += \
    nfl.csv

FORMS += \
    mainwindow.ui
