#ifndef HTTPSTATUSENUM_H
#define HTTPSTATUSENUM_H

enum class HttpStatusEnum : int {
    NOT_FOUND = 404,
    SUCCESS = 200,
    TIMEOUT_ERROR = 599,
};

#endif // HTTPSTATUSENUM_H
