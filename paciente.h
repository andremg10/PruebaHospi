/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   paciente.h
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 06:12 PM
 */

#ifndef PACIENTE_H
#define PACIENTE_H

#include "arregloEspecialidades.h"

#include <sstream>
#include <iostream>

class cama;
class doctor;

using namespace std;

class paciente{
private:
    string nombre;
    string apellido;
    string direccion;
    string prioridad;
    string fecha;
    string tipoCirugia;
    char genero;
    especialidad* esp;
    cama* cam;
    doctor* doc;
public:
    paciente();
    paciente(string, string, string, string, string, string, char, especialidad*, doctor*, cama*);
    virtual ~paciente();
    virtual void fijarDoctor(doctor*);
    virtual void fijarCama(cama*);
    virtual string toString() const;
}; 

#endif /* PACIENTE_H */

