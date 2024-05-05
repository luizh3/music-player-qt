#ifndef MUSICINTEGRACAOSPOTIFY_H
#define MUSICINTEGRACAOSPOTIFY_H

#include <class/integracao/musicintegracao.h>

class MusicIntegracaoSpotify : public MusicIntegracao {
public:
    QList<MusicModel*> songs() const override;
    bool addSong( const QString& indentifier ) override;
    QList<AlbumModel*> albums() const override;
};

#endif // MUSICINTEGRACAOSPOTIFY_H
