#include "trackmodel.h"

TrackModel::TrackModel() :
    _durationMs(0),
    _href(""),
    _idTrack(""),
    _name(""),
    _previewUrl(""),
    _uri(""),
    _artists({}){}

int TrackModel::durationMs() const
{
    return _durationMs;
}

void TrackModel::setDurationMs(int newDurationMs)
{
    if (_durationMs == newDurationMs)
        return;
    _durationMs = newDurationMs;
    emit durationMsChanged();
}

const QString &TrackModel::idTrack() const
{
    return _idTrack;
}

void TrackModel::setIdTrack(const QString &newIdTrack)
{
    if (_idTrack == newIdTrack)
        return;
    _idTrack = newIdTrack;
    emit idTrackChanged();
}

const QString &TrackModel::name() const
{
    return _name;
}

void TrackModel::setName(const QString &newName)
{
    if (_name == newName)
        return;
    _name = newName;
    emit nameChanged();
}

const QString &TrackModel::previewUrl() const
{
    return _previewUrl;
}

void TrackModel::setPreviewUrl(const QString &newPreviewUrl)
{
    if (_previewUrl == newPreviewUrl)
        return;
    _previewUrl = newPreviewUrl;
    emit previewUrlChanged();
}

const QString &TrackModel::uri() const
{
    return _uri;
}

void TrackModel::setUri(const QString &newUri)
{
    if (_uri == newUri)
        return;
    _uri = newUri;
    emit uriChanged();
}

const QList<ArtistModel *> &TrackModel::artists() const
{
    return _artists;
}

void TrackModel::setArtists(const QList<ArtistModel *> &newArtists)
{
    if (_artists == newArtists)
        return;
    _artists = newArtists;
    emit artistsChanged();
}

const QString &TrackModel::href() const
{
    return _href;
}

void TrackModel::setHref(const QString &newHref)
{
    if (_href == newHref)
        return;
    _href = newHref;
    emit hrefChanged();
}
