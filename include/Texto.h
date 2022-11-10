#ifndef TEXTO_H
#define TEXTO_H
#include "Funciones.h"
#include "Origen.h"

class Texto
{
    private:
        Origen coor;
        int opc;
    public:
        Texto(Origen&);
        void mostrar_texto1();
        void mostrar_texto2();
        void mostrar_texto3();
        void mostrar_texto4();
        void mostrar_texto5();
        void mostrar_texto6();
        void resaltar1(int);
        void resaltar2(int);
        void resaltar3(int);
        void resaltar4(int);
        void resaltar5(int);
        void resaltar6(int);

};

#endif // TEXTO_H
