#include <iostream>
#include <cstring>
#include <fstream>
#include "banco.h"
#include "clientes.h"
using namespace std;

banco::banco()
{
    nEmpleado = 0;
    ntransacciones = 0;
    nClientes = 0;
}

banco::banco(char _nombre[], char _direccion[])
{
    strcpy(nombre, _nombre);       // Copia el contenido de _nombre en nombre
    strcpy(direccion, _direccion); // Copia el contenido de _direccion en direccion
    nEmpleado = 0;
    ntransacciones = 0;
    nClientes = 0;
}

void banco::setNombre(char name[])
{
    strcpy(nombre, name); // Copia el contenido de name en nombre
}

void banco::setDireccion(char adress[])
{
    strcpy(direccion, adress); // Copia el contenido de adress en direccion
}

void banco::incrementarnEmpleados()
{
    nEmpleado++;
}

int banco::getnEmpleado()
{
    return nEmpleado;
}

void banco::ActualizarLista(Clientes nuevalista[])
{
    for (int i = 0; i <= nClientes; i++)
    {
        listado[i] = nuevalista[i]; // Copia el contenido de nuevalista en listado
    }
}

int banco::getnClientes()
{
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
    listadoClientes.open("/home/francisco/Desktop/Proyecto-ProgramacionII-Rolon-Schiavoni-Taurian/archivos/listadoClientes.txt");

    if (!listadoClientes)
    {
        cerr << "Error al abrir el archivo listadoClientes.txt" << endl;
        // Muestra un mensaje de error si no se puede abrir el archivo
        return;
    }

    listadoClientes << "-------------LISTADO DE CLIENTES----------" << endl;
    for (int i = 0; i < nClientes; i++)
    {
        listadoClientes << endl;
        listadoClientes << "Cliente n: " << listado[i].getNumCliente() << ":" << endl;
        listadoClientes << "Nombre: " << listado[i].getNombre() << "." << endl;
        listadoClientes << "Apellido: " << listado[i].getApellido() << "." << endl;
        listadoClientes << "Dni: " << listado[i].getDni() << "." << endl;
        listadoClientes << "Tipo de cliente: " << listado[i].getTipocliente() << "." << endl;
        listadoClientes << "Caja en pesos: "<<listado[i].getCaja_pesos() << "."<<endl;
        listadoClientes << "Caja en dolares: "<<listado[i].getCaja_dolar() << "."<<endl;
        listadoClientes << "------------------------------" << endl;
    }

    listadoClientes.close();

    if (listadoClientes.fail())
    {
        cerr << "Error al cerrar el archivo listadoClientes.txt" << endl;
        // Muestra un mensaje de error si no se puede cerrar el archivo
    }
    else
    {
        cout << "Archivo generado correctamente." << endl;
    }
}

void banco::muestraTransacciones()
{
    ofstream listaTrans;
    listaTrans.open("/home/francisco/Desktop/Proyecto-ProgramacionII-Rolon-Schiavoni-Taurian/archivos/listaTrans.txt");

    if (!listaTrans)
    {
        cerr << "Error al abrir el archivo listaTransacciones.txt" << endl;
        // Muestra un mensaje de error si no se puede abrir el archivo
        return;
    }

    listaTrans << "-------------LISTADO DE TRANSACCIONES----------" << endl;

    for (int i = 0; i < ntransacciones; i++)
    {
        listaTrans << endl;
        listaTrans << "Dni del cliente: " << historial[i].getNum_cliente() << "." << endl;
        listaTrans << "Tipo de transaccion: " << historial[i].getTipo() << "." << endl;
        listaTrans << "Tipo de moneda: " << historial[i].getMoneda() << "." << endl;
        listaTrans << "Dia: " << historial[i].getDia() << "." << endl;
        listaTrans << "Mes: " << historial[i].getMes() << "." << endl;
        listaTrans << "Año: " << historial[i].getAnio() << "." << endl;
        listaTrans << "Monto: " << historial[i].getMonto() << "." << endl;
        listaTrans << "--------------------------------------" << endl;
    }

    listaTrans.close();

    if (listaTrans.fail())
    {
        cerr << "Error al cerrar el archivo listadoClientes.txt" << endl;
        // Muestra un mensaje de error si no se puede abrir el archivo
    }
    else
    {
        cout << "Archivo generado correctamente." << endl;
    }
}

