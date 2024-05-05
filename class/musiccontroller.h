#ifndef MUSICCONTROLLER_H
#define MUSICCONTROLLER_H

#include <QObject>

#include "music/musicmodel.h"

class MusicController : public QObject {
    Q_OBJECT
    Q_PROPERTY( QObject* currentMusic READ currentMusic NOTIFY currentMusicChange )
    Q_PROPERTY( QList<QObject*> musicsQueue READ musicsQueue NOTIFY musicsQueueChanged )
    Q_PROPERTY( QList<QObject*> nextMusics READ nextMusics NOTIFY nextMusicChanged )
public:
    MusicController();

    QList<QObject*> musicsQueue() const;
    QList<QObject*> nextMusics() const;
    QObject* currentMusic() const;

public slots:
    void next();
    void previous();
    void start();

    void addMusicQueue( QObject* object );

signals:
    void currentMusicChange( QObject* music = nullptr ) const;
    void musicsQueueChanged() const;
    void nextMusicChanged() const;

private:
    MusicModel* _currentMusic;
    int _nrMusicCurrent;
    QList<MusicModel*> _queueMusic;

    void changeMusicCurrent( MusicModel* musica );
    void setCurrentMusic( MusicModel* musica );

};

#endif // MUSICCONTROLLER_H
