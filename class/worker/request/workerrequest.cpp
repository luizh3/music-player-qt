#include "workerrequest.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QTimer>

#include <openssl/aes.h>

WorkerRequest::WorkerRequest( QObject* parent ) :
    QObject( parent ) {

    connect( &manager, &QNetworkAccessManager::authenticationRequired, this, &WorkerRequest::authenticationRequired );
    connect( &manager, &QNetworkAccessManager::encrypted, this, &WorkerRequest::encrypted );
    connect( &manager, &QNetworkAccessManager::networkAccessibleChanged, this, &WorkerRequest::networkAccessibleChanged );
    connect( &manager, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &WorkerRequest::preSharedKeyAuthenticationRequired );
    connect( &manager, &QNetworkAccessManager::proxyAuthenticationRequired, this, &WorkerRequest::proxyAuthenticationRequired );
    connect( &manager, &QNetworkAccessManager::sslErrors, this, &WorkerRequest::sslErrors );
}


void WorkerRequest::post( QString location, QByteArray data ) {

    qInfo() << "Posting server ...";
    QNetworkRequest request = QNetworkRequest( QUrl( location ) );
    request.setHeader( QNetworkRequest::ContentTypeHeader, "application/json" );
    QNetworkReply* reply = manager.post( request, data );
    connect( reply, &QNetworkReply::readyRead, this, &WorkerRequest::readyRead );

}

void WorkerRequest::readyRead() {
    qInfo() << "readyRead";
    reply  = qobject_cast<QNetworkReply*>( sender() );
    QByteArray array = reply->readAll();
    if( reply ) qInfo() << array;
}

void WorkerRequest::authenticationRequired( QNetworkReply* reply, QAuthenticator* authenticator ) {
    Q_UNUSED( reply );
    Q_UNUSED( authenticator );
    qInfo() << "authenticationRequired";

}

void WorkerRequest::encrypted( QNetworkReply* reply ) {
    Q_UNUSED( reply );
    qInfo() << "encrypted";
}

void WorkerRequest::finished( QNetworkReply* reply ) {
    Q_UNUSED( reply );
    qInfo() << "finished";
}

void WorkerRequest::networkAccessibleChanged( QNetworkAccessManager::NetworkAccessibility acessible ) {
    Q_UNUSED( acessible );
    qInfo() << "networkAccessibleChanged";
}

void WorkerRequest::preSharedKeyAuthenticationRequired( QNetworkReply* reply, QSslPreSharedKeyAuthenticator* authenticator ) {
    Q_UNUSED( authenticator );
    Q_UNUSED( reply );
    qInfo() << "preSharedKeyAuthenticationRequired";
}

void WorkerRequest::proxyAuthenticationRequired( const QNetworkProxy& proxy, QAuthenticator* authenticator ) {
    Q_UNUSED( proxy );
    Q_UNUSED( authenticator );
    qInfo() << "proxyAuthenticationRequired";
}

void WorkerRequest::sslErrors( QNetworkReply* reply, const QList<QSslError>& errors ) {
    Q_UNUSED( reply );
    Q_UNUSED( errors );
    qInfo() << "sslErrors";
}

HttpStatusEnum WorkerRequest::requestStatus( int timeout ) {

    QTimer timer;
    timer.setSingleShot( true );

    QEventLoop loop;
    QObject::connect( &timer, &QTimer::timeout, &loop, &QEventLoop::quit );
    QObject::connect( reply, &QNetworkReply::finished, &loop, &QEventLoop::quit );
    timer.start( timeout );
    loop.exec();

    if( timer.isActive() ) {
        timer.stop();
        if( reply->error() > 0 ) {
            qInfo() << "WorkerRequest::requestStatus Erro Request";
            return HttpStatusEnum::NOT_FOUND;
        } else {

            int status = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt();
            if ( status >= 200 && status < 300 ) {
                qInfo() << "WorkerRequest::requestStatus Sucess";
                return HttpStatusEnum::SUCCESS;
            }
        }
    } else {

        qInfo() << "WorkerRequest::requestStatus timeout";

        QObject::disconnect( reply, &QNetworkReply::finished, &loop, &QEventLoop::quit );
        reply->abort();

        return HttpStatusEnum::TIMEOUT_ERROR;
    }

    return HttpStatusEnum::NOT_FOUND;
}

// TODO implementar
// request.setHeader( QNetworkRequest::ContentTypeHeader, "application/json" );
// request.setRawHeader("Authorization", "Bearer BQAwKIAtEZhY7dmSWPLqlj-35sbzYvpfPFAV-dEHaURhA2XpgwJY5vUH8tuWpK-l8Rx-vZzHXc5A36XGYOp7dlGaXP69B0kXOM5FiRi0CL06CjNj3kJ1jVlrFnA8bDfYU2juPKQPG-P7NjyeWj18XCtmlaCPXKg6MgQ");

