#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include <class/api/spotify/apispotify.h>
#include <QQuickWindow>

#include "class/listsongscontroller.h"
#include "class/musiccontroller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QQuickStyle::setStyle( "Material" );

//    qputenv("QT_QPA_PLATFORM", "webgl:port=8998");

    QGuiApplication app(argc, argv);

//    QQuickWindow::setSceneGraphBackend(QSGRendererInterface::Software);
    QQuickWindow().setPersistentOpenGLContext(true);

    app.setOrganizationName("adasdasd");
    app.setOrganizationDomain("adasdasd");
    QCoreApplication::setApplicationName( "Star Runner" );

    qmlRegisterType<ListSongsController>( "br.com.listsongscontroller", 1, 0, "ListSongsController" );
    qmlRegisterType<MusicController>( "br.com.musiccontroller", 1, 0, "MusicController" );

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    ApiSpotify();

    return app.exec();
}
