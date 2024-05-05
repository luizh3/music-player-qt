#ifndef APISPOTIFY_H
#define APISPOTIFY_H

#include <QList>

class AlbumModel;
class ApiSpotify {
public:
    QList<AlbumModel*> albums() const;
};

#endif // APISPOTIFY_H
