#ifndef ORIGEN_H
#define ORIGEN_H

//Clase Origen
class Origen
{
    private:
        int x, y;

    public:
        Origen();
        Origen (int, int);
        int getX(){return x;}
        int getY(){return y;}
};

#endif // ORIGEN_H
