#include "Origen.h"

Origen::Origen()
{
    x = 0;
    y = 0;
}

Origen::Origen(int _x, int _y)
{
   x = _x;
   y = _y;
}
int Origen::getX(){
return x;
}
int Origen::getY(){
return y;
}
