#ifndef WORKERREQUEST_H
#define WORKERREQUEST_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QNetworkProxy>

#include <class/response/bodystubresponse.h>

#include "httpstatusenum.h"

class WorkerRequest : public QObject {
    Q_OBJECT
public:
    explicit WorkerRequest( QObject* parent = nullptr );
    void post( QString location, QByteArray data );

    template<class StubResponse>
    StubResponse* get( const QString& url, const int& timeout = 5000 ){
        qInfo() << "WorkerRequest::get server ...";

        QByteArray array = {};

        QNetworkRequest request = QNetworkRequest( QUrl( url ) );
        request.setSslConfiguration(QSslConfiguration::defaultConfiguration());

        reply = manager.get( request );

        QObject::connect( reply, &QNetworkReply::readyRead, this, [&]() {
            reply = qobject_cast<QNetworkReply*>( sender() );
            array = reply->readAll();
            if( reply ) qInfo() << array;
        } );

        HttpStatusEnum status = requestStatus( timeout );

        qInfo() << "WorkerRequest::get [RESPONSE]" << array;

        return toResponse<StubResponse>(array, status );
    };

private slots:
    void readyRead();
    void authenticationRequired( QNetworkReply* reply, QAuthenticator* authenticator );
    void encrypted( QNetworkReply* reply );
    void finished( QNetworkReply* reply );
    void networkAccessibleChanged( QNetworkAccessManager::NetworkAccessibility acessible );
    void preSharedKeyAuthenticationRequired( QNetworkReply* reply, QSslPreSharedKeyAuthenticator* authenticator );
    void proxyAuthenticationRequired( const QNetworkProxy& proxy, QAuthenticator* authenticator );
    void sslErrors( QNetworkReply* reply, const QList<QSslError>& errors );

    HttpStatusEnum requestStatus( int timeout );

private:

    template<class StubResponse>
    StubResponse* toResponse( QByteArray array, const HttpStatusEnum& status ) const {

        StubResponse* response = new StubResponse();
        QJsonDocument document = QJsonDocument::fromJson( array );

        BodyStubResponse* bodyStub = static_cast<BodyStubResponse*>( response );
        bodyStub->fromJson( document );
        bodyStub->setStatus( status );

        return response;
    };

    QNetworkAccessManager manager;
    QNetworkReply* reply;
};

#endif // WORKERREQUEST_H
