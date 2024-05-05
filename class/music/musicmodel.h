#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include <QObject>

class MusicModel : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString sourceImage READ sourceImage WRITE setSourceImage NOTIFY sourceImageChanged)
    Q_PROPERTY(QString nameMusic READ nameMusic WRITE setNameMusic NOTIFY nameMusicChanged)
    Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(QString album READ album WRITE setAlbum NOTIFY albumChanged)
    Q_PROPERTY(QString release READ release WRITE setRelease NOTIFY releaseChanged)
    Q_PROPERTY(QString genre READ genre WRITE setGenre NOTIFY genreChanged)
    Q_PROPERTY(QString sourceMusic READ sourceMusic WRITE setSourceMusic NOTIFY sourceMusicChanged)

public:

    MusicModel();

    const QString &sourceImage() const;
    void setSourceImage(const QString &newSourceImage);

    const QString &nameMusic() const;
    void setNameMusic(const QString &newNameMusic);

    const QString &artist() const;
    void setArtist(const QString &newArtist);

    const QString &album() const;
    void setAlbum(const QString &newAlbum);

    const QString &release() const;
    void setRelease(const QString &newRelease);

    const QString &genre() const;
    void setGenre(const QString &newGenre);

    const QString &sourceMusic() const;
    void setSourceMusic(const QString &newSourceMusic);

signals:
    void sourceImageChanged();
    void nameMusicChanged();
    void artistChanged();
    void albumChanged();
    void releaseChanged();
    void genreChanged();
    void sourceMusicChanged();

private:
    QString _sourceImage;
    QString _nameMusic;
    QString _artist;
    QString _album;
    QString _release;
    QString _genre;
    QString _sourceMusic;
};

#endif // MUSICMODEL_H
