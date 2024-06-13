#ifndef PERSONA_H // Si no esta definida la clase persona.h
#define PERSONA_H // Definir la clase persona.h

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