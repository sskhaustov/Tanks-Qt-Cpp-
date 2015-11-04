#include "map.h"

Map::~Map()
{
    for (int _i = 0; _i < MAXROW; _i++)
        for (int _j = 0; _j < MAXCOL; _j++)
            delete mapa[_i][_j];
}

int Map::create()
{
    int _type;
    fmapa = fopen(path.toAscii().data(), "r");
    if (fmapa == NULL)
        return 1;
    for (int _i = 0, _x = 0; _i < MAXROW; _i++, _x+=20)
        for (int _j = 0, _y = 0; _j < MAXCOL; _j++, _y+=20)
        {
            if (fscanf(fmapa, "%d", &_type) == -1)
                return 2;
            mapa[_i][_j] = new Cell;
            mapa[_i][_j]->x = _x;
            mapa[_i][_j]->y = _y;
            switch (_type)
            {
            case 0:
                mapa[_i][_j]->type = cGrass;
                mapa[_i][_j]->pic = "textures/grass.png";
                break;
            case 1:
                mapa[_i][_j]->type = cDotG;
                mapa[_i][_j]->pic = "textures/dot_grass.png";
                break;
            case 2:
                mapa[_i][_j]->type = cAsph;
                mapa[_i][_j]->pic = "textures/asphalt.png";
                break;
            case 3:
                mapa[_i][_j]->type = cDotA;
                mapa[_i][_j]->pic = "textures/dot_asphalt.png";
                break;
            case 4:
                mapa[_i][_j]->type = cSand;
                mapa[_i][_j]->pic = "textures/sand.png";
                break;
            case 5:
                mapa[_i][_j]->type = cSwamp;
                mapa[_i][_j]->pic = "textures/swamp.png";
                break;
            case 6:
                mapa[_i][_j]->type = cHouse;
                mapa[_i][_j]->pic = "textures/house.png";
                break;
            case 7:
                mapa[_i][_j]->type = cWall;
                mapa[_i][_j]->pic = "textures/wall.png";
                break;
            case 8:
                mapa[_i][_j]->type = cWater;
                mapa[_i][_j]->pic = "textures/water.png";
                break;
            case 9:
                mapa[_i][_j]->type = cForest;
                mapa[_i][_j]->pic = "textures/forest.png";
                break;
            default:
                mapa[_i][_j]->type = cNone;
            }
        }
    return 0;
}

Cell* Map::posXY(int _x, int _y)
{
    for (int _i = 0; _i < MAXROW; _i++)
        for (int _j = 0; _j < MAXCOL; _j++)
            if ((_x >= mapa[_i][_j]->x - 10 && _x < mapa[_i][_j]->x + 10) && (_y >= mapa[_i][_j]->y - 10 && _y < mapa[_i][_j]->y + 10))
                return mapa[_i][_j];
    return NULL;
}

bool Map::is_road(int _x, int _y)
{
    return (posXY(_x, _y)->type == cGrass || posXY(_x, _y)->type == cAsph || posXY(_x, _y)->type == cSand || posXY(_x, _y)->type == cWater || posXY(_x, _y)->type == cSwamp);
}

bool Map::is_shot(int _x, int _y)
{
    return (posXY(_x, _y)->type != cWall || posXY(_x, _y)->type != cWallD || posXY(_x, _y)->type != cHouse || posXY(_x, _y)->type != cTank);
}

bool Map::is_wc(int _x, int _y)
{
    return (posXY(_x, _y)->type == cWater || posXY(_x, _y)->type == cSwamp);
}
