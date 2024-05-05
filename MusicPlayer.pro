QT += quick quickcontrols2

CONFIG += c++11

LIBS += -LC:/OpenSSL-Win64/lib -llibcrypto

INCLUDEPATH += C:/OpenSSL-Win64/include

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        class/api/spotify/apispotify.cpp \
        class/delegate/listsongsdelegate.cpp \
        class/factory/musicintegracaofactory.cpp \
        class/integracao/local/musicintegracaolocal.cpp \
        class/integracao/musicintegracao.cpp \
        class/integracao/spotify/musicintegracaospotify.cpp \
        class/listsongscontroller.cpp \
        class/model/spotify/albummodel.cpp \
        class/model/spotify/artistmodel.cpp \
        class/model/spotify/imagemodel.cpp \
        class/model/spotify/trackmodel.cpp \
        class/music/musicmodel.cpp \
        class/musiccontroller.cpp \
        class/response/bodystubresponse.cpp \
        class/response/spotify/album/albumstubresponse.cpp \
        class/response/spotify/artist/artiststubresponse.cpp \
        class/response/spotify/track/trackstubresponse.cpp \
        class/worker/request/workerrequest.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    class/api/spotify/apispotify.h \
    class/delegate/listsongsdelegate.h \
    class/factory/musicintegracaofactory.h \
    class/helper/converter.h \
    class/integracao/local/musicintegracaolocal.h \
    class/integracao/musicintegracao.h \
    class/integracao/spotify/musicintegracaospotify.h \
    class/listsongscontroller.h \
    class/model/spotify/albummodel.h \
    class/model/spotify/artistmodel.h \
    class/model/spotify/imagemodel.h \
    class/model/spotify/trackmodel.h \
    class/model/tipointegracaoenum.h \
    class/music/musicmodel.h \
    class/musiccontroller.h \
    class/response/bodystubresponse.h \
    class/response/spotify/album/albumstubresponse.h \
    class/response/spotify/artist/artiststubresponse.h \
    class/response/spotify/track/trackstubresponse.h \
    class/worker/request/httpstatusenum.h \
    class/worker/request/workerrequest.h
