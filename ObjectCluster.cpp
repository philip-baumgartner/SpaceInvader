#include "ObjectCluster.h"

#include <iostream>

#include "Bullet.h"

int ObjectCluster::hashValue(int x, int y)
{
    return ((x + y) * (x + y + 1)) / 2 + y;
}

void ObjectCluster::add(Position* p)
{
    int s = spots.size();
    spots[hashValue(p->x, p->y)] = p;
    s = spots.size();
    spots[hashValue(p->x, p->y)] = p;
}

char ObjectCluster::getSymbol(int x, int y)
{
    return spots[hashValue(x,y)]->getSymbol();
}

void ObjectCluster::deleteElementOn(int x, int y)
{
    spots.erase(hashValue(x,y));
}

void ObjectCluster::clear()
{
    spots.clear();
}

bool ObjectCluster::enthalten(int x, int y)
{
    if(spots.find(hashValue(x,y)) != spots.end()) return true;
    else return false;
}

void ObjectCluster::fire(ObjectCluster& oc){

    std::map<int, Position*>::iterator it;
    for ( it = spots.begin(); it != spots.end(); it++ )
    {
        oc.add(new Bullet(it->second->x, it->second->y));
    }
}

std::vector<Position*>* ObjectCluster::eraseAll()
{
    std::vector<Position*>* result = new std::vector<Position*>();
    std::map<int, Position*>::iterator it;
    for ( it = spots.begin(); it != spots.end(); it++ )
    {
        result->push_back(it->second);
    }
    spots.clear();
    return result;
}

void ObjectCluster::move(int x, int y)
{
    bool canMove = true;
    std::map<int, Position*>::iterator it;
    for ( it = spots.begin(); it != spots.end(); it++ )
    {
        if(!(it->second->canMove(x,y))) canMove = false;
    }
    if(!canMove) return;

    std::vector<Position*>* all = eraseAll();
    for(std::vector<Position*>::iterator it = all->begin(); it != all->end(); ++it) {
        (*it)->move(x,y);
        spots[hashValue((*it)->x, (*it)->y)] = (*it);
    }

    delete all;
}
