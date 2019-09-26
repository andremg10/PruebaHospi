/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hospital.h
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 06:12 PM
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "arregloPabellones.h"
#include "arregloEspecialidades.h"
#include "arregloDoctores.h"
#include "arregloCamas.h"
#include "arregloPacientes.h"

#include <iostream>
#include <sstream>

using namespace std;

class hospital{
private:
    arregloEspecialidades* e;
    arregloPabellones* pb;
    arregloDoctores* d;
    arregloCamas* c;
    arregloPacientes* p;
public:
    hospital();
    virtual ~hospital();
    virtual void agregarEspecialidad(especialidad*);
    virtual arregloEspecialidades* obtenerEspecialidades();
    virtual especialidad* buscarEspecialidad(int);
    virtual void agregarPabellon(pabellon*);
    virtual arregloPabellones* obtenerPabellones();
    virtual arregloPabellones* camaDisponible(char);
    virtual void agregarCama(cama*);
    bool agregarCamaPabellon(cama*,int);
    virtual void eliminarCama(int);
    virtual arregloCamas* obtenerCamas();
    virtual void agregarDoctor(doctor*);
    virtual void eliminarDoctor(int);
    virtual arregloDoctores* obtenerDoctores();
    virtual arregloDoctores* buscarDoctor(int);
    bool agregarPacienteDoctor(paciente*, int);
    bool agregarPacienteCama(paciente*, int);
    virtual void agregarPaciente(paciente*);
    virtual arregloPacientes* obtenerPacientes();
    virtual void eliminarPaciente(int);
    virtual paciente* buscarPaciente(int);
}; 

#endif /* HOSPITAL_H */

