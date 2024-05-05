#ifndef LISTSONGSDELEGATE_H
#define LISTSONGSDELEGATE_H

#include <QString>

#include "../model/tipointegracaoenum.h"

class AlbumModel;
class MusicModel;
class MusicIntegracao;
class ListSongsDelegate {
public:
    ListSongsDelegate( const TipoIntegracaoEnum& tpIntegracao );

    QList<MusicModel*> songs() const;
    QList<AlbumModel*> albums() const;

    void addSong( const QString& identifier ) const;

private:
    MusicIntegracao* _musicIntegracao;
};

#endif // LISTSONGSDELEGATE_H
