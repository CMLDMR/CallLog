INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD

HEADERS += \
    $$PWD/item.h

SOURCES += \
    $$PWD/item.cpp


win32 {

contains(QT_ARCH, x86_64) {
    message(mongocxx 3.10.2.0 MinGW 8.1.0 x64 link)
    INCLUDEPATH += C:\mongo\mingw-8.1.0-x64\Release\include\bsoncxx\v_noabi
    DEPENDPATH  += C:\mongo\mingw-8.1.0-x64\Release\include\bsoncxx\v_noabi
    PRE_TARGETDEPS += C:\mongo\mingw-8.1.0-x64\Release\lib\libmongocxx.dll.a
    LIBS        += -LC:\mongo\mingw-8.1.0-x64\Release\lib -lbsoncxx
    mongodll.files = C:\mongo\mingw-8.1.0-x64\Release\bin\libbson-1.0.dll C:\mongo\mingw-8.1.0-x64\Release\bin\libbsoncxx.dll
    mongodll.path  = $$OUT_PWD
    COPIES += mongodll
} else {
    message(mongocxx 3.10.2.0 MinGW 8.1.0 x86 link)
    INCLUDEPATH += C:\mongo\x86\include\bsoncxx\v_noabi
    DEPENDPATH  += C:\mongo\x86\include\bsoncxx\v_noabi
    PRE_TARGETDEPS += C:\mongo\x86\lib\libmongocxx.dll.a
    LIBS        += -LC:\mongo\x86\lib -lbsoncxx
    mongodll.files = C:\mongo\x86\bin\libbson-1.0.dll C:\mongo\x86\bin\libbsoncxx.dll
    mongodll.path  = $$OUT_PWD
    COPIES += mongodll
}
}
unix {

    DISTRIBUTION = $$system(cat /etc/issue | cut -d\' \' -f1)
    contains(DISTRIBUTION, Manjaro) {
        INCLUDEPATH += /usr/include/bsoncxx/v_noabi
        DEPENDPATH  += /usr/include/bsoncxx/v_noabi
    }
    else {
        # Ubuntu
        INCLUDEPATH += /usr/local/include/bsoncxx/v_noabi
        DEPENDPATH  += /usr/local/include/bsoncxx/v_noabi
    }
    LIBS += -lbsoncxx
}
