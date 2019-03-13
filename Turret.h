#ifndef __TURRET__
#define __TURRET__

#include "Position.h"

class Turret: public Position
{
public:
    Turret(int x, int y):Position(x,y) {};
    virtual void fire(){
    }

    virtual char getSymbol(){
        return '=';
    }

    virtual bool canMove(int offset_x, int offset_y){
        if(x + offset_x < 0 || x + offset_x > fieldWidth || y + offset_y < 0 || y + offset_y > fieldHeight) return false;
        else return true;
    }

    virtual void move(int offset_x, int offset_y){
        x += offset_x;
        y += offset_y;
    }

    virtual ~Turret() {};
};

#endif
