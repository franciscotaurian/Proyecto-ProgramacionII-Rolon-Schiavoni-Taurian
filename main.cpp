#include <iostream>
#include <cstring>
#include <cctype>
#include "banco.h"
#include "tarjeta.h"
#include "clientes.h"
#include "empleado.h"
#include "transacciones.h"
using namespace std;

banco banco1;

bool checkletra(char array[])
{

    for (int i = 0; array[i] != '\0'; i++)
    {
        if (!isalpha(array[i]) && array[i] != ' ') // isalpha verifica si el caracter es una letra
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
    cout << "5) Ver todas las transacciones de los clientes" <<endl;
    cout << "0) Salir"<<endl;
    cout << "Ingrese un opcion" << endl;
}


void menuCliente()
{
    cout << "**********MENU**********" << endl;
    cout << "1) Ver mis datos" << endl;
    cout << "2) Ver dinero en cuenta" << endl;
    cout << "3) Realizar una transaccion" << endl;
    cout<< "0) Salir"<<endl;
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
    
    if (clienteExistente(dni) == true)
    {
        cout << "El cliente que desea agregar ya existe" << endl;
    }
    else
    {
        cout << "Ingrese el nombre" << endl;
        cin.ignore();
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

        banco1.altaClientes(cliente);

        cout<<"Cliente cargado con exito"<<endl;
        cout<<"El numero asignado al nuevo cliente es: "<<(banco1.getnClientes()-1)<<endl;
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

    if (ncliente>=banco1.getnClientes())
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

void transaccionestodas(){
    banco1.muestraTransacciones();
}


void hacerTransaccion(Clientes* cliente)
{
    if (cliente == nullptr) {
        cout << "El cliente no existe." << endl;
        return;
    }

    int tipo_transaccion, moneda;
    float monto;
    int dia, mes, anio;
    cout << "Ingrese el día de la transacción: ";
    cin >> dia;

    cout << "Ingrese el mes de la transacción: ";
    cin >> mes;

    cout << "Ingrese el año de la transacción: ";
    cin >> anio;

    cout << "Ingrese (1) para hacer una extracción y (2) para hacer un deposito: ";
    cin >> tipo_transaccion;
    
    Transacciones nuevaTransaccion;
    nuevaTransaccion.setDia(dia);
    nuevaTransaccion.setMes(mes);
    nuevaTransaccion.setAnio(anio);
    nuevaTransaccion.setTipo(tipo_transaccion);


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
            if (cliente->getCaja_pesos() >= monto)
            {
                cliente->setCaja_pesos(cliente->getCaja_pesos() - monto);
                cout << "Extracción exitosa. El saldo actual en pesos es: " << cliente->getCaja_pesos() << endl;
            }
            else
            {
                cout << "Fondos insuficientes en pesos." << endl;
            }
        }
        else if (moneda == 2)
        {
            if (cliente->getCaja_dolar() >= monto)
            {
                cliente->setCaja_dolar(cliente->getCaja_dolar() - monto);
                cout << "Extracción exitosa. El saldo actual en dólares es: " << cliente->getCaja_dolar() << endl;
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
            cliente->setCaja_pesos(cliente->getCaja_pesos() + monto);
            cout << "Depósito exitoso. Saldo actual en pesos: " << cliente->getCaja_pesos() << endl;
        }
        else if (moneda == 2)
        {
            cliente->setCaja_dolar(cliente->getCaja_dolar() + monto);
            cout << "Depósito exitoso. Saldo actual en dólares: " << cliente->getCaja_dolar() << endl;
        }
        break;

    default:
        cout << "Opción no válida." << endl;
        break;
    }
}


void verDatos(Clientes* cli) {


            cout << "Datos del Cliente:" << endl;
            cout << "Nombre: " << cli->getNombre() << endl;
            cout << "Apellido: " << cli->getApellido() << endl;
            cout << "DNI: " << cli->getDni() << endl;
            cout << "Tipo de Cliente: " << cli->getTipocliente() << endl;
          
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
        tipocliente = "Platio";
        cout<< tipocliente <<endl;
        limiteCredito = 500000;
        }
    }
*/

Clientes* clienteExiste(int _dni)
{
    Clientes* c = banco1.getlistado();
    int cantClientes = banco1.getnClientes();
    for (int i = 0; i < cantClientes; i++) 
    {
        if (c[i].getDni() == _dni)
        {
            return &c[i]; // Devolver el puntero al cliente si se encuentra
        }
    }
    return nullptr; 
}

int main() {
    int tipoUsuario;
    char nombreB[20], direccionB[20];
    cout << "Ingrese el nombre del banco: ";
    cin.ignore();
    cin.getline(nombreB, 20);
    cout << "Ingrese la dirección del banco: ";
    cin.getline(direccionB, 20);

    do {
        cout << "Ingrese el tipo de usuario (1 para Cliente, 2 para Empleado, 0 para salir): ";
        cin >> tipoUsuario;
    
        if (tipoUsuario == 1) {
            int dni;
            cout << "Ingrese su DNI: ";
            cin >> dni;

            Clientes* clienteActual = clienteExiste(dni);
            if (clienteActual != nullptr) { //nullptr es un puntero nulo
                int opcionCliente;
                do {
                    menuCliente();
                    cin >> opcionCliente;
                    switch (opcionCliente) {
                    case 1:
                        verDatos(clienteActual);
                        break;
                    case 2:
                        cout << "Dinero en cuenta:" << endl;
                        cout << "Pesos: " << clienteActual->getCaja_pesos() << endl;
                        cout << "Dólares: " << clienteActual->getCaja_dolar() << endl;
                        break;
                    case 3:
                        hacerTransaccion(clienteActual);
                        break;
                    case 0:
                        cout << "Saliendo del menú cliente..." << endl;
                        break;
                    default:
                        cout << "Opción no válida" << endl;
                        break;
                    }
                } while (opcionCliente != 0 && tipoUsuario == 1); // Permanece en el menú cliente hasta que se elija salir
            } else {
                cout << "El cliente no existe." << endl;
            }
        } else if (tipoUsuario == 2) {
    
            if(banco1.getnEmpleado()==0){
                char ne[20],ae[20];
                int dnie;
                Empleado e1;
                cout<<"Ingrese el Nombre del empleado"<<endl;
                cin.ignore();
                cin.getline(ne, 20, '\n');
                cout<<"Ingrese el apellido del empleado"<<endl;
                cin.getline(ae, 20, '\n');
                cout<<"Ingrese el Dni del empleado"<<endl;
                cin>>dnie;

                Empleado empleado1;

                empleado1.setNombre(ne);
                empleado1.setApellido(ae);
                empleado1.setDni(dnie);
                empleado1.setnEmpleado(1);
                
                banco1.incrementarnEmpleados();

                cout<<"Empleado cargado con exito"<<endl;

            }

            int opcionEmpleado;
            do {
                menuEmpleado();
                cin >> opcionEmpleado;
                switch (opcionEmpleado) {
                case 1:
                    AgregarCliente();
                    break;
                case 2:
                    EliminarCliente();
                    break;
                case 3:
                    mostrarCLiente();
                    break;
                case 4:
                    generarLista();
                    break;
                case 5:
                    transaccionestodas();
                case 0:
                    cout << "Saliendo del menú empleado..." << endl;
                    break;
                default:
                    cout << "Opción no válida." << endl;
                }
            } while (opcionEmpleado != 0 && tipoUsuario == 2); 
        } else if (tipoUsuario != 0) {
            cout << "Tipo de usuario no válido." << endl;
        }
    } while (tipoUsuario != 0);

    cout << "Saliendo del programa..." << endl;
    return 0;
}
