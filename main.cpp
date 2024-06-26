#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>
#include "banco.h"
#include "tarjeta.h"
#include "clientes.h"
#include "empleado.h"
#include "transacciones.h"
using namespace std;

banco banco1;
Tarjeta nula("Nula", 0);
Tarjeta credix("Credix", 250000);
Tarjeta premium("Platinum", 500000);

void leerArchivoTransacciones() // Funcion para leer el archivo de transacciones y cargarlas al banco, aunque cerremos el programa, las transacciones se mantendran
{
    ifstream archivoTransacciones("/home/francisco/Desktop/Proyecto-ProgramacionII-Rolon-Schiavoni-Taurian/archivos/listaTrans.txt");

    if (!archivoTransacciones.is_open())
    {
        cout << "No se pudo abrir el archivo de transacciones." << endl;
        return;
    }

    string line;
    while (getline(archivoTransacciones, line))
    {
        if (line.find("Dni del cliente:") != string::npos) // Verificar si la línea contiene el DNI del cliente
        {
            // Nueva entrada de transacción
            int dni;
            int tipo;
            int moneda;
            string monedatipo;
            int dia, mes, anio;
            int monto;

            // Leer el dni del cliente
            istringstream iss(line);
            string temp;
            iss >> temp >> temp >> temp >> dni;

            // Leer tipo de transacción
            getline(archivoTransacciones, line);
            tipo = stoi(line.substr(line.find(":") + 2));

            // Leer tipo de moneda
            getline(archivoTransacciones, line);
            monedatipo = line.substr(line.find(":") + 2);
            if (monedatipo == "Pesos")
            {
                moneda = 1;
            }
            else
            {
                moneda = 2;
            }

            // Leer día
            getline(archivoTransacciones, line);
            dia = stoi(line.substr(line.find(":") + 2));

            // Leer mes
            getline(archivoTransacciones, line);
            mes = stoi(line.substr(line.find(":") + 2));

            // Leer año
            getline(archivoTransacciones, line);
            anio = stoi(line.substr(line.find(":") + 2));

            // Leer monto
            getline(archivoTransacciones, line);
            monto = stoi(line.substr(line.find(":") + 2));

            // Crear y configurar transacción
            Transacciones transaccion(dni, tipo, dia, mes, anio);
            transaccion.setMonto(monto);
            transaccion.setMoneda(moneda);
            transaccion.setNum_cliente(dni);
            // Agregar la transacción al banco
            banco1.agregoTransaccion(transaccion);

            // Saltar la línea de separación
            getline(archivoTransacciones, line);
        }
    }

    archivoTransacciones.close();
    cout << "Transacciones cargadas correctamente." << endl;
}

void leerArchivoClientes() // Funcion para leer el archivo de clientes y cargarlos al banco, aunque cerremos el programa, los clientes se mantendran
{
    ifstream archivoClientes("/home/francisco/Desktop/Proyecto-ProgramacionII-Rolon-Schiavoni-Taurian/archivos/listadoClientes.txt");

    if (!archivoClientes.is_open())
    {
        cout << "No se pudo abrir el archivo de clientes." << endl;
        return;
    }

    string line;
    while (getline(archivoClientes, line))
    {
        if (line.find("Cliente n:") != string::npos)
        {
            // Nueva entrada de cliente
            int numcliente;
            string nombre, apellido, tipoCliente;
            int dni, cajaPesos, cajaDolares;

            // Leer el número de cliente
            istringstream iss(line); // istringstream es un flujo de datos que se utiliza para operaciones de entrada en cadenas
            string temp;
            iss >> temp >> temp >> numcliente; // iss permite la manipulación de strings como flujos de datos, similar a cin

            // Leer nombre
            getline(archivoClientes, line);
            nombre = line.substr(line.find(":") + 2);
            nombre.pop_back(); // Remove the trailing period

            // Leer apellido
            getline(archivoClientes, line);
            apellido = line.substr(line.find(":") + 2);
            apellido.pop_back(); // Remove the trailing period

            // Leer dni
            getline(archivoClientes, line);
            dni = stoi(line.substr(line.find(":") + 2));

            // Leer tipo de cliente
            getline(archivoClientes, line);
            tipoCliente = line.substr(line.find(":") + 2);
            tipoCliente.pop_back(); // Remove the trailing period

            // Leer caja en pesos
            getline(archivoClientes, line);
            cajaPesos = stoi(line.substr(line.find(":") + 2));

            // Leer caja en dolares
            getline(archivoClientes, line);
            cajaDolares = stoi(line.substr(line.find(":") + 2));

            // Crear y configurar cliente
            Clientes cliente;
            cliente.setNcliente(numcliente);
            cliente.setNombre(const_cast<char *>(nombre.c_str()));
            cliente.setApellido(const_cast<char *>(apellido.c_str()));
            cliente.setDni(dni);
            cliente.setTipocliente(tipoCliente);
            cliente.setCaja_pesos(cajaPesos);
            cliente.setCaja_dolar(cajaDolares);

            // Agregar el cliente al banco
            banco1.altaClientes(cliente);

            // Saltar la línea de separación
            getline(archivoClientes, line);
        }
    }

    archivoClientes.close();
    cout << "Clientes cargados correctamente." << endl;
}

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
    cout << endl;
    cout << "**********MENU**********" << endl;
    cout << "1) Agregar Cliente" << endl;
    cout << "2) Eliminar Cliente" << endl;
    cout << "3) Mostrar Datos de Cliente" << endl;
    cout << "4) Generar Archivo de clientes" << endl;
    cout << "5) Generar Archivo de transacciones" << endl;
    cout << "6) Ver Transacciones por Mes" << endl;
    cout << "7) Ver Transacciones por Año" << endl;
    cout << "0) Salir" << endl;
    cout << "Ingrese un opcion" << endl;
    cout << "*************************" << endl;
    cout << endl;
}

