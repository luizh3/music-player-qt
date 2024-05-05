#include "artiststubresponse.h"

#include <QJsonArray>

ArtistStubResponse::ArtistStubResponse() {}

QList<ArtistModel*> ArtistStubResponse::fromJson( const QJsonValue& value ) const {

    QList<ArtistModel*> listArtists = {};

    QJsonArray artistsJson = value.toArray();

    for( QJsonValue&& currentArtistJson : artistsJson ){

        ArtistModel* artistModel = new ArtistModel();

        artistModel->setIdArtist( currentArtistJson["id"].toString() );
        artistModel->setName( currentArtistJson["name"].toString() );
        artistModel->setHref( currentArtistJson["href"].toString() );
        artistModel->setUri( currentArtistJson["uri"].toString() );

        listArtists.append( artistModel );

    }

    return listArtists;

}

