#include "listsongsdelegate.h"

#include <QDebug>

#include "../factory/musicintegracaofactory.h"

ListSongsDelegate::ListSongsDelegate( const TipoIntegracaoEnum& tpIntegracao ) :
    _musicIntegracao( MusicIntegracaoFactory::build( tpIntegracao ) ) {
}

QList<MusicModel*> ListSongsDelegate::songs() const {
    qInfo() << "ListSongsDelegate::songs";
    const QList<MusicModel*> songs = _musicIntegracao->songs();
    qInfo() << "ListSongsDelegate::songs [SONGS_SIZE]" << songs.size();
    return songs;
}

QList<AlbumModel*> ListSongsDelegate::albums() const {
    qInfo() << "ListSongsDelegate::albums";
    QList<AlbumModel*> albums = _musicIntegracao->albums();
    qInfo() << "ListSongsDelegate::albums [ALBUMS_SIZE]" << albums.size();
    return albums;
}

void ListSongsDelegate::addSong( const QString& identifier ) const {
    qInfo() << "ListSongsDelegate::addSong [DS_IDENTIFIER]" << identifier;
    _musicIntegracao->addSong( identifier );
    qInfo() << "ListSongsDelegate::addSong";
}
