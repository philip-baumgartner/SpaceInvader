#include "Spieler.h"


void Spieler::runter()
{
    if(this->y3<19)
    {
        this->y1++;
        this->y2++;
        this->y3++;
        this->y4++;
    }
}

void Spieler::hoch()
{
    if(this->y1>0)
    {
        this->y1--;
        this->y2--;
        this->y3--;
        this->y4--;
    }
}
void Spieler::links()
{
    if(this->x1>0)
    {
        this->x1--;
        this->x2--;
        this->x3--;
        this->x4--;
    }
}
void Spieler::rechts()
{
    if(this->x1<20)
    {
        this->x1++;
        this->x2++;
        this->x3++;
        this->x4++;
    }
}

bool Spieler::enthaltenReihe(int y)
{
    if(this->y1==y||this->y2==y||this->y3==y||this->y4==y) return true;
    else return false;
}

bool Spieler::enthalten(int x, int y)
{
    if(((this->x1==x)&&(this->y1==y))||((this->x2==x)&&(this->y2==y))||((this->x3==x)&&(this->y3==y))||((this->x4==x)&&(this->y4==y))) return true;
    else return false;


}
