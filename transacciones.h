#include <iostream>
using namespace std;

class Transacciones{
    
    private: 
    int num_trans;
    int tipo;
    int dia;
    int mes;
    int anio;

    public:
    Transacciones();
    Transacciones(int, int, int, int, int);
    void setNumtrans(int);
    void setTipo(int);
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    int getNumtrans();
    int getTipo();
    int getDia();
    int getMes();
    int getAnio();
   
    
};