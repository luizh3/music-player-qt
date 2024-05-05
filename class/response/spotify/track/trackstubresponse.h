#ifndef TRACKSTUBRESPONSE_H
#define TRACKSTUBRESPONSE_H

#include <QList>

#include <class/model/spotify/trackmodel.h>

class TrackStubResponse {
public:
  QList<TrackModel*> fromJson( const QJsonValue& value ) const;
};

#endif // TRACKSTUBRESPONSE_H
