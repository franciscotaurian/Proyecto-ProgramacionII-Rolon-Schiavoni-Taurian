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
Tarjeta nula("Nula", 0);
Tarjeta credix("Credix", 25000);
Tarjeta premium("Platinum", 50000);

bool checkletra(char array[]) // Funcion para verificar si el nombre y apellido contienen solo letras
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
    cout << "5) Ver todas las transacciones de los clientes" << endl;
    cout << "0) Salir" << endl;
    cout << "Ingrese un opcion" << endl;
    cout << "*************************" << endl;
    cout << endl;
}

void menuCliente()
{
    cout << "**********MENU**********" << endl;
    cout << "1) Ver mis datos" << endl;
    cout << "2) Ver dinero en cuenta" << endl;
    cout << "3) Realizar una transaccion" << endl;
    cout << "4) Pedir una tarjeta" << endl;
    cout << "0) Salir" << endl;
    cout << "Ingrese un opcion" << endl;
    cout << "*************************" << endl;
    cout << endl;
}

bool esNumero(const string &str) // Funcion para verificar si el DNI ingresado es un número
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0) // isdigit verifica si el caracter es un número
            return false;
    }
    return true;
}

bool clienteExistente(int _dni) // Funcion para verificar si el cliente ya existe
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

void AgregarCliente() // Funcion para agregar un cliente
{
    int dni, anioingreso;
    string tipocliente;
    int limiteCredito;
    int cantClientes = banco1.getnClientes();
    char nombre[20], apellido[20];
    bool bandera = true;
    string checkdni, checkanio;

    // Ingreso de DNI
    do
    {
        cout << "Ingrese el Dni del cliente" << endl;
        cin >> checkdni;
        cout << endl;

        // Verificar si el DNI ingresado es un número
        if (esNumero(checkdni))
        {
            try
            {
                dni = stoi(checkdni); // Convertir la cadena a entero
                cout << "DNI válido: " << dni << endl;
                bandera = true;
            }
            catch (const out_of_range &e)
            {
                cout << "DNI inválido. El número está fuera del rango permitido para un entero." << endl;
                bandera = false;
            }
        }
        else
        {
            cout << "DNI inválido. Por favor, ingrese solo números." << endl;
            bandera = false;
        }

    } while (bandera == false);

    // Verificar si el cliente ya existe
    if (clienteExistente(dni) == true)
    {
        cout << "El cliente que desea agregar ya existe" << endl;
    }
    else
    {
        // Ingreso de nombre y apellido del cliente
        do
        {
            cout << endl;
            cout << "Ingrese el nombre" << endl;
            cin.ignore();
            cin.getline(nombre, 20, '\n');
            // Verificar si el nombre ingresado contiene solo letras
            if (checkletra(nombre) == false)
            {
                cout << "El nombre puede contener solo letras" << endl;
                cout << "Ingrese nuevamente el nombre" << endl;
                cin.getline(nombre, 20, '\n');
            };
        } while (checkletra(nombre) == false);

        do
        {
            cout << endl;
            cout << "Ingrese el Apellido" << endl;
            cin.getline(apellido, 20, '\n');
            // Verificar si el apellido ingresado contiene solo letras
            if (checkletra(apellido) == false)
            {
                cout << "El apellido puede contener solo letras" << endl;
                cout << "Ingrese nuevamente el apellido" << endl;
                cin.getline(apellido, 20, '\n');
            };
        } while (checkletra(nombre) == false);

        // Ingreso de año de ingreso
        do
        {
            cout << endl;
            cout << "Ingrese el anio de ingreso" << endl;
            cin >> checkanio;

            // Verificar si el año ingresado es un número
            if (esNumero(checkanio))
            {
                try
                {
                    anioingreso = stoi(checkanio); // Convertir la cadena a entero
                    cout << "Año válido: " << anioingreso << endl;
                    bandera = true;
                }
                catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
                {
                    cout << "Año inválido. El número está fuera del rango permitido para un entero." << endl;
                    bandera = false;
                }
            }
            else // Si el año ingresado no es un número
            {
                cout << "Año inválido. Por favor, ingrese solo números." << endl;
                bandera = false;
            }
        } while (bandera == false);

        int antiguedad = (2024 - anioingreso);
        // Asignacion Tipo de Cliente

        if (antiguedad < 1)
        {
            tipocliente = "Plata";
            limiteCredito = 0;
        }
        else if (antiguedad >= 1 && antiguedad < 5)
        {
            tipocliente = "Oro";
            limiteCredito = 25000;
        }
        else if (antiguedad >= 6)
        {
            tipocliente = "Platino";
            limiteCredito = 50000;
        }

        // Crear el cliente
        Clientes cliente;
        cliente.setNcliente(cantClientes);
        cliente.setNombre(nombre);
        cliente.setApellido(apellido);
        cliente.setDni(dni);
        cliente.setAnioingreso(anioingreso);
        cliente.setTipocliente(tipocliente);

        banco1.altaClientes(cliente);
        cout << endl;
        cout << "Cliente cargado con exito********" << endl;
        cout << "El numero asignado al nuevo cliente es: " << (banco1.getnClientes() - 1) << endl;
        cout << endl;
    }
}

