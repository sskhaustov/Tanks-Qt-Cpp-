#ifndef GAMEPLAYING_H
#define GAMEPLAYING_H

#include "header.h"
#include "QString"

class gamePlaying
{
    public:
        gamePlaying(int _tanks_count, bool _alive);
        ~gamePlaying();
        void dec_tanks() {tanks_count--;} //уменьшить число танков
        QString map(int _i) {return lev[_i];} //текущая карта
        bool win() {return tanks_count == 1 && alive;} //победа
        bool lose() {return alive == false;} //поражение
        void dead() {alive = false;} //игрок уничтожен
    private:
        int tanks_count; //число танков
        bool alive; //жив ли игрок
        QString lev[8]; //уровни
};

#endif // GAMEPLAYING_H
