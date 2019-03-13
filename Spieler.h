#ifndef __SPIELER__
#define __SPIELER__

#include "Position.h"
#include "Settings.h"

class Spieler: public Position
{
public:
    Spieler(int x, int y):Position(x,y) {};
    virtual char getSymbol(){
        return '>';
    }

    virtual bool canMove(int offset_x, int offset_y){
        if(x + offset_x < 0 || x + offset_x > fieldWidth || y + offset_y < 0 || y + offset_y > fieldHeight) return false;
        else return true;
    }

    virtual void move(int offset_x, int offset_y){
        x += offset_x;
        y += offset_y;
    }

    virtual ~Spieler() {};
};

#endif
