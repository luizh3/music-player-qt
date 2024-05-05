#ifndef ALBUMSTUBRESPONSE_H
#define ALBUMSTUBRESPONSE_H

#include <class/model/spotify/albummodel.h>
#include <class/model/spotify/trackmodel.h>
#include <class/response/bodystubresponse.h>

class MusicModel;
class AlbumStubResponse : public BodyStubResponse {
public:
    AlbumStubResponse();
    void fromJson( QJsonDocument& document ) override;
    QList<AlbumModel*> albums() const;
private:
    QList<MusicModel*> tracksToMusics( const QList<TrackModel*> tracks, const QString& urlImage ) const;
    QList<AlbumModel*> _album;
};

#endif // ALBUMSTUBRESPONSE_H
