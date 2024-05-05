#include "albummodel.h"

#include "../../helper/converter.h"

AlbumModel::AlbumModel() :
    _popularity(0),
    _totalTracks(0),
    _idAlbum(""),
    _urlImage(""),
    _name(""),
    _releaseDate(QDateTime()),
    _artists({}),
    _tracks({}){}

double AlbumModel::popularity() const {
    return _popularity;
}

void AlbumModel::setPopularity(double newPopularity) {
    if ( qFuzzyCompare(_popularity, newPopularity) ){
        return;
    }
    _popularity = newPopularity;
    emit popularityChanged();
}

int AlbumModel::totalTracks() const {
    return _totalTracks;
}

void AlbumModel::setTotalTracks(int newTotalTracks) {
    if (_totalTracks == newTotalTracks)
        return;
    _totalTracks = newTotalTracks;
    emit totalTracksChanged();
}

const QString &AlbumModel::idAlbum() const {
    return _idAlbum;
}

void AlbumModel::setIdAlbum(const QString &newIdAlbum) {
    if (_idAlbum == newIdAlbum)
        return;
    _idAlbum = newIdAlbum;
    emit idAlbumChanged();
}

const QString &AlbumModel::urlImage() const {
    return _urlImage;
}

void AlbumModel::setUrlImage(const QString &newUrlImage) {
    if (_urlImage == newUrlImage)
        return;
    _urlImage = newUrlImage;
    emit urlImageChanged();
}

const QString &AlbumModel::name() const {
    return _name;
}

void AlbumModel::setName(const QString &newName) {
    if (_name == newName)
        return;
    _name = newName;
    emit nameChanged();
}

const QDateTime &AlbumModel::releaseDate() const {
    return _releaseDate;
}

void AlbumModel::setReleaseDate(const QDateTime &newReleaseDate) {
    if ( _releaseDate == newReleaseDate ){
        return;
     }
    _releaseDate = newReleaseDate;
    emit releaseDateChanged();
}

const QList<QObject*> AlbumModel::artists() const {
    return Converter::toObject( _artists );
}

void AlbumModel::setArtists( const QList<ArtistModel*>& newArtists ) {
    if ( _artists == newArtists ){
        return;
    }
    _artists = newArtists;
    emit artistsChanged();
}

const QList<QObject*> AlbumModel::tracks() const {
    return Converter::toObject( _tracks );
}

void AlbumModel::setTracks( const QList<MusicModel*>& newTracks ) {
    if ( _tracks == newTracks ){
        return;
    }
    _tracks = newTracks;
    emit tracksChanged();
}
