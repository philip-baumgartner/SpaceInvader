#ifndef __POSITION__
#define __POSITION__

class ObjectCluster;

class Position
{
public:
    int x,y;
    Position(int x, int y):x(x),y(y) {};
    bool operator==(const Position& p){
        if(this->x==p.x && this->y==p.y) return true;
        else return false;
    }
    virtual void fire(ObjectCluster& oc){}
    virtual char getSymbol(){
        return '#';
    }

    virtual bool canMove(int offset_x, int offset_y){
        return true;
    }

    virtual void move(int offset_x, int offset_y){
        x += offset_x;
        y += offset_y;
    }

    virtual ~Position() {};
};

#endif
