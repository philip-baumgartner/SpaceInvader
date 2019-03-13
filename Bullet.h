#ifndef __BULLET__
#define __BULLET__

#include "Position.h"

class Bullet: public Position
{
public:
    Bullet(int x, int y):Position(x,y) {};
    virtual char getSymbol(){
        return '-';
    }
    virtual ~Bullet() {};
};

#endif