void banco::transaccionAnio(int anio)
{
    cout << "-------------LISTADO DE TRANSACCIONES----------" << endl;
    bool transanio = true;

    for (int i = 0; i <= ntransacciones; i++)
    {
        if (historial[i].getAnio() == anio)
        {
            cout << "Dni del cliente: " << historial[i].getNum_cliente() << "." << endl;
            cout << "Tipo de transaccion: " << historial[i].getTipo() << "." << endl;
            cout << "Tipo de moneda: " << historial[i].getMoneda() << "." << endl;
            cout << "Dia: " << historial[i].getDia() << "." << endl;
            cout << "Mes: " << historial[i].getMes() << "." << endl;
            cout << "Año: " << historial[i].getAnio() << "." << endl;
            cout << "Monto: " << historial[i].getMonto() << "." << endl;
            cout << "--------------------------------------" << endl;
            transanio = false;
        }
    }
    if (transanio == true)
    {
        cout << "No hay transacciones en este año" << endl;
    }
}

void banco::transaccionMes(int mes)
{
    cout << "-------------LISTADO DE TRANSACCIONES----------" << endl;
    bool transmes = true;

    for (int i = 0; i <= ntransacciones; i++)
    {
        if (historial[i].getMes() == mes)
        {
            cout << "Dni del cliente: " << historial[i].getNum_cliente() << "." << endl;
            cout << "Tipo de transaccion: " << historial[i].getTipo() << "." << endl;
            cout << "Tipo de moneda: " << historial[i].getMoneda() << "." << endl;
            cout << "Dia: " << historial[i].getDia() << "." << endl;
            cout << "Mes: " << historial[i].getMes() << "." << endl;
            cout << "Año: " << historial[i].getAnio() << "." << endl;
            cout << "Monto: " << historial[i].getMonto() << "." << endl;
            cout << "--------------------------------------" << endl;
            transmes == false;
        }
    }
    if (transmes == true)
    {
        cout << "No existe ninguna transaccion en el mes" << endl;
    }
}

void banco::transaccionCliente(int numdoc)
{
    cout << "-------------LISTADO DE TRANSACCIONES----------" << endl;
    bool transcli = true;

    for (int i = 0; i <= ntransacciones; i++)
    {
        if (historial[i].getNum_cliente() == numdoc)
        {
            cout << "Dni del cliente: " << historial[i].getNum_cliente() << "." << endl;
            cout << "Tipo de transaccion: " << historial[i].getTipo() << "." << endl;
            cout << "Tipo de moneda: " << historial[i].getMoneda() << "." << endl;
            cout << "Dia: " << historial[i].getDia() << "." << endl;
            cout << "Mes: " << historial[i].getMes() << "." << endl;
            cout << "Año: " << historial[i].getAnio() << "." << endl;
            cout << "Monto: " << historial[i].getMonto() << "." << endl;
            cout << "--------------------------------------" << endl;
            transcli == false;
        }
    }
    if (transcli == false)
    {
        cout << "No existe ninguna transaccion de este cliente" << endl;
    }
}

Clientes *banco::getlistado()
{
    Clientes *p = new Clientes[100];
    for (int i = 0; i < nClientes; i++)
    {
        p[i] = listado[i];
    }
    return p;
}

void banco::muestraDatos(int posicion)
{

    cout << "Numero de cliente: " << listado[posicion].getNumCliente() << endl;
    cout << "Nombre: " << listado[posicion].getNombre() << endl;
    cout << "Apellido: " << listado[posicion].getApellido() << endl;
    cout << "Dni: " << listado[posicion].getDni() << endl;
    cout << "Tipo de cliente: " << listado[posicion].getTipocliente() << endl;
    cout << "Estado: " << listado[posicion].getEstado() << endl;
    cout << "Caja en Pesos: $" << listado[posicion].getCaja_pesos() << endl;
    cout << "Caja en Dolares: $" << listado[posicion].getCaja_dolar() << endl;
}

void banco::altaClientes(Clientes _cliente)
{
    listado[nClientes] = _cliente;
    nClientes++;
}

void banco::agregoTransaccion(Transacciones _transaccion)
{
    historial[ntransacciones] = _transaccion;
    ntransacciones++;
}

void banco::bajaClientes(int nclient)
{
    listado[nclient].setEstado("Baja");
}
void banco::sobreescbirCliente(int nc,Clientes sob){
    listado[nc]=sob;
}
