#ifndef MUSICINTEGRACAO_H
#define MUSICINTEGRACAO_H

#include <class/music/musicmodel.h>
#include <class/model/spotify/albummodel.h>

class MusicIntegracao {
public:
    MusicIntegracao() = default;
    virtual QList<MusicModel*> songs() const = 0;
    virtual bool addSong( const QString& identifier ) = 0;

    virtual QList<AlbumModel*> albums() const {
        return {};
    };
};

#endif // MUSICINTEGRACAO_H
