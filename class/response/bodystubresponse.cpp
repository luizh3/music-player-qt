#include "bodystubresponse.h"

BodyStubResponse::BodyStubResponse() :
    _status( HttpStatusEnum::NOT_FOUND ){}

HttpStatusEnum BodyStubResponse::status() const {
    return _status;
}

void BodyStubResponse::setStatus( HttpStatusEnum newStatus ) {
    _status = newStatus;
}