void EliminarCliente() // Funcion para dar de baja un cliente
{
    string checkncliente;
    int nclien;
    cout << "Ingrese el numero de cliente que quiere dar de baja" << endl;
    cin >> checkncliente;

    banco1.bajaClientes(nclien);
}

void mostrarCliente() // Funcion para mostrar los datos de un cliente
{
    int ncliente;
    string checkcliente;
    bool bandera1 = true;
    do
    {
        cout << endl;
        cout << "Ingrese el numero de Cliente" << endl;
        cin >> checkcliente;

        if (esNumero(checkcliente)) // Verificar si el número ingresado es un número
        {
            try
            {
                ncliente = stoi(checkcliente); // Convertir la cadena a entero
                cout << "Numero válido: " << ncliente << endl;
                bandera1 = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                bandera1 = false;
            }
        }
        else // Si el número ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            bandera1 = false;
        }

    } while (bandera1 == false);

    if (ncliente >= banco1.getnClientes()) // Verificar si el número de cliente ingresado existe
    {
        cout << "El numero de cliente no existe" << endl;
    }
    else // Si el número de cliente ingresado existe, mostrar los datos del cliente
    {
        cout << endl;
        banco1.muestraDatos(ncliente);
    }
}

void generarLista() // Funcion para generar un archivo con los datos de los clientes
{
    banco1.muestraListado();
}

void transaccionestodas() // Funcion para mostrar todas las transacciones de los clientes
{
    banco1.muestraTransacciones();
}

