#include <iostream>
#include <cstring>
#include <fstream>
#include "banco.h"
#include "clientes.h"
using namespace std;

banco::banco()
{
}

banco::banco(char _nombre[], char _direccion[])
{
    strcpy(nombre, _nombre);
    strcpy(direccion, _direccion);
}

void banco::setNombre(char name[])
{
    strcpy(nombre, name);
}

void banco::setDireccion(char adress[])
{
    strcpy(direccion, adress);
}

char *banco::getNombre()
{
    char *p = new char[20];
    strcpy(p, nombre);
    return p;
}

char *banco::getDireccion()
{
    char *p = new char[20];
    strcpy(p, direccion);
    return p;
}

void banco::getListado()
{
    ofstream listadoClientes;
    listadoClientes.open("C:/Users/Francisco/Desktop/Proyecto-ProgramacionII-Rolon-Schiavoni-Taurian/txt");
    listadoClientes << "-------------LISTADO DE CLIENTES----------" << endl;
    for (int i = 0; i < nClientes; i++)
    {
        listadoClientes << "Cliente n: " << listado[i].<< ":" << endl;
        listadoClientes << "Nombre: " << listado[i].getNombre() << "." << endl;
        listadoClientes << "Apellido: " << listado[i].getApellido() << "." << endl;
        listadoClientes << "Dni: " << listado[i].getDni() << "." << endl;
        listadoClientes << "Tipo de cliente: " << listado[i].getTipocliente() << "." << endl;
    }
}

void banco::muestraDatos(int posicion)
{

        cout << "Numero de cliente: " << listado[posicion].get << endl;
        cout << "Nombre: " << listado[posicion].getNombre() << endl;
        cout << "Apellido: " << listado[posicion].getApellido() << endl;
        cout << "Dni: " << listado[posicion].getDni() << endl;
        cout << "Tipo de cliente: " << listado[posicion].getTipocliente() << endl;
        cout << "Estado: " << listado[posicion].getEstado() << endl;
        cout << "Caja en Pesos: $" << listado[posicion].getCaja_pesos() << endl;
        cout << "Caja en Dolares: $" << listado[posicion].getCaja_dolar() << endl;
    
}

void banco::altaClientes(Clientes _cliente){
    listado[nClientes]=_cliente;
    nClientes++;
}

void()
