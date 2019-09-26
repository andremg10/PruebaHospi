/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfaz.h
 * Author: andre
 *
 * Created on 9 de septiembre de 2019, 07:50 PM
 */

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "hospital.h"
#include <iostream>

using namespace std;

class interfaz {
private:
    hospital* _hospital;
public:
    interfaz();
    virtual ~interfaz();
    virtual int mostrarMenuPrincipal();
    virtual void agregarEspecialidad();
    virtual void mostrarEspecialidad();
    virtual void agregarPabellon();
    virtual void mostrarPabellon();
    virtual void agregarCama();
    virtual void mostrarCama();
    virtual void eliminarCama();
    virtual void agregarDoctor();
    virtual void eliminarDoctor();
    virtual void mostrarDoctor();
    virtual void agregarPaciente();
    virtual void eliminarPaciente();
    virtual void mostrarPaciente();
    virtual void iniciar();
    virtual int pedirOpcion();
    virtual void cambiarCama();
    virtual void cambiarDoctor();
    virtual void informePaciente();
    
};



#endif /* INTERFAZ_H */

