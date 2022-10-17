#ifndef TEXTO_H
#define TEXTO_H
#include "Funciones.h"

class Texto
{
    private:
        origen coor;
        int opc;
    public:
        Texto();
        Texto(origen);
        void mostrar_texto1();
        void mostrar_texto2();
        void mostrar_texto3();
        void mostrar_texto4();
        void resaltar1(int);
        void resaltar2(int);
};

#endif // TEXTO_H
