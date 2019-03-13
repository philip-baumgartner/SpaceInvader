#include "Position.h"
#include <cstdlib>

bool Position::operator==(const Position& p)
{
    if(this->x == p.x && this->y == p.y) return true;
    else return false;
}




