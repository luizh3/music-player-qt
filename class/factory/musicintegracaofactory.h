#ifndef MUSICINTEGRACAOFACTORY_H
#define MUSICINTEGRACAOFACTORY_H

#include "../model/tipointegracaoenum.h"
#include "../integracao/musicintegracao.h"

class MusicIntegracaoFactory {
public:
    static MusicIntegracao* build( const TipoIntegracaoEnum& tpIntegracao );
};

#endif // MUSICINTEGRACAOFACTORY_H
