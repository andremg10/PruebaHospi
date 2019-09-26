/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   paciente.cpp
 * Author: andre
 *
 * Created on 5 de septiembre de 2019, 05:54 PM
 */

#include <cstdlib>

#include "paciente.h"

paciente::paciente() {

}

paciente::paciente(string nombre, string apellido, string direccion, 
        string prioridad, string tipoCirugia, string fecha, char genero, especialidad* esp, 
        doctor* doc, cama* cam): 
        nombre(nombre), apellido(apellido), direccion(direccion), 
        prioridad(prioridad), tipoCirugia(tipoCirugia), fecha(fecha), genero(genero),
        esp(esp), doc(doc), cam(cam) {
}
   
paciente::~paciente() {
    delete esp;
}

void paciente::fijarDoctor(doctor* d) {
    doc=d;
}

void paciente::fijarCama(cama* c) {
    cam=c;
}



string paciente::toString() const{
    stringstream s;
    s<<"Nombre: "<<nombre<<endl;
    s<<"Apellido: "<<apellido<<endl;
    s<<"Direccion: "<<direccion<<endl;
    s<<"Prioridad: "<<prioridad<<endl;
    s<<"Fecha: "<<nombre<<endl;
    s<<"Genero: "<<genero<<endl;
    s<<"Especialidad: "<<esp->obtenerNombre()<<endl;
    s<<"Doctor: "<<doc<<endl;
    s<<"Cama: "<<cam<<endl;
    return s.str();   
}