void menuCliente()
{
    cout << endl;
    cout << "**********MENU**********" << endl;
    cout << "1) Ver mis datos" << endl;
    cout << "2) Ver dinero en cuenta" << endl;
    cout << "3) Realizar una transaccion" << endl;
    cout << "4) Pedir una tarjeta" << endl;
    cout << "5) Ver mis transacciones" << endl;
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

void transaccionxCliente(int dni2) // Funcion para mostrar las transacciones de un cliente
{

    banco1.transaccionCliente(dni2);
}

void transaccionesMes() // Funcion para mostrar las transacciones de un mes
{

    int mes1;
    string checkmes1;
    bool banderames = true;

    do // Ingresar mes de la transacción
    {
        cout << "Ingrese el mes de la transacción: ";
        cin >> checkmes1;

        if (esNumero(checkmes1)) // Verificar si el mes ingresado es un número
        {
            try
            {
                mes1 = stoi(checkmes1); // Convertir la cadena a entero
                cout << "Numero válido: " << mes1 << endl;
                banderames = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderames = false;
            }
        }
        else // Si el mes ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderames = false;
        }
        if (mes1 > 12 || mes1 < 1)
        { // Verificar si el mes ingresado está dentro del rango del mes posible del año
            cout << "Debe ingresar un mes valido" << endl;
            banderames = false;
        }

    } while (banderames == false);
    banco1.transaccionMes(mes1);
    banderames = true;
}

