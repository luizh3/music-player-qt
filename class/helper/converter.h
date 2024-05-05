#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>

namespace Converter {
    template < typename T>
    static QList<QObject*> toObject( QList<T*> objectList){
        QList<QObject*> listQObject = {};

        for( QObject* object : objectList ){
            listQObject.append( object );
        }
        return listQObject;
    }
};

#endif // CONVERTER_H
