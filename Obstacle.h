#ifndef __OBSTACLE__
#define __OBSTACLE__

#include "Position.h"
#include "Settings.h"

class Obstacle: public Position
{
public:
    Obstacle(int x, int y):Position(x,y) {};
    virtual char getSymbol(){
        return '#';
    }

    virtual void move(int offset_x, int offset_y){
        x += offset_x;
        y += offset_y;
        if(x == 0){
            x = fieldWidth;
            y = rand() % fieldHeight;
        }
    }

    virtual ~Obstacle() {};
};


#endif
