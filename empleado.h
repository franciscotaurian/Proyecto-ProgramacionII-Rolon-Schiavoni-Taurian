#include "persona.h"

class Empleado:public Persona{
    private:
        int nEmpleado;
    public:
        Empleado();
        void setnEmpleado(int);
        int getnEmpleado();
};