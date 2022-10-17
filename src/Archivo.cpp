#include "Archivo.h"
#include <iostream>

using namespace std;
Archivo::Archivo()
{
 a = 1;
}


void Archivo::Guardar(Contactos obj)
{
    FILE *p = fopen ("Contactos.dat", "ab");
    if (p == NULL){
        cout <<"no se pudo abrir el archivo";
            system("pause");
    }
    bool ok = fwrite(&obj, sizeof (Contactos), 1, p);
    if (ok == false){
            cout <<"no se pudo escribir";
            system("pause");
    }
    fclose(p);


}

void Archivo::Mostrar(Contactos obj)
{
    int pos = 1;
    FILE *p = fopen ("Contactos.dat", "rb");
    if (p == NULL){
        cout <<"no se pudo abrir el archivo";
            system ("pause");
    }
    while(fread (&obj, sizeof (Contactos), 1, p)){
    obj.Mostrar(pos);
    pos+= 2;
    }
    fclose(p);
}

