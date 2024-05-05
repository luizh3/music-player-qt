#include "musicintegracaospotify.h"

#include <QDebug>

#include <class/api/spotify/apispotify.h>

QList<MusicModel*> MusicIntegracaoSpotify::songs() const {
    return {};
}

bool MusicIntegracaoSpotify::addSong( const QString& /*indentifier*/ ){
    return false;
}

QList<AlbumModel*> MusicIntegracaoSpotify::albums() const {
    qInfo() << "MusicIntegracaoSpotify::albums";
    QList<AlbumModel*> albums = ApiSpotify().albums();
    qInfo() << "MusicIntegracaoSpotify::albums [ALBUMS_SIZE]" << albums.size();
    return albums;
}
