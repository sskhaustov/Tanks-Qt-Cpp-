#include "score.h"

Score::~Score()
{
}

void Score::save_score()
{
    store = fopen("score.txt", "w");
    fprintf(store,"%d",sc);
    fclose(store);
}

void Score::load_score()
{
    store = fopen("score.txt", "r");
    fscanf(store,"%d",&max_sc);
    fclose(store);
}

void Score::set_score_win(int _lives, int _level, int _ammo, int _arm)
{
    sc = ((_level / (_lives + 1) + 1) * (_ammo + _arm) + sc);
}
