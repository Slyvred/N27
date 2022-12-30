SOURCES += \
    ../classes/account.cpp \
    ../classes/agency.cpp \
    ../classes/user.cpp \
    main.cpp \
    mainapp.cpp

HEADERS += \
    ../classes/account.hpp \
    ../classes/agency.hpp \
    ../classes/json.hpp \
    ../classes/socket.hpp \
    ../classes/user.hpp \
    mainapp.h \
    socket_thread.h

QT += widgets

FORMS += \
    mainapp.ui

DISTFILES += \
    build/client/data/A1655035746.json \
    build/client/data/T1655035746.json \
    build/client/data/U1655035746.json \
    data/A1655035746.json \
    data/T1655035746.json \
    data/U1655035746.json
