#include "musicintegracaolocal.h"

#include <QDebug>

MusicIntegracaoLocal::MusicIntegracaoLocal():
    _songs({}) {
    initializeConstSongs();
}

QList<MusicModel*> MusicIntegracaoLocal::songs() const{
    return _songs;
}

bool MusicIntegracaoLocal::addSong( const QString& identifier ) {

    MusicModel* musicModel = new MusicModel();

    musicModel->setSourceImage( "/img/music/unknow.jpg");
    musicModel->setNameMusic(decomposeNameMusic(identifier));
    musicModel->setAlbum("unknown");
    musicModel->setArtist("unknown");
    musicModel->setRelease("unknown");
    musicModel->setGenre("unknown");
    musicModel->setSourceMusic(identifier);

    _songs.append( musicModel );

    return true;
}

QString MusicIntegracaoLocal::decomposeNameMusic( QString url ) const {
    qDebug() << " ListSongsController::decomposeNameMusic [URL]" << url;

    QStringList listUrl = url.split("/");
    QString nameMusic = listUrl.last().replace(".mp3","");
    nameMusic = nameMusic.replace(0,1, nameMusic[0].toUpper());

    qDebug() << " ListSongsController::decomposeNameMusic [NAME_MUSIC]" << nameMusic;

    return nameMusic;
}

void MusicIntegracaoLocal::initializeConstSongs(){

    // TODO Remove this metodo when implemented a database

    MusicModel* musicModel = new MusicModel();

    musicModel->setSourceImage( "/img/music/MoonRiver.jpg");
    musicModel->setNameMusic("Moon River");
    musicModel->setAlbum("Moon River");
    musicModel->setArtist("Henry Mancini");
    musicModel->setRelease("1961");
    musicModel->setGenre("Música pop");
    musicModel->setSourceMusic("/music/MoonRiver.mp3");

    MusicModel* musicModel1 = new MusicModel();

    musicModel1->setSourceImage( "/img/music/RealHero.jpg");
    musicModel1->setNameMusic("A Real Hero");
    musicModel1->setAlbum("Innerworld (Deluxe Edition)");
    musicModel1->setArtist("Electric Youth");
    musicModel1->setRelease("2010");
    musicModel1->setGenre("Dance/Eletrónica");
    musicModel1->setSourceMusic("/music/ARealHero.mp3");

    _songs.append( musicModel );
    _songs.append( musicModel1 );

}
