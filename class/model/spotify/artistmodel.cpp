#include "artistmodel.h"

ArtistModel::ArtistModel() :
     _href(""),
     _idArtist(""),
     _name(""),
     _uri(""){}

const QString &ArtistModel::href() const
{
    return _href;
}

void ArtistModel::setHref(const QString &newHref)
{
    if (_href == newHref)
        return;
    _href = newHref;
    emit hrefChanged();
}

const QString &ArtistModel::idArtist() const
{
    return _idArtist;
}

void ArtistModel::setIdArtist(const QString &newIdArtist)
{
    if (_idArtist == newIdArtist)
        return;
    _idArtist = newIdArtist;
    emit idArtistChanged();
}

const QString &ArtistModel::name() const
{
    return _name;
}

void ArtistModel::setName(const QString &newName)
{
    if (_name == newName)
        return;
    _name = newName;
    emit nameChanged();
}

const QString &ArtistModel::uri() const
{
    return _uri;
}

void ArtistModel::setUri(const QString &newUri)
{
    if (_uri == newUri)
        return;
    _uri = newUri;
    emit uriChanged();
}
