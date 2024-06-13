#include <iostream>
#include "clientes.h"
using namespace std;

class banco {
    private:
        char nombre[20];
        char direccion[20];
        int nClientes;
        Clientes listado[100];
        Transacciones lista[100];
    public:
        banco();
        banco(char[],char[]);
        void setNombre(char[]);
        void setDireccion(char[]);
        void incrementarNClientes();
        void ActualizarLista(Clientes[]);
        void muestraTransacciones();
        int getnClientes();
        char *getNombre();
        char *getDireccion();
        Clientes *getlistado();
        void muestraListado ();
        void muestraDatos (int);
        void altaClientes(Clientes);
        void bajaClientes(int);
};