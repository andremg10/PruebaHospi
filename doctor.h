/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   doctor.h
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 06:10 PM
 */

#ifndef DOCTOR_H
#define DOCTOR_H

#include "arregloPacientes.h"
#include "arregloEspecialidades.h"

#include <sstream>
#include <iostream>

using namespace std;

class doctor {
private:
    string nombre;
    especialidad* especialidadDoctor;
    arregloPacientes* pacienteDoctor;
public:
    doctor();
    doctor(string,especialidad*);
    virtual ~doctor();
    virtual void agregarPacienteDoctor(paciente*);
    virtual arregloPacientes* obtenerPacienteDoctor();
    virtual string toString();
}; 


#endif /* DOCTOR_H */

