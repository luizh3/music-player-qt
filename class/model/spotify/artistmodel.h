#ifndef ARTISTMODEL_H
#define ARTISTMODEL_H

#include <QObject>

class ArtistModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString href READ href WRITE setHref NOTIFY hrefChanged )
    Q_PROPERTY( QString idArtist READ idArtist WRITE setIdArtist NOTIFY idArtistChanged )
    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY( QString uri READ uri WRITE setUri NOTIFY uriChanged )
public:
    ArtistModel();
    const QString &href() const;
    void setHref(const QString &newHref);

    const QString &idArtist() const;
    void setIdArtist(const QString &newIdArtist);

    const QString &name() const;
    void setName(const QString &newName);

    const QString &uri() const;
    void setUri(const QString &newUri);

signals:
    void hrefChanged();
    void idArtistChanged();
    void nameChanged();
    void uriChanged();

private:
   QString _href;
   QString _idArtist;
   QString _name;
   QString _uri;
};

#endif // ARTISTMODEL_H
