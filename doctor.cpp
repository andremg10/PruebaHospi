/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   doctor.cpp
 * Author: andre
 *
 * Created on 2 de septiembre de 2019, 10:09 PM
 */

#include <cstdlib>

#include "doctor.h"

doctor::doctor() {

}

doctor::doctor(string nombre,especialidad* especialidadDoctor)
: nombre(nombre), especialidadDoctor(new especialidad()) {
    
    pacienteDoctor = new arregloPacientes();
}

void doctor::agregarPacienteDoctor(paciente* p){
    pacienteDoctor->agregarPaciente(p);
}

arregloPacientes* doctor::obtenerPacienteDoctor() {
    return pacienteDoctor;
}


string doctor::toString(){
    stringstream s;
    s<<"Nombre: "<<nombre<<endl;
    s<<"Especialidad: "<<especialidadDoctor<<endl;
    s<<"Pacientes: "<<pacienteDoctor<<endl;
    return s.str(); 
    
}

doctor::~doctor() {
    delete especialidadDoctor;
    delete pacienteDoctor;
}

