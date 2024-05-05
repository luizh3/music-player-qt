#ifndef MUSICINTEGRACAOLOCAL_H
#define MUSICINTEGRACAOLOCAL_H

#include <class/integracao/musicintegracao.h>

class MusicIntegracaoLocal : public MusicIntegracao {
public:
    MusicIntegracaoLocal();
    QList<MusicModel*> songs() const override;
    bool addSong( const QString& identifier ) override;
private:
    QString decomposeNameMusic( QString url ) const;
    void initializeConstSongs();

    QList<MusicModel*> _songs;
};

#endif // MUSICINTEGRACAOLOCAL_H
