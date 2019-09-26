/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloEspecialidades.h
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 09:22 PM
 */

#ifndef ARREGLOESPECIALIDADES_H
#define ARREGLOESPECIALIDADES_H

#include <sstream>
#include <iostream>

#include "especialidad.h"

using namespace std;

class arregloEspecialidades {
private:
    especialidad** vector;
    int tamano, cantidad;
public:
    arregloEspecialidades();
    virtual ~arregloEspecialidades();
    virtual void agregarEspecialidad(especialidad*);
    virtual especialidad* buscarEspecialidad(int);
    virtual string toString() const;
   
}; 

#endif /* ARREGLOESPECIALIDADES_H */

