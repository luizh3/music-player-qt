#include "trackstubresponse.h"

#include <QJsonArray>

#include <class/response/spotify/artist/artiststubresponse.h>

QList<TrackModel*> TrackStubResponse::fromJson( const QJsonValue& value ) const {

    QList<TrackModel*> listTracks = {};

    QJsonArray tracksJson = value.toArray();

    for( QJsonValue&& currentTrackJson : tracksJson ){

        TrackModel* trackModel = new TrackModel();

        trackModel->setArtists( ArtistStubResponse().fromJson( currentTrackJson["artists"] ) );
        trackModel->setDurationMs( currentTrackJson["duration_ms"].toInt() );
        trackModel->setHref( currentTrackJson["href"].toString() );
        trackModel->setName( currentTrackJson["name"].toString() );
        trackModel->setUri( currentTrackJson["uri"].toString() );
        trackModel->setIdTrack( currentTrackJson["id"].toString() );
        trackModel->setPreviewUrl( currentTrackJson["preview_url"].toString() );

        listTracks.append( trackModel );

    }

    return listTracks;

}
