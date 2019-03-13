


class Endboss{
protected:
    Endboss():x(new int[20]),y(new int[20]){}
    int* x;
    int* y;
public:
    bool enthaltenReihe(int y){
        for(int i=0; i<20;i++){
            if(this->y[i]==y) return true;
        }

        return false;
    }

    bool enthalten(int x, int y){
        for(int i=0; i<20;i++){
                if(this->x[i]==x&&this->y[i]==y) return true;
        }

        return false;
    }

};


class Endboss1: public Endboss{
public:
    Endboss1(){
        this->x[0]=45;
        this->y[0]=10;
        this->x[1]=45;
        this->y[1]=9;
        this->x[2]=45;
        this->y[2]=8;
        this->x[3]=44;
        this->y[3]=8;
        this->x[4]=45;
        this->y[4]=11;
        this->x[5]=45;
        this->y[5]=12;
        this->x[6]=44;
        this->y[6]=12;
        this->x[7]=44;
        this->y[7]=10;
        this->x[8]=43;
        this->y[8]=10;
    }

};
