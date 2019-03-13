#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int stackSize;
int stackCapacity;

struct Score{
    int score;
    char name[40];
};

typedef struct Score Score;
Score* scoreStack;
void scoreStackPush(char* name, int score, int nameLength){
    if(stackSize>=stackCapacity)
        scoreStack = (Score*) realloc(scoreStack,++stackCapacity*sizeof(Score));
    memcpy(scoreStack[stackSize].name,name,nameLength*sizeof(char));
    scoreStack[stackSize++].score=score;


}

int scoreStackHighest(int score){
    int i;
    for(i=0;i<stackSize;i++){
        if(scoreStack[i].score>score) return 0;
    }

    return 1;
}

void scoreStackSort(){
    Score* temp=(Score*)calloc(1,sizeof(Score));
    int wasGefunden;
    wasGefunden=1;
    int i;
    while(wasGefunden){
        wasGefunden=0;
        for(i=0;i<(stackSize-1);i++){
            if(scoreStack[i+1].score>scoreStack[i].score){
                memcpy(temp,&scoreStack[i],sizeof(Score));
                memcpy(&scoreStack[i],&scoreStack[i+1],sizeof(Score));
                memcpy(&scoreStack[i+1],temp,sizeof(Score));
                wasGefunden=1;
                break;
            }
        }
    }
}

void scoreStackPrintSimple(){
    int i;
    for(i=0;i<stackSize;i++){
        printf("%s,%i",scoreStack[i].name,scoreStack[i].score);
        printf("\n");

    }
}


void scoreStackPrint(){
    int hs;
    int index;
    int i;

    do{
        hs=0;
        for(i=0;i<stackSize;i++){
            if(scoreStack[i].score>hs){
                hs=scoreStack[i].score;
                index=i;
            }
        }

        printf("%s,%i",scoreStack[index].name,scoreStack[index].score);
        printf("\n");
        scoreStack[index].score=0;
    }while(hs>0);
}
