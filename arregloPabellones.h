/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloPabellones.h
 * Author: andre
 *
 * Created on 4 de septiembre de 2019, 07:57 PM
 */

#ifndef ARREGLOPABELLONES_H
#define ARREGLOPABELLONES_H

#include <sstream>

#include "pabellon.h"

using namespace std;

class arregloPabellones{
private:
    pabellon** vector;
    int tamano, cantidad;
public:
    arregloPabellones();
    virtual ~arregloPabellones();
    virtual void agregarPabellon(pabellon*);
    virtual pabellon* camaDisponible(char);
    virtual string toString() const;
    virtual pabellon** obtenerVector();
    
}; 

#endif /* ARREGLOPABELLONES_H */

