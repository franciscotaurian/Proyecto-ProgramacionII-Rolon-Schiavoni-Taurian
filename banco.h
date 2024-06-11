#include <iostream>
#include "clientes.h"
using namespace std;

class banco {
    private:
        char nombre[20];
        char direccion[20];
        int nClientes;
        Clientes listado[100];
    public:
        banco();
        banco(char[],char[]);
        void setNombre(char[]);
        void setDireccion(char[]);
        char *getNombre();
        char *getDireccion();
        void getListado ();
        void muestraDatos (int);
        void altaClientes(Clientes);
        void bajaClientes(int);
};