void hacerTransaccion(Clientes *cliente) // Funcion para realizar una transacción
{
    int documentocliente = cliente->getDni();
    if (cliente == nullptr) // Verificar si el cliente existe
    {
        cout << "El cliente no existe." << endl;
        return;
    }

    int tipo_transaccion, moneda;
    float monto;
    int dia, mes, anio;
    bool banderatransaccion;
    string checkdia, checkmes, checkanio, checktipo, checkmonto;
    do
    {
        cout << "Ingrese el día de la transacción: ";
        cin >> checkdia;

        if (esNumero(checkdia)) // Verificar si el día ingresado es un número
        {
            try
            {
                dia = stoi(checkdia); // Convertir la cadena a entero
                cout << "Numero válido: " << dia << endl;
                banderatransaccion = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderatransaccion = false;
            }
        }
        else // Si el día ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    banderatransaccion = true;

    do
    {
        cout << "Ingrese el mes de la transacción: ";
        cin >> checkmes;

        if (esNumero(checkmes)) // Verificar si el mes ingresado es un número
        {
            try
            {
                mes = stoi(checkmes); // Convertir la cadena a entero
                cout << "Numero válido: " << mes << endl;
                banderatransaccion = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderatransaccion = false;
            }
        }
        else // Si el mes ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    banderatransaccion = true;

    do
    {
        cout << "Ingrese el año de la transacción: ";
        cin >> checkanio;

        if (esNumero(checkanio)) // Verificar si el año ingresado es un número
        {
            try
            {
                anio = stoi(checkanio); // Convertir la cadena a entero
                cout << "Numero válido: " << anio << endl;
                banderatransaccion = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderatransaccion = false;
            }
        }
        else // Si el año ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    banderatransaccion = true;

    do
    {
        cout << "Ingrese (1) para hacer una extracción y (2) para hacer un deposito: ";
        cin >> checktipo;

        if (esNumero(checktipo)) // Verificar si el tipo de transacción ingresado es un número
        {
            try
            {
                tipo_transaccion = stoi(checktipo); // Convertir la cadena a entero
                cout << "Numero válido: " << tipo_transaccion << endl;
                banderatransaccion = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderatransaccion = false;
            }
        }
        else // Si el tipo de transacción ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderatransaccion = false;
        }

        if (tipo_transaccion != 1 || tipo_transaccion != 2)
        {
            cout << "Numero de opcion invalido" << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    banderatransaccion = true;

    // Crear la transaccion con los datos ingresados
    Transacciones nuevaTransaccion;
    nuevaTransaccion.setNum_cliente(documentocliente);
    nuevaTransaccion.setDia(dia);
    nuevaTransaccion.setMes(mes);
    nuevaTransaccion.setAnio(anio);
    nuevaTransaccion.setTipo(tipo_transaccion);

    // Ingresar el monto y la moneda de la transacción
    cout << "Seleccione la moneda: " << endl;
    cout << "1) Pesos" << endl;
    cout << "2) Dólares" << endl;
    cin >> moneda;

    do
    {
        cout << "Ingrese el monto: ";
        cin >> checkmonto;
        nuevaTransaccion.setMonto(monto);

        if (esNumero(checkmonto)) // Verificar si el monto ingresado es un número
        {
            try
            {
                monto = stoi(checkmonto); // Convertir la cadena a entero
                cout << "Numero válido: " << monto << endl;
                banderatransaccion = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderatransaccion = false;
            }
        }
        else // Si el monto ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    switch (tipo_transaccion)
    {
    case 1: // Extracción
        if (moneda == 1)
        {
            if (cliente->getCaja_pesos() >= monto) // Verificar si el cliente tiene suficientes fondos en pesos
            {
                cliente->setCaja_pesos(cliente->getCaja_pesos() - monto);
                cout << "Extracción exitosa. El saldo actual en pesos es: " << cliente->getCaja_pesos() << endl;
            }
            else
            {
                cout << "Fondos insuficientes en pesos." << endl;
            }
        }
        else if (moneda == 2) // Verificar si el cliente tiene suficientes fondos en dólares
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

    case 2:              // Depósito
        if (moneda == 1) // Realizar el depósito en pesos
        {
            cliente->setCaja_pesos(cliente->getCaja_pesos() + monto); // Aumentar el saldo en pesos
            cout << "Depósito exitoso. Saldo actual en pesos: " << cliente->getCaja_pesos() << endl;
        }
        else if (moneda == 2) // Realizar el depósito en dólares
        {
            cliente->setCaja_dolar(cliente->getCaja_dolar() + monto); // Aumentar el saldo en dólares
            cout << "Depósito exitoso. Saldo actual en dólares: " << cliente->getCaja_dolar() << endl;
        }
        break;

    default:
        cout << "Opcion no valida." << endl;
        break;
    }
    // Agregar la transacción al cliente
    nuevaTransaccion.setMonto(monto);
    banco1.agregoTransaccion(nuevaTransaccion);
}

void verDatos(Clientes *cli)
{

    cout << "Datos del Cliente:" << endl;
    cout << "Nombre: " << cli->getNombre() << endl;
    cout << "Apellido: " << cli->getApellido() << endl;
    cout << "DNI: " << cli->getDni() << endl;
    cout << "Tipo de Cliente: " << cli->getTipocliente() << endl;
}

void pedirTrajeta(Clientes *cli) // Funcion para asignar una tarjeta al cliente
{
    int anioingreso = cli->getAnioingreso();

    string tipocliente;
    string tipotarjeta;
    int limiteCredito;

    int antiguedad = 2024 - anioingreso;
    if (antiguedad < 1) // Asignar tarjeta Nula
    {

        tipocliente = "Plata";
        cli->setTipotarjeta(nula);
        cout << "Se le ha asignado la tarjeta: " << cli->getTipotarjeta().getTipotarj() << endl;
        cout << "Su límite de credito es: " << cli->getTipotarjeta().getLimiteCredito() << endl;
    }
    else if (antiguedad >= 1 && antiguedad < 5) // Asignar tarjeta Credix
    {
        tipocliente = "Oro";
        cli->setTipotarjeta(credix);
        cout << "Se le ha asignado la tarjeta " << cli->getTipotarjeta().getTipotarj() << endl;
        cout << "Su límite de credito es: " << cli->getTipotarjeta().getLimiteCredito() << endl;
    }
    else // Asignar tarjeta Platinum
    {
        tipocliente = "Platino";
        cli->setTipotarjeta(premium);
        cout << "Se le ha asignado la tarjeta " << cli->getTipotarjeta().getTipotarj() << endl;
        cout << "Su límite de credito es: " << cli->getTipotarjeta().getLimiteCredito() << endl;
    }
}

Clientes *clienteExiste(int _dni) // Funcion para verificar si el cliente existe
{
    Clientes *c = banco1.getlistado();
    int cantClientes = banco1.getnClientes();
    for (int i = 0; i < cantClientes; i++)
    {
        if (c[i].getDni() == _dni)
        {
            return &c[i]; // Devolver el puntero al cliente si se encuentra
        }
    }
    return nullptr; // Devolver un puntero nulo si no se encuentra
}

int main() // Función principal
{
    int tipoUsuario;
    char nombreB[20], direccionB[20];
    cout << "Ingrese el nombre del banco: ";
    cin.ignore();
    cin.getline(nombreB, 20);
    cout << "Ingrese la dirección del banco: ";
    cin.getline(direccionB, 20);

    do // Menú principal
    {
        cout << "Ingrese el tipo de usuario (1 para Cliente, 2 para Empleado, 0 para salir): ";
        cin >> tipoUsuario;

        if (tipoUsuario == 1) // Menú cliente
        {
            string dnicheck;
            bool banderadni = true;
            int dni;

            do
            {

                cout << "Ingrese su DNI: ";
                cin >> dnicheck;

                if (esNumero(dnicheck)) // Verificar si el DNI ingresado es un número
                {
                    try
                    {
                        dni = stoi(dnicheck); // Convertir la cadena a entero
                        cout << "Numero válido: " << dni << endl;
                        banderadni = true;
                    }
                    catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
                    {
                        cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                        banderadni = false;
                    }
                }
                else
                {
                    cout << "Numero inválido. Por favor, ingrese solo números." << endl;
                    banderadni = false;
                }

            } while (banderadni == false);

            Clientes *clienteActual = clienteExiste(dni); // Crear un puntero al cliente si existe
            if (clienteActual != nullptr)
            { // nullptr es un puntero nulo
                int opcionCliente;
                do
                {
                    menuCliente();
                    cin >> opcionCliente;
                    switch (opcionCliente)
                    {
                    case 1: // Ver datos del cliente
                        verDatos(clienteActual);
                        break;
                    case 2: // Ver dinero en cuenta
                        cout << "Dinero en cuenta:" << endl;
                        cout << "Pesos: " << clienteActual->getCaja_pesos() << endl;
                        cout << "Dólares: " << clienteActual->getCaja_dolar() << endl;
                        break;
                    case 3: // Realizar una transacción
                        hacerTransaccion(clienteActual);
                        break;
                    case 4: // Pedir una tarjeta
                        pedirTrajeta(clienteActual);
                        break;
                    case 0: // Salir
                        cout << "Saliendo del menú cliente..." << endl;
                        break;
                    default:
                        cout << "Opción no válida" << endl;
                        break;
                    }
                } while (opcionCliente != 0 && tipoUsuario == 1); // Permanece en el menú cliente hasta que se elija salir
            }
            else
            {
                cout << "El cliente no existe." << endl;
            }
        }
        else if (tipoUsuario == 2) // Menú empleado
        {

            if (banco1.getnEmpleado() == 0) // Crear un empleado si no existe
            {
                char ne[20], ae[20];
                int dnie;
                Empleado e1;
                cout << "Ingrese el Nombre del empleado" << endl;
                cin.ignore();
                cin.getline(ne, 20, '\n');
                cout << "Ingrese el apellido del empleado" << endl;
                cin.getline(ae, 20, '\n');
                cout << "Ingrese el Dni del empleado" << endl;
                cin >> dnie;

                Empleado empleado1;

                // Crear el empleado con los datos ingresados
                empleado1.setNombre(ne);
                empleado1.setApellido(ae);
                empleado1.setDni(dnie);
                empleado1.setnEmpleado(1);
                banco1.incrementarnEmpleados();

                cout << "Empleado cargado con exito" << endl;
            }

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
                    mostrarCliente();
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
        }
        else if (tipoUsuario != 0)
        {
            cout << "Tipo de usuario no válido." << endl;
        }
    } while (tipoUsuario != 0);

    cout << "Saliendo del programa..." << endl;
    return 0;
}
