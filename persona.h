#ifndef PERSONA_H
#define PERSONA_H

#include<iostream>
using namespace std;

class Persona
{
private:
    char nombre[20];
    char apellido[20];
    int dni;

public:
    Persona();
    Persona(char[],char[],int);
    void setNombre(char[]);
    void setApellido(char[]);
    void setDni(int);
    char *getNombre();
    char *getApellido();
    int getDni();
};

#endif