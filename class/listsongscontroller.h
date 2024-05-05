#ifndef LISTSONGSCONTROLLER_H
#define LISTSONGSCONTROLLER_H

#include <QObject>

#include "music/musicmodel.h"
#include "delegate/listsongsdelegate.h"

class ListSongsController : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> songs READ songs NOTIFY songsChanged)
    Q_PROPERTY(QList<QObject*> albums READ albums NOTIFY albumsChanged)

public:
    ListSongsController();
public slots:
    QList<QObject*> albums();
    QList<QObject*> songs();
    void addSong( const QString& identifier ) const;
signals:
    void songsChanged() const;
    void albumsChanged() const;
private:
    ListSongsDelegate _listSongsDelegate;
    QList<MusicModel*> _songs;
};

#endif // LISTSONGSCONTROLLER_H
