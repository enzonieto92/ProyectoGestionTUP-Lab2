#ifndef TEXTO_H
#define TEXTO_H
#include "funciones.h"
class Texto
{
    private:
        origen coor;
    public:
        Texto();
        Texto(origen);
        void mostrar_texto1();
        void resaltar(int&);
};

#endif // TEXTO_H
