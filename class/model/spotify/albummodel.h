#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QList>
#include <QDateTime>

#include <class/music/musicmodel.h>

#include "artistmodel.h"

class AlbumModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( double popularity READ popularity WRITE setPopularity NOTIFY popularityChanged )
    Q_PROPERTY( int totalTracks READ totalTracks WRITE setTotalTracks NOTIFY totalTracksChanged )
    Q_PROPERTY( QString idAlbum READ idAlbum WRITE setIdAlbum NOTIFY idAlbumChanged )
    Q_PROPERTY( QString urlImage READ urlImage WRITE setUrlImage NOTIFY urlImageChanged )
    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY( QDateTime releaseDate READ releaseDate WRITE setReleaseDate NOTIFY releaseDateChanged )
    Q_PROPERTY( QList<QObject*> artists READ artists NOTIFY artistsChanged )
    Q_PROPERTY( QList<QObject*> tracks READ tracks NOTIFY tracksChanged )
public:
    AlbumModel();

    double popularity() const;
    void setPopularity(double newPopularity);

    int totalTracks() const;
    void setTotalTracks(int newTotalTracks);

    const QString& idAlbum() const;
    void setIdAlbum(const QString &newIdAlbum);

    const QString& urlImage() const;
    void setUrlImage(const QString &newUrlImage);

    const QString& name() const;
    void setName(const QString &newName);

    const QDateTime& releaseDate() const;
    void setReleaseDate(const QDateTime &newReleaseDate);

    const QList<QObject*> artists() const;
    void setArtists(const QList<ArtistModel*>& newArtists);

    const QList<QObject*> tracks() const;
    void setTracks(const QList<MusicModel*>& newTracks);

signals:
    void popularityChanged();
    void totalTracksChanged();
    void idAlbumChanged();
    void urlImageChanged();
    void nameChanged();
    void releaseDateChanged();
    void artistsChanged();
    void tracksChanged();

private:
    double _popularity;
    int _totalTracks;
    QString _idAlbum;
    QString _urlImage;
    QString _name;
    QDateTime _releaseDate;
    QList<ArtistModel*> _artists;
    QList<MusicModel*> _tracks;
};

#endif // ALBUMMODEL_H