void transaccionesAnio() // Funcion para mostrar las transacciones de un año
{
    int anio;
    bool banderaAnio = true;
    string checkanio;
    do // Ingresar año de la transacción
    {
        cout << "Ingrese el año de la transacción: ";
        cin >> checkanio;

        if (esNumero(checkanio)) // Verificar si el año ingresado es un número
        {
            try
            {
                anio = stoi(checkanio); // Convertir la cadena a entero
                cout << "Numero válido: " << anio << endl;
                banderaAnio = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderaAnio = false;
            }
        }
        else // Si el año ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderaAnio = false;
        }

        if (anio > 2024 || anio < 0)
        { // Verificar si el año ingresado es válido
            cout << "Debe ingresar un Año valido" << endl;
            banderaAnio = false;
        }
        else
        {
            banderaAnio = true;
        }

    } while (banderaAnio == false);
    banco1.transaccionAnio(anio);
    banderaAnio = true;
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
    // int limiteCredito;
    int cantClientes = banco1.getnClientes();
    char nombre[20], apellido[20];
    bool bandera = true;
    string checkdni, checkanio;

    // Ingreso de DNI
    do
    {
        cout << endl;
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
                cout << endl;
                bandera = true;
            }
            catch (const out_of_range &e)
            {
                cout << "DNI inválido. El número está fuera del rango permitido para un entero." << endl;
                cout << endl;
                bandera = false;
            }
        }
        else
        {
            cout << "DNI inválido. Por favor, ingrese solo números." << endl;
            cout << endl;
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
                cout << endl;
                cout << "El apellido puede contener solo letras" << endl;
                cout << "Ingrese nuevamente el apellido" << endl;
                cout << endl;
                cin.getline(apellido, 20, '\n');
            };
        } while (checkletra(nombre) == false);

        // Ingreso de año de ingreso
        do
        {
            cout << endl;
            cout << "Ingrese el año de ingreso" << endl;
            cin >> checkanio;

            // Verificar si el año ingresado es un número
            if (esNumero(checkanio))
            {
                try
                {
                    anioingreso = stoi(checkanio); // Convertir la cadena a entero
                    cout << endl;
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
            if (anioingreso > 2024 || anioingreso < 0)
            { // Verificar si el año ingresado es válido
                cout << "Debe ingresar un Año valido" << endl;
                bandera = false;
            }
        } while (bandera == false);

        int antiguedad = (2024 - anioingreso);
        // Asignacion Tipo de Cliente

        if (antiguedad < 1)
        {
            tipocliente = "Plata";
            // limiteCredito = 0;
        }
        else if (antiguedad >= 1 && antiguedad < 5)
        {
            tipocliente = "Oro";
            // limiteCredito = 250000;
        }
        else if (antiguedad >= 6)
        {
            tipocliente = "Platino";
            // limiteCredito = 500000;
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
    bool banderacliente = true;
    do
    {
        cout << "Ingrese el numero de cliente que quiere dar de baja" << endl;
        cin >> checkncliente;

        if (esNumero(checkncliente))
        {
            try
            {
                nclien = stoi(checkncliente); // Convertir la cadena a entero
                cout << "Numero válido: " << nclien << endl;
                banderacliente = true;
            }
            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
            {
                cout << "NUmero inválido. El número está fuera del rango permitido para un entero." << endl;
                banderacliente = false;
            }
        }
        else // Si el valor ingresado no es un número
        {
            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
            banderacliente = false;
        }
        if (nclien >= banco1.getnClientes())
        {
            cout << "El numero de cliente no exite" << endl;
            banderacliente = false;
        }
    } while (banderacliente == false);

    banco1.bajaClientes(nclien);
    cout << "Cliente dado de baja" << endl;
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

        if (ncliente >= banco1.getnClientes()) // Verificar si el número de cliente ingresado existe
        {
            cout << "El numero de cliente no existe" << endl;
            bandera1 = false;
        }
    } while (bandera1 == false);
    banco1.muestraDatos(ncliente);
}

void generarLista() // Funcion para generar un archivo con los datos de los clientes
{
    banco1.muestraListado();
}

void transaccionestodas() // Funcion para generar archivo con todas las transacciones de los clientes
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
    string checkdia, checkmes, checkanio, checktipo, checkmonto, checkmoneda;

    do // Ingresar dia de la transacción
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
        if (dia > 31 || dia < 1)
        { // Verificar si el dia ingresado está dentro del rango del mes
            cout << "Debe ingresar un dia valido" << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    banderatransaccion = true;

    do // Ingresar mes de la transacción
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
        if (mes > 12 || mes < 1)
        { // Verificar si el mes ingresado está dentro del rango del mes posible del año
            cout << "Debe ingresar un mes valido" << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    banderatransaccion = true;

    do // Ingresar año de la transacción
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

        if (anio > 2024 || anio < 0)
        { // Verificar si el año ingresado es válido
            cout << "Debe ingresar un Año valido" << endl;
            banderatransaccion = false;
        }
        else
        {
            banderatransaccion = true;
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

        if (tipo_transaccion != 1 && tipo_transaccion != 2)
        {
            cout << "Numero de opcion invalido" << endl;
            banderatransaccion = false;
        }

    } while (banderatransaccion == false);

    banderatransaccion = true;

    do
    {
        // Ingresar el monto y la moneda de la transacción
        cout << endl;
        cout << "Seleccione la moneda: " << endl;
        cout << "1) Pesos" << endl;
        cout << "2) Dólares" << endl;
        cin >> checkmoneda;
        cout << endl;

        // validacion moneda
        if (esNumero(checkmoneda)) // Verificar si valor ingresado es un número
        {
            try
            {
                moneda = stoi(checkmoneda); // Convertir la cadena a entero
                cout << "El numero ingresado es válido" << endl;
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

        if (moneda != 1 && moneda != 2)
        {
            cout << "Valor invalido, ingrese una moneda valida" << endl;
            banderatransaccion = false;
        }
        if (moneda == 1)
        {
            cout << "***Ha seleccionado pesos***" << endl;
        }
        if (moneda == 2)
        {
            cout << "***Ha seleccionado dolares***" << endl;
        }
        // fin validacion moneda
    } while (banderatransaccion == false);

    banderatransaccion = true;

    do
    {
        cout << "Ingrese el monto: ";
        cin >> checkmonto;

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

        if (monto < 0)
        {
            cout << "Monto invalido, ingrese un monto valido" << endl;
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
                Transacciones nuevaTransaccion;
                nuevaTransaccion.setNum_cliente(documentocliente);
                nuevaTransaccion.setDia(dia);
                nuevaTransaccion.setMes(mes);
                nuevaTransaccion.setAnio(anio);
                nuevaTransaccion.setTipo(tipo_transaccion);
                nuevaTransaccion.setMonto(monto);
                nuevaTransaccion.setMoneda(moneda);
                banco1.agregoTransaccion(nuevaTransaccion);
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
                Transacciones nuevaTransaccion;
                nuevaTransaccion.setNum_cliente(documentocliente);
                nuevaTransaccion.setDia(dia);
                nuevaTransaccion.setMes(mes);
                nuevaTransaccion.setAnio(anio);
                nuevaTransaccion.setTipo(tipo_transaccion);
                nuevaTransaccion.setMonto(monto);
                nuevaTransaccion.setMoneda(moneda);
                banco1.agregoTransaccion(nuevaTransaccion);
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
            Transacciones nuevaTransaccion;
            nuevaTransaccion.setNum_cliente(documentocliente);
            nuevaTransaccion.setDia(dia);
            nuevaTransaccion.setMes(mes);
            nuevaTransaccion.setAnio(anio);
            nuevaTransaccion.setTipo(tipo_transaccion);
            nuevaTransaccion.setMonto(monto);
            nuevaTransaccion.setMoneda(moneda);
            banco1.agregoTransaccion(nuevaTransaccion);
        }
        else if (moneda == 2) // Realizar el depósito en dólares
        {
            cliente->setCaja_dolar(cliente->getCaja_dolar() + monto); // Aumentar el saldo en dólares
            cout << "Depósito exitoso. Saldo actual en dólares: " << cliente->getCaja_dolar() << endl;
            Transacciones nuevaTransaccion;
            nuevaTransaccion.setNum_cliente(documentocliente);
            nuevaTransaccion.setDia(dia);
            nuevaTransaccion.setMes(mes);
            nuevaTransaccion.setAnio(anio);
            nuevaTransaccion.setTipo(tipo_transaccion);
            nuevaTransaccion.setMonto(monto);
            nuevaTransaccion.setMoneda(moneda);
            banco1.agregoTransaccion(nuevaTransaccion);
        }

        break;

    default:
        cout << "Opcion no valida." << endl;
        break;
    }

    int nclient;
    nclient = cliente->getNumCliente();
    banco1.sobreescbirCliente(nclient, *cliente);
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
    string checktipoUsuario, checkDni;
    bool banderatipoUsuario;
    leerArchivoClientes();
    leerArchivoTransacciones();
    do // Menú principal
    {

        do
        {

            cout << "Ingrese el tipo de usuario (1 para Cliente, 2 para Empleado, 0 para salir): ";
            cin >> checktipoUsuario;

            if (esNumero(checktipoUsuario)) // Verificar si el monto ingresado es un número
            {
                try
                {
                    tipoUsuario = stoi(checktipoUsuario); // Convertir la cadena a entero
                    cout << "Numero válido: " << tipoUsuario << endl;
                    banderatipoUsuario = true;
                }
                catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
                {
                    cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                    banderatipoUsuario = false;
                }
            }
            else // Si el monto ingresado no es un número
            {
                cout << "Numero inválido. Por favor, ingrese solo números." << endl;
                banderatipoUsuario = false;
            }

        } while (banderatipoUsuario == false);

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
                string checkoptionCliente;
                bool banderaoptioncliente;
                do
                {
                    do
                    {
                        menuCliente();
                        cin >> checkoptionCliente;

                        if (esNumero(checkoptionCliente)) // Verificar si el DNI ingresado es un número
                        {
                            try
                            {
                                opcionCliente = stoi(checkoptionCliente); // Convertir la cadena a entero
                                cout << "Numero válido: " << opcionCliente << endl;
                                banderaoptioncliente = true;
                            }
                            catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
                            {
                                cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                                banderaoptioncliente = false;
                            }
                        }
                        else
                        {
                            cout << "Numero inválido. Por favor, ingrese solo números." << endl;
                            banderaoptioncliente = false;
                        }

                    } while (banderaoptioncliente == false);

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
                    case 5:
                        transaccionxCliente(dni);
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
                bool banderanombre = true;
                Empleado e1;

                cout << "Ingrese el Nombre del empleado" << endl;
                cin.ignore();
                cin.getline(ne, 20, '\n');
                // Verificar si el nombre ingresado contiene solo letras
                do
                {
                    if (checkletra(ne) == false)
                    {
                        banderanombre = false;
                        cout << "El nombre puede contener solo letras" << endl;
                        cout << "Ingrese nuevamente el nombre" << endl;
                        cin.getline(ne, 20, '\n');
                    }
                    else
                    {
                        banderanombre = true;
                    }

                } while (banderanombre == false);
                // Fin validacion nombre

                cout << "Ingrese el apellido del empleado" << endl;
                cin.getline(ae, 20, '\n');
                banderanombre = true;
                // Verificar si el apellido ingresado contiene solo letras
                do
                {
                    if (checkletra(ae) == false)
                    {
                        banderanombre = false;
                        cout << "El apellido puede contener solo letras" << endl;
                        cout << "Ingrese nuevamente el apellido" << endl;
                        cin.getline(ae, 20, '\n');
                    }
                    else
                    {
                        banderanombre = true;
                    }
                } while (banderanombre == false);
                // Fin validacion apellido

                do
                {
                    cout << "Ingrese el Dni del empleado" << endl;
                    cin >> checkDni;
                    // Verificar si el DNI ingresado es un número
                    if (esNumero(checkDni)) // Verificar si el DNI ingresado es un número
                    {
                        try
                        {
                            dnie = stoi(checkDni); // Convertir la cadena a entero
                            cout << "Numero válido: " << dnie << endl;
                            banderanombre = true;
                        }
                        catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
                        {
                            cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                            banderanombre = false;
                        }
                    }
                    else
                    {
                        cout << "Numero inválido. Por favor, ingrese solo números." << endl;
                        banderanombre = false;
                    }
                } while (banderanombre == false);
                // Fin validacion DNI

                Empleado empleado1; // Crear un empleado

                // Crear el empleado con los datos ingresados
                empleado1.setNombre(ne);
                empleado1.setApellido(ae);
                empleado1.setDni(dnie);
                empleado1.setnEmpleado(1);
                banco1.incrementarnEmpleados();

                cout << "Empleado cargado con exito" << endl;
            }

            int opcionEmpleado;
            string checkoptionempleado;
            bool banderaopcionE;
            do
            {

                do
                {
                    menuEmpleado();
                    cin >> checkoptionempleado;

                    if (esNumero(checkoptionempleado)) // Verificar si el DNI ingresado es un número
                    {
                        try
                        {
                            opcionEmpleado = stoi(checkoptionempleado); // Convertir la cadena a entero
                            cout << "Numero válido: " << opcionEmpleado << endl;
                            banderaopcionE = true;
                        }
                        catch (const out_of_range &e) // Capturar excepción si el número está fuera del rango permitido
                        {
                            cout << "Numero inválido. El número está fuera del rango permitido para un entero." << endl;
                            banderaopcionE = false;
                        }
                    }
                    else
                    {
                        cout << "Numero inválido. Por favor, ingrese solo números." << endl;
                        banderaopcionE = false;
                    }

                } while (banderaopcionE == false);

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
                    break;
                case 6:
                    transaccionesMes();
                    break;
                case 7:
                    transaccionesAnio();
                    break;
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