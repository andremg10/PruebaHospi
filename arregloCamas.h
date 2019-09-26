/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloCamas.h
 * Author: andre
 *
 * Created on 4 de septiembre de 2019, 03:02 PM
 */

#ifndef ARREGLOCAMAS_H
#define ARREGLOCAMAS_H

#include <sstream>

#include "cama.h"

using namespace std;

class arregloCamas{
private:
    cama** vector;
    int tamano, cantidad;
public:
    arregloCamas();
    virtual ~arregloCamas();
    virtual void agregarCama(cama*);
    virtual void eliminarCama(int);
    virtual cama** obtenerVector();
    virtual cama* buscarCama(int);
    virtual string toString() const;
    
}; 

#endif /* ARREGLOCAMAS_H */

