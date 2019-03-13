#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <sstream>
#include <mmsystem.h>

#include "Position.h"
#include "Spieler.h"
#include "Obstacle.h"
#include "Settings.h"
#include "Bullet.h"
#include "Turret.h"

#include "ObjectCluster.h"



using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


stringstream buffer;
bool obst = true;
int roundCount;
extern void scoreStackPush(char* name, int score, int nameLength);
extern void scoreStackPrint();
extern void scoreStackSort();
extern void scoreStackPrintSimple();
extern int scoreStackHighest(int staticScore);
namespace exceptions
{
class myexception: public exception
{

public:
    virtual const char* what() const throw()
    {
        return "Element nicht gefunden.";
    }
} missing_element;
}

void scoreCheck();
void addHighscore();

int score;
ObjectCluster spieler;
ObjectCluster bullets;
ObjectCluster hindernisse;


bool run;

void tick()
{
    static COORD zc;

    SetConsoleCursorPosition(h, zc);
    for(int y=0; y<=fieldHeight ; y++)
    {
        for(int x = 0; x <= fieldWidth; x++)
        {
            if(spieler.enthalten(x,y)) buffer << spieler.getSymbol(x,y);
            else if(hindernisse.enthalten(x,y)) buffer << hindernisse.getSymbol(x,y);
            else if(bullets.enthalten(x,y)) buffer << bullets.getSymbol(x,y);
            else buffer << " ";

            if(hindernisse.enthalten(x,y) && bullets.enthalten(x,y))
            {
                hindernisse.deleteElementOn(x,y);
                bullets.deleteElementOn(x,y);
                hindernisse.add(new Obstacle(fieldWidth, rand()%fieldHeight));
                score++;
            }

            if(hindernisse.enthalten(x,y) && spieler.enthalten(x,y))
            {
                run=false;
                system("cls");
                return;
            }

        }

        buffer << "\n";
    }
    buffer << "\n";
    buffer << "score: " << score;
    cout << "\r";
    cout << buffer.str() << endl;
    buffer.str("");
}


int main()
{
    srand (time(NULL));
    run=true;

    spieler.add(new Turret(1,1));
    spieler.add(new Spieler(1,2));
    spieler.add(new Spieler(2,2));
    spieler.add(new Turret(1,3));

    for(int i = 0 ; i < 60; i++){
        hindernisse.add(new Obstacle(fieldWidth - rand() % (fieldWidth / 3), rand()%fieldHeight));
    }

    while(run)
    {
        tick();
        bullets.move(1, 0);
        hindernisse.move(-1, 0);

        if (GetAsyncKeyState(VK_DOWN) !=0)
        {
            spieler.move(0, 1);
        }
        if (GetAsyncKeyState(VK_UP) !=0)
        {
            spieler.move(0, -1);
        }
        if (GetAsyncKeyState(VK_RIGHT) !=0)
        {
            spieler.move(1, 0);
        }
        if (GetAsyncKeyState(VK_LEFT) !=0)
        {
            spieler.move(-1, 0);;
        }
        if (GetAsyncKeyState(VK_SPACE) !=0)
        {
            if(clip > 0) {
                spieler.fire(bullets);
                clip--;
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE) !=0)
        {
            return 0;
        }

        if(clip < 10) clip = clip+0.04;

        roundCount++;
        if(roundCount > 10){
            hindernisse.add(new Obstacle(fieldWidth - rand() % (fieldWidth / 3), rand()%fieldHeight));
            roundCount = 0;
        }

        Sleep(40);
    }


    try{
        addHighscore();
    }catch(exception& e){
        system("cls");
        cout << e.what() << endl;
    };

    scoreCheck();

    hindernisse.clear();
    spieler.clear();
    bullets.clear();
    buffer.str("");
    score = 0;
    main();
}


void scoreCheck(){
    char name[40]={};
    int scoreTmp;
    FILE* scoresEin=NULL;
    scoresEin=fopen("HighScores.txt","r");

    while(fscanf(scoresEin,"%s%d",name,&scoreTmp)!=EOF){
        scoreStackPush(name,scoreTmp,sizeof(name));
    }

    fclose (scoresEin);
    if(scoreStackHighest(score)) cout << "Neuer Highscore!!!!!!" << endl;
    system("cls");
    scoreStackSort();
    scoreStackPrintSimple();
    Sleep(1000);
    getch();
    system("cls");
}

void addHighscore()
{
    system("cls");
    fflush(stdout);
    fflush(stdin);
    char abfrage[40]={};


    cout << "you loose. your score: " << score << endl;
    cout << "Namen eigeben" << endl;
    scanf("%s",abfrage);
    fflush(stdin);

    FILE* namenAnhaengen=NULL;
    namenAnhaengen=fopen("HighScores.txt","a");
    if(namenAnhaengen==NULL){
        throw (&exceptions::missing_element);
    }
    fputc ( '\n' , namenAnhaengen );
    fputs (abfrage,namenAnhaengen);
    fputc ( ' ' , namenAnhaengen );
    fprintf(namenAnhaengen, "%d", score);
    fclose (namenAnhaengen);
}






