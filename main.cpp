#include <iostream>
#include <cstring>
#include <cctype>
#include "banco.h"
#include "tarjeta.h"
#include "clientes.h"
#include "transacciones.h"
using namespace std;

banco banco1;

bool checkletra(char array[])
{

    for (int i = 0; array[i] != '\0'; i++)
    {
        if (!isalpha(array[i]) && array[i] != ' ')
        {
            return false;
        }
    }
    return true;
}

void menuEmpleado()
{
    cout << "**********MENU**********" << endl;
    cout << "1) Agregar Cliente" << endl;
    cout << "2) Eliminar Cliente" << endl;
    cout << "3) Mostrar Datos de Cliente" << endl;
    cout << "4) Generar Archivo de clientes" << endl;
    cout << "Ingrese un opcion" << endl;
}

void menuCliente()
{
    cout << "**********MENU**********" << endl;
    cout << "1) Ver mis datos" << endl;
    cout << "2) Ver dinero en cuenta" << endl;
    cout << "3) Realizar una transaccion" << endl;
    cout << "Ingrese un opcion" << endl;
}

bool clienteExistente(int _dni)
{
    Clientes *c = new Clientes[100];
    c = banco1.getlistado();
    int cantClientes = banco1.getnClientes();
    bool existe = false;
    for (int i = 0; i <= cantClientes; i++)
    {
        if (c[i].getDni() == _dni)
        {
            existe = true;
        }
    }
    return existe;
}

void AgregarCliente()
{
    int dni, anioingreso;
    int cantClientes = banco1.getnClientes();
    char nombre[20], apellido[20];

    cout << "Ingrese el Dni del cliente" << endl;
    cin >> dni;

    if (clienteExistente(dni) == false)
    {
        cout << "El cliente que desea agregar ya existe" << endl;
    }
    else
    {
        cout << "Ingrese el nombre" << endl;
        cin.getline(nombre, 20, '\n');
        if (checkletra(nombre) == false)
        {
            cout << "El nombre puede contener solo letras" << endl;
            cout << "Ingrese nuevamente el nombre" << endl;
            cin.getline(nombre, 20, '\n');
        };
        cout << "Ingrese el Apellido" << endl;
        cin.getline(apellido, 20, '\n');
        if (checkletra(apellido) == false)
        {
            cout << "El apellido puede contener solo letras" << endl;
            cout << "Ingrese nuevamente el apellido" << endl;
            cin.getline(apellido, 20, '\n');
        };
        cout<<"Ingrese el anio de ingreso"<<endl;
        cin>>anioingreso;
        Clientes cliente;

        cliente.setNcliente(cantClientes);
        cliente.setNombre(nombre);
        cliente.setApellido(apellido);
        cliente.setDni(dni);
        cliente.setAnioingreso(anioingreso);

        banco1.incrementarNClientes();

        banco1.altaClientes(cliente);

        cout<<"Cliente cargado con exito"<<endl;
    }
}

void EliminarCliente(){
    int nclien;
    cout<<"Ingrese el numero de cliente que quiere dar de baja"<<endl;
    cin>>nclien;

    banco1.bajaClientes(nclien);
}

void mostrarCLiente(){
    int ncliente;
    cout<<"Ingrese el numero de Cliente"<<endl;
    cin>>ncliente;

    if (ncliente>banco1.getnClientes())
    {
        cout<<"El numero de cliente no existe"<<endl;
    }
    else{
        banco1.muestraDatos(ncliente);
    }
}

void generarLista(){
    banco1.muestraListado();
}

void VerListado(){
    
}

void hacerTransaccion(Clientes cliente)
{
    int tipo_transaccion, moneda;
    float monto;

    cout << "Ingrese (1) para hacer una extracción y (2) para hacer un deposito: ";
    cin >> tipo_transaccion;

    cout << "Seleccione la moneda: " << endl;
    cout << "1) Pesos" << endl;
    cout << "2) Dólares" << endl;
    cin >> moneda;

    cout << "Ingrese el monto: ";
    cin >> monto;

    switch (tipo_transaccion)
    {
    case 1:
        if (moneda == 1)
        {
            if (cliente.getCajaPesos() >= monto)
            {
                cliente.setCajaPesos(cliente.getCajaPesos() - monto);
                cout << "Extracción exitosa. Nuevo saldo en pesos: " << cliente.getCajaPesos() << endl;
            }
            else
            {
                cout << "Fondos insuficientes en pesos." << endl;
            }
        }
        else if (moneda == 2)
        {
            if (cliente.getCajaDolar() >= monto)
            {
                cliente.setCajaDolar(cliente.getCajaDolar() - monto);
                cout << "Extracción exitosa. Nuevo saldo en dólares: " << cliente.getCajaDolar() << endl;
            }
            else
            {
                cout << "Fondos insuficientes en dólares." << endl;
            }
        }
        break;

    case 2:
        if (moneda == 1)
        {
            cliente.setCajaPesos(cliente.getCajaPesos() + monto);
            cout << "Depósito exitoso. Nuevo saldo en pesos: " << cliente.getCajaPesos() << endl;
        }
        else if (moneda == 2)
        {
            cliente.setCajaDolar(cliente.getCajaDolar() + monto);
            cout << "Depósito exitoso. Nuevo saldo en dólares: " << cliente.getCajaDolar() << endl;
        }
        break;

    default:
        cout << "Opción no válida." << endl;
        break;
    }
}

/*
void validarAntiguedad() {
    int antiguedad = 2024 - anioingreso;
    if (antiguedad < 1) {
    tipocliente = "Plata";
    cout<<tipocliente<<endl;
    limiteCredito = 0;

    } else if (antiguedad >= 1 && antiguedad < 5) {
    tipocliente = "Oro";
    cout<< tipocliente <<endl;
    limiteCredito = 250000;
    } else {
        tipocliente = "Platino";
        cout<< tipocliente <<endl;
        limiteCredito = 500000;
        }
    }
*/

int main()
{
    int tipoUsuario;
    cout << "Ingrese el tipo de usuario (1 para Cliente, 2 para Empleado): ";
    cin >> tipoUsuario;

    if (tipoUsuario == 1)
    {
        int opcionCliente;
        do
        {
            menuCliente();
            cin >> opcionCliente;
            switch (opcionCliente)
            {
            case 1:
               
                break;
            case 2:
                
                break;
            case 3:
                hacerTransaccion(cliente);
                break;
            case 0:
                cout << "Saliendo del menu cliente..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
            }
        } while (opcionCliente != 0);
    }
    else if (tipoUsuario == 2)
    {
        
    char nombreB[20], direccionB[20];

    cout << "Ingrese el nombre del banco: ";
    cin.getline(nombreB, 20);
    cout << "Ingrese la dirección del banco: ";
    cin.getline(direccionB, 20);
    
        int opcionEmpleado;
        do
        {
            menuEmpleado();
            cin >> opcionEmpleado;
            switch (opcionEmpleado)
            {
            case 1:
                AgregarCliente();
                break;
            case 2:
                EliminarCliente();
                break;
            case 3:
                VerListado();
                break;
            case 0:
                cout << "Saliendo del menu empleado..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
            }
        } while (opcionEmpleado != 0);
    }
    else
    {
        cout << "Tipo de usuario no valido." << endl;
    }
}

