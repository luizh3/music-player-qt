#include "musiccontroller.h"

#include "helper/converter.h"

MusicController::MusicController() :
    _currentMusic(nullptr),
    _nrMusicCurrent(0),
    _queueMusic({}){}

void MusicController::next(){

    if( _nrMusicCurrent < 0 || ( _nrMusicCurrent + 1 ) >= _queueMusic.size() ){
        return;
    }

    changeMusicCurrent( _queueMusic.at(++_nrMusicCurrent) );
}

void MusicController::previous(){

    if( ( _nrMusicCurrent - 1 ) < 0 || ( _nrMusicCurrent - 1 ) > _queueMusic.size() ){
        return;
    }

    changeMusicCurrent( _queueMusic.at(--_nrMusicCurrent) );

}

void MusicController::start(){
    changeMusicCurrent( _queueMusic.at(0) );
}

void MusicController::addMusicQueue( QObject* object ) {

    _queueMusic.append( dynamic_cast<MusicModel*>( object ) );

    emit musicsQueueChanged();
    emit nextMusicChanged();
}

QList<QObject*> MusicController::musicsQueue() const{
    return Converter::toObject( _queueMusic );
}

QList<QObject*> MusicController::nextMusics() const {

    if( !_currentMusic ){
        return {};
    }

    QList<QObject*> nextMusics = {};

    for( int index = _queueMusic.indexOf(_currentMusic); index < _queueMusic.length(); ++index ){
        nextMusics.append( _queueMusic.at(index) );
    }

    return nextMusics;
}

void MusicController::changeMusicCurrent( MusicModel* musica ){

    setCurrentMusic( musica );

    emit currentMusicChange( musica );
    emit musicsQueueChanged();
    emit nextMusicChanged();
}

QObject* MusicController::currentMusic() const {
    return _currentMusic;
}

void MusicController::setCurrentMusic( MusicModel *musica) {
    _currentMusic = musica;
}

