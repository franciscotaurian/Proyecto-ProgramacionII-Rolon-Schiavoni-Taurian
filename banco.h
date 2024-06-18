#include <iostream>
#include "clientes.h"
using namespace std;

class banco {
    private:
        char nombre[20];
        char direccion[20];
        int nClientes;
        int nEmpleado;
        int ntransacciones;
        Clientes listado[100];
        Transacciones historial[100];
    public:
        banco();
        banco(char[],char[]);
        void setNombre(char[]);
        void setDireccion(char[]);
        void incrementarNClientes();
        void ActualizarLista(Clientes[]);
        void incrementarnEmpleados();
        void muestraTransacciones();
        int getnClientes();
        int getnEmpleado();
        char *getNombre();
        char *getDireccion();
        Clientes *getlistado();
        void muestraListado ();
        void muestraDatos (int);
        void agregoTransaccion(Transacciones);
        void altaClientes(Clientes);
        void bajaClientes(int);
        void transaccionMes(int);
        void transaccionAnio(int);
};