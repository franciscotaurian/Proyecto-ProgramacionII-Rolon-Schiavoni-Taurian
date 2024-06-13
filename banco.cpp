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


void banco::ActualizarLista(Clientes nuevalista[]){
    for (int i = 0; i <= nClientes; i++)
    {
        listado[i]=nuevalista[i];
    }
    
}

int banco::getnClientes(){
    return nClientes;
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

void banco::muestraListado()
{
    ofstream listadoClientes;
    listadoClientes.open("C:/Users/Francisco/Desktop/Proyecto-ProgramacionII-Rolon-Schiavoni-Taurian/archivos/listadoClientes.txt");
    
    if (!listadoClientes) {
        cerr << "Error al abrir el archivo listadoClientes.txt" << endl;
        return;
    }

    listadoClientes << "-------------LISTADO DE CLIENTES----------" << endl;
    for (int i = 0; i < nClientes; i++)
    {
        listadoClientes << "Cliente n: " << listado[i].getNumCliente() << ":" << endl;
        listadoClientes << "Nombre: " << listado[i].getNombre() << "." << endl;
        listadoClientes << "Apellido: " << listado[i].getApellido() << "." << endl;
        listadoClientes << "Dni: " << listado[i].getDni() << "." << endl;
        listadoClientes << "Tipo de cliente: " << listado[i].getTipocliente() << "." << endl;
        cout<<""<<endl;
    }
    
    listadoClientes.close();
    
    if (listadoClientes.fail()) {
        cerr << "Error al cerrar el archivo listadoClientes.txt" << endl;
    } else {
        cout << "Archivo generado correctamente." << endl;
    }
}

void banco::muestraTransacciones()
{
    ofstream listaTrans;
    listaTrans.open("C:/Users/cande/Onedrive/Documentos/Proyecto-ProgramacionII-Rolon-Schiavoni-Taurian/archivos/listaTrans.txt");
    
    if (!listaTrans) {
        cerr << "Error al abrir el archivo listaTransacciones.txt" << endl;
        return;
    }

        listaTrans << "-------------LISTADO DE TRANSACCIONES----------" << endl;

    for (int i = 0; i < nClientes; i++)
    {
        listaTrans << "Cliente n: " << listado[i].getNumCliente() << ":" << endl;
        listaTrans << "Transacciones: " << listado[i].gettransacciones() << "." << endl;
        
        
        cout<<""<<endl;
    }
    
    listaTrans.close();
    
    if (listaTrans.fail()) {
        cerr << "Error al cerrar el archivo listadoClientes.txt" << endl;
    } else {
        cout << "Archivo generado correctamente." << endl;
    }


}


Clientes *banco::getlistado(){
    Clientes *p= new Clientes[100];
    for (int i = 0; i < nClientes; i++)
    {
        p[i]=listado[i];
    }
    return p;

}

void banco::muestraDatos(int posicion)
{

        cout << "Numero de cliente: " << listado[posicion].getNumCliente()<< endl;
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

void banco::bajaClientes(int nclient){
    listado[nclient].setEstado("Baja");
}
