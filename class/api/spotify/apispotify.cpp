#include "apispotify.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

#include <class/worker/request/workerrequest.h>
#include <class/response/spotify/album/albumstubresponse.h>

// TODO hoje no windows não estou conseguindo utilizar request https por conta do openssl.
// Como solução temporaria criei uma aplicação em node.js que realizara as request https, sendo assim consultarei ela por http
// Essa aplicação retornara o json puro para isso já ser trato aqui.

namespace {
// constexpr const char* API_KEY = "";
 constexpr const char* URL_ALBUM = "http://localhost:4555/albuns";
}

QList<AlbumModel*> ApiSpotify::albums() const {

    QList<AlbumModel*> albums = {};

    AlbumStubResponse* response = WorkerRequest().get<AlbumStubResponse>( URL_ALBUM );

    if( response && response->status() == HttpStatusEnum::SUCCESS ){
        albums = response->albums();
    }

    delete response;

    return albums;
}
