#include "musicintegracaofactory.h"

#include <QDebug>

#include "../integracao/local/musicintegracaolocal.h"
#include "../integracao/spotify/musicintegracaospotify.h"

MusicIntegracao* MusicIntegracaoFactory::build( const TipoIntegracaoEnum& tpIntegracao ) {

    qInfo() << "MusicIntegracaoFactory::build [TP_INTEGRACAO]" << int( tpIntegracao );

    MusicIntegracao* integracao = nullptr;

    switch ( tpIntegracao ) {
        case TipoIntegracaoEnum::SPOTIFY:
            integracao = new MusicIntegracaoSpotify();
            break;
        default:
            integracao = new MusicIntegracaoLocal();
            break;
    }

    qInfo() << "MusicIntegracaoFactory::build";

    return integracao;
}
