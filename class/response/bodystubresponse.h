#ifndef BODYSTUBRESPONSE_H
#define BODYSTUBRESPONSE_H

#include <QJsonDocument>

#include <class/worker/request/httpstatusenum.h>

class BodyStubResponse {
public:
    BodyStubResponse();
    virtual ~BodyStubResponse() = default;
    virtual void fromJson( QJsonDocument& document ) = 0;

    HttpStatusEnum status() const;
    void setStatus( HttpStatusEnum newStatus );

private:
    HttpStatusEnum _status;
};

#endif // BODYSTUBRESPONSE_H
