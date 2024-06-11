#include <iostream>
#include "transacciones.h"
using namespace std;

class Clientes{

    private:
    int numcliente;
    char nombre[20];
    char apellido[20];
    int dni;
    string tipocliente;
    int anioingreso;
    string estado;
    Transacciones trans_clientes[100];
    int caja_pesos;
    int caja_dolar;

    public:
    Clientes();
    Clientes(int, int, string, int, string, char[], char[]);
        void setNombre(char[]);
        void setApellido(char[]);
        void setDni(int);
        void setAnioingreso(int);
        void setCaja_pesos(int);
        void setCaja_dolar(int);
        void setEstado(string);
        void setTipocliente(string);
        char *getNombre();
        char *getApellido();
        int getDni();
        int getAnioingreso();
        int getCaja_pesos();
        int getCaja_dolar();
        string getEstado();
        string getTipocliente();
        Transacciones *gettransacciones();
        void muestra_datosclien();
        void consultar_saldo();
        void hacer_transaccion();
        void solic_tarj();
        void pedir_baja();


};




