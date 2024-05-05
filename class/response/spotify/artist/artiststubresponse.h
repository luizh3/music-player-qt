#ifndef ARTISTSTUBRESPONSE_H
#define ARTISTSTUBRESPONSE_H

#include <QJsonObject>

#include <class/model/spotify/artistmodel.h>

class ArtistStubResponse {
public:
    ArtistStubResponse();
    QList<ArtistModel*> fromJson( const QJsonValue& value ) const;
};

#endif // ARTISTSTUBRESPONSE_H
