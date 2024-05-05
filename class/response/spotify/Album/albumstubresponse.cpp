#include "albumstubresponse.h"

#include <QDebug>

#include <QJsonObject>
#include <QJsonArray>

#include <class/music/musicmodel.h>

#include <class/response/spotify/artist/artiststubresponse.h>
#include <class/response/spotify/track/trackstubresponse.h>

AlbumStubResponse::AlbumStubResponse() :
    _album( {} ){}

void AlbumStubResponse::fromJson( QJsonDocument& document ) {

    QList<AlbumModel*> listAlbums = {};

    QJsonArray albumsJson = document.object()["albums"].toArray();

    for( QJsonValue&& currentAlbumJson : albumsJson ){

      AlbumModel* albumModel = new AlbumModel();

      albumModel->setPopularity( currentAlbumJson["popularity"].toDouble() );
      albumModel->setIdAlbum( currentAlbumJson["id"].toString() );
      albumModel->setName( currentAlbumJson["name"].toString() );
      albumModel->setReleaseDate( QDateTime::fromString( currentAlbumJson["release_date"].toString(), "yyyy-mm-dd" ) );
      albumModel->setUrlImage( currentAlbumJson["images"].toArray().first()["url"].toString() );
      albumModel->setArtists( ArtistStubResponse().fromJson( currentAlbumJson["artists"] ) );

      QList<TrackModel*> tracks = TrackStubResponse().fromJson( currentAlbumJson["tracks"]["items"] );
      QList<MusicModel*> musics = tracksToMusics( tracks, albumModel->urlImage() );

      albumModel->setTracks( musics );

      listAlbums.append( albumModel );

    }

    _album.append( listAlbums );
}

QList<MusicModel*> AlbumStubResponse::tracksToMusics( const QList<TrackModel*> tracks, const QString& urlImage ) const {

    QList<MusicModel*> musics = {};

    std::for_each( tracks.begin(), tracks.end(), [&]( TrackModel* track ){

        MusicModel* music = new MusicModel();
        music->setNameMusic( track->name() );
        music->setSourceMusic( track->previewUrl() );
        music->setSourceImage( urlImage );
        music->setArtist( track->artists()[0]->name() );

        musics.append( music );
        // TODO deletar os artistas da track
        delete( track );
    });

    return musics;
}

QList<AlbumModel*> AlbumStubResponse::albums() const {
    return _album;
}

