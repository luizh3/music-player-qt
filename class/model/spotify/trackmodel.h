#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QObject>

#include "artistmodel.h"

class TrackModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(int durationMs READ durationMs WRITE setDurationMs NOTIFY durationMsChanged)
    Q_PROPERTY(QString idTrack READ idTrack WRITE setIdTrack NOTIFY idTrackChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString previewUrl READ previewUrl WRITE setPreviewUrl NOTIFY previewUrlChanged)
    Q_PROPERTY(QString uri READ uri WRITE setUri NOTIFY uriChanged)
    Q_PROPERTY(QList<ArtistModel*> artists READ artists WRITE setArtists NOTIFY artistsChanged)
    Q_PROPERTY(QString href READ href WRITE setHref NOTIFY hrefChanged)
public:
    TrackModel();

    int durationMs() const;
    void setDurationMs(int newDurationMs);

    const QString &idTrack() const;
    void setIdTrack(const QString &newIdTrack);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &previewUrl() const;
    void setPreviewUrl(const QString &newPreviewUrl);

    const QString &uri() const;
    void setUri(const QString &newUri);

    const QList<ArtistModel *> &artists() const;
    void setArtists(const QList<ArtistModel *> &newArtists);

    const QString &href() const;
    void setHref(const QString &newHref);

signals:
    void durationMsChanged();
    void idTrackChanged();
    void nameChanged();
    void previewUrlChanged();
    void uriChanged();
    void artistsChanged();

    void hrefChanged();

private:
    int _durationMs;
    QString _href;
    QString _idTrack;
    QString _name;
    QString _previewUrl;
    QString _uri;
    QList<ArtistModel*> _artists;
};

#endif // TRACKMODEL_H
