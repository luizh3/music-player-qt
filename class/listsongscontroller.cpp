#include "listsongscontroller.h"

#include <QDebug>

#include "helper/converter.h"
#include "model/spotify/albummodel.h"

ListSongsController::ListSongsController() :
    _listSongsDelegate( ListSongsDelegate( TipoIntegracaoEnum::LOCAL ) ),
    _songs({}) {
}

QList<QObject*> ListSongsController::albums() {
    QList<QObject*> albums = Converter::toObject( _listSongsDelegate.albums() );
    return albums;
}

QList<QObject*> ListSongsController::songs() {

    qInfo() << "ListSongsController::songs";

//    std::for_each( _songs.begin(), _songs.end(), []( MusicModel* music ){
//        delete music;
//    } );

    _songs = _listSongsDelegate.songs();

    qInfo() << "ListSongsController::songs";

    return Converter::toObject( _songs );
}

void ListSongsController::addSong( const QString& identifier ) const {

    qInfo() << "ListSongsController::addSong";

    _listSongsDelegate.addSong( identifier );

    emit songsChanged();

    qInfo() << "ListSongsController::addSong";
}

