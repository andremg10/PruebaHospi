/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arregloDoctores.h
 * Author: andre
 *
 * Created on 3 de septiembre de 2019, 11:40 PM
 */

#ifndef ARREGLODOCTORES_H
#define ARREGLODOCTORES_H

#include <sstream>
#include "doctor.h"


class arregloDoctores{
private:
    doctor** vector;
    int tamano, cantidad;
public:
    arregloDoctores();
    virtual ~arregloDoctores();
    virtual void agregarDoctor(doctor*);
    virtual void eliminarDoctor(int);
    virtual doctor* buscarDoctor(int);
    virtual doctor** obtenerVector();
    virtual string toString() const;
    
    
}; 

#endif /* ARREGLODOCTORES_H */

