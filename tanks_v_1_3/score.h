#ifndef SCORE_H
#define SCORE_H

#include "stdio.h"

class Score
{
    public:
        Score() {sc = 0;}
        ~Score();
        void inc_score() {sc += 100;}
        void save_score();
        void load_score();
        void set_score_win(int _lives, int _level, int _ammo, int _arm);
        int get_curr_score() {return sc;}
        int get_max_score() {return max_sc;}
        void cancel() {sc = 0;}
    private:
        FILE *store;
        int sc;
        int max_sc;
};

#endif // SCORE_H
