/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pabellon.h
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 06:11 PM
 */

#ifndef PABELLON_H
#define PABELLON_H
#include "arregloCamas.h"
#include <sstream>
#include <iostream>

using namespace std;

class pabellon{
private:
    char letra;
    char genero;
    arregloCamas* camaPabellon;
public:
    pabellon();
    pabellon(char, char);
    virtual ~pabellon();
    virtual char obtenerLetra();
    virtual char obtenerGenero();
    virtual void agregarCamaPabellon(cama*);
    virtual arregloCamas* obtenerCamaPabellon();
    virtual string toString() const;
}; 

#endif /* PABELLON_H */

