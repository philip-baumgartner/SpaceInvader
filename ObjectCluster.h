#ifndef __OBJECTCLUSTER__
#define __OBJECTCLUSTER__

#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>

#include "Position.h"
#include "Bullet.h"
#include "Obstacle.h"
#include "Settings.h"

static double clip = 20;

class ObjectCluster
{
private:
    std::map<int, Position*> spots;
    std::vector<Position*>* eraseAll();
public:

    ObjectCluster():visible(true){};
    bool visible;
    int hashValue(int x, int y);
    void add(Position* p);
    bool enthalten(int x, int y);
    char getSymbol(int x, int y);
    bool checkBounds();
    void move(int x, int y);
    void deleteElementOn(int x, int y);
    void fire(ObjectCluster& bullets);
    void clear();

    ~ObjectCluster() {
        spots.clear();
    };
};

#endif
