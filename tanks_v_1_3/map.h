#ifndef MAP_H
#define MAP_H

#include "header.h"
#include "QString"
#include "stdio.h"

struct Cell         //одна клетка поля
{
    int x;          //координата Х
    int y;          //координата У
    QString pic;    //изображение
    CellType type;  //тип
};

class Map
{
    public:
        Map(QString _path) {path = _path;}
        ~Map();
        int create();                                               //создание карты
        Cell* posXY(int _x, int _y);                                //получение клетки по ее координатам
        Cell* get_cell(int _i, int _j) {return mapa[_i][_j];}       //вернуть клетку с индексами
        bool is_road(int _x, int _y);                               //можно ли проехать по этой клетке (для танка)
        bool is_shot(int _x, int _y);                               //можно ли прострелить клетку (для снаряда)
        bool is_wc(int _x, int _y);                                 //можно ли утонуть (для танка)
    protected:
        FILE *fmapa;                                                //файл с описанием карты
        Cell *mapa[MAXROW][MAXCOL];                                 //массив структур, отображающий карту
        QString path;                                               //путь к файлу
};

#endif // MAP_H
