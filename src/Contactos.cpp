#include "Contactos.h"
#include <iostream>
#include <cstdio>
using namespace std;
Contactos::Contactos()
{
*Nombre = {};
Telefono = 0;
coor = {30, 10};
opc = 1;
}

void Contactos::Menu()
{
            rlutil::hidecursor();
            while (opc != 0)
            {
                system("cls");
                Cuadro Cuadro_t(coor, 40, 4, opc);
                Cuadro_t.dibujar();
                Cuadro_t.mostrar_texto4();
                Cuadro_t.Resaltar2();

                        switch (rlutil::getkey()){
                            case 14:
                                    if (opc < 4){
                                        opc += 3;
                                    }
                                    else{

                                    opc -=3;
                                    }
                                    break;
                            case 15:
                                    if (opc > 3){
                                        opc -= 3;
                                    }
                                    else{

                                    opc +=3;
                                    }
                                    break;
                            case 16:
                                    if (opc == 1 || opc == 4){
                                        opc += 2;
                                    }
                                    else{
                                    opc --;
                                    }
                                    break;
                            case 17:
                                    if (opc == 3 || opc == 6){
                                        opc -= 2;
                                    }
                                    else{
                                    opc ++;
                                    }
                                    break;

                            case 1:
                                ///ACA VAN LAS OPCIONES SEGUN DONDE SE PRESIONE ENTER

                                            switch (opc){

                                                case 1:
                                                    ///AGREGAR///
                                                    Agregar();
                                                    break;
                                                case 2:
                                                    ///MODIFICAR///
                                                    Modificar();
                                                    break;
                                                case 3:
                                                    ///MOSTRAR///
                                                    Mostrar_reg();
                                                    break;
                                                case 4:
                                                    ///ELIMINAR///
                                                    break;
                                                case 5:
                                                    ///BUSCAR///
                                                    break;
                                                case 6:
                                                    return;
                                                    ///VOLVER///
                                            }
                            }

            }

}
void Contactos::Cargar()
{
    cout <<endl<<"Nombre: ";
    cin.getline(Nombre, 30);
    cout <<endl<<"Telefono: ";
    cin >>Telefono;
    cin.ignore();


}
void Contactos::Mostrar(int i)
{
    gotoxy(33, i+17);
    cout <<"Nombre: "<<Nombre<<", Telefono: "<<Telefono;

}
bool Contactos::LeerDeDisco(int pos)
{
    bool leyo;
    FILE *p = fopen ("Contactos.dat", "rb");
    if (p == NULL){
        cout <<"no se pudo abrir el archivo";
        system("pause");
    }
    fseek (p, pos*sizeof(Contactos), 1);
    leyo = fread(this, sizeof(Contactos), 1, p);
    fclose(p);
    return leyo;
}
void Contactos::Agregar()
{
    Contactos obj;
    obj.Cargar();
    FILE *p = fopen ("Contactos.dat", "ab");
    if (p == NULL){
        cout <<"no se pudo abrir el archivo";
            system("pause");
    }
    bool ok = fwrite(&obj, sizeof(obj), 1, p);
    if (ok == false){
            cout <<"no se pudo escribir";
            system("pause");
    }
    fclose(p);

}
void Contactos::Modificar()
{


}
void Contactos::Mostrar_reg()
{
Contactos obj;
int i = 0;

while (obj.LeerDeDisco(i)){
    obj.Mostrar(i);
    cout <<endl;
    i ++;
}
getch();
}
