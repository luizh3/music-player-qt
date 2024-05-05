#include "musicmodel.h"

MusicModel::MusicModel() :
    _sourceImage(""),
    _nameMusic(""),
    _artist(""),
    _album(""),
    _release(""),
    _genre(""),
    _sourceMusic(""){ }

const QString &MusicModel::sourceImage() const {
    return _sourceImage;
}

void MusicModel::setSourceImage(const QString &newSourceImage) {
    if (_sourceImage == newSourceImage)
        return;
    _sourceImage = newSourceImage;
    emit sourceImageChanged();
}

const QString &MusicModel::nameMusic() const {
    return _nameMusic;
}

void MusicModel::setNameMusic(const QString &newNameMusic) {
    if (_nameMusic == newNameMusic)
        return;
    _nameMusic = newNameMusic;
    emit nameMusicChanged();
}

const QString &MusicModel::artist() const {
    return _artist;
}

void MusicModel::setArtist(const QString &newArtist) {
    if (_artist == newArtist)
        return;
    _artist = newArtist;
    emit artistChanged();
}

const QString &MusicModel::album() const {
    return _album;
}

void MusicModel::setAlbum(const QString &newAlbum) {
    if (_album == newAlbum)
        return;
    _album = newAlbum;
    emit albumChanged();
}

const QString &MusicModel::release() const {
    return _release;
}

void MusicModel::setRelease(const QString &newRelease) {
    if (_release == newRelease)
        return;
    _release = newRelease;
    emit releaseChanged();
}

const QString &MusicModel::genre() const {
    return _genre;
}

void MusicModel::setGenre(const QString &newGenre) {
    if (_genre == newGenre)
        return;
    _genre = newGenre;
    emit genreChanged();
}

const QString &MusicModel::sourceMusic() const {
    return _sourceMusic;
}

void MusicModel::setSourceMusic(const QString &newSourceMusic) {
    if (_sourceMusic == newSourceMusic)
        return;
    _sourceMusic = newSourceMusic;
    emit sourceMusicChanged();
}

