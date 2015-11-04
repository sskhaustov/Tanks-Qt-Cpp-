#include "gamePlaying.h"

gamePlaying::gamePlaying(int _tanks_count, bool _alive)
{
    tanks_count = _tanks_count;
    alive = _alive;
    lev[0] = "maps/map_1.txt";
    lev[1] = "maps/map_2.txt";
    lev[2] = "maps/map_3.txt";
    lev[3] = "maps/map_4.txt";
    lev[4] = "maps/map_5.txt";
    lev[5] = "maps/map_6.txt";
    lev[6] = "maps/map_7.txt";
    lev[7] = "maps/map_8.txt";
}

gamePlaying::~gamePlaying()
{
}
