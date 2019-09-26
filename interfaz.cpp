/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   interfaz.cpp
 * Author: andre
 *
 * Created on 9 de septiembre de 2019, 08:31 PM
 */

#include <cstdlib>
#include<stdlib.h>
#include <valarray>

#include "interfaz.h"

interfaz::interfaz(): _hospital(new hospital()) {
}

interfaz::~interfaz() {
}

void interfaz::agregarEspecialidad() {
    string nombre;
    cout<<"Digite la especialidad:" ;
    cin>>nombre;
    especialidad* e = new especialidad(nombre);
    _hospital->agregarEspecialidad(e);
}
void interfaz::mostrarEspecialidad(){
    cout<<"Lista de especialidades"<<endl;
    cout<<_hospital->obtenerEspecialidades()->toString()<<endl;
}

void interfaz::agregarPabellon() {
    char letra;
    char genero;
    cout<<"Digite la letra del pabellon:" ;
    cin>>letra;
    cout<<"Digite el genero del pabellon(F o M):" ;
    cin>>genero; 
    pabellon* pb = new pabellon(letra, genero);
    _hospital->agregarPabellon(pb);
    }

void interfaz::mostrarPabellon() {
    cout<<"Lista de pabellones"<<endl;
    cout<<_hospital->obtenerPabellones()->toString()<<endl;
}


void interfaz::agregarCama() {
    int numero;
    cama* c;
    pabellon* pb;
    cout<<"Digite el numero de cama:" ;
    cin>>numero;
    mostrarPabellon();
    cout<<"Digite la posicion del pabellon:" ;
    cin>>numero;
    
    while(!_hospital->agregarCamaPabellon(c,numero-1)){
        cout<<"Digite la posicion del pabellon:" ;
        cin>>numero;
    }
    cout<<"Cama insertada en el pabellón que esta en la posicion"<<numero<<endl;
    
    c= new cama(numero);
    _hospital->agregarCama(c); 
}

void interfaz::mostrarCama(){
    cout<<"Lista de camas"<<endl;
    cout<<_hospital->obtenerCamas()->toString()<<endl;
} 

void interfaz::agregarDoctor() {
    string nombre;
    int posicionEspecialidad;
    especialidad* esp;
    doctor* doc;
    cout <<"Digite el nombre del doctor: " <<endl;
    cin>>nombre;
    cout<<_hospital->obtenerEspecialidades()->toString()<<endl;
    cout<<"Digite la posicion de la especialidad que desea"<<endl;
    cin>>posicionEspecialidad;
    esp = _hospital->buscarEspecialidad(posicionEspecialidad);
    doc = new doctor(nombre, esp);
    _hospital->agregarDoctor(doc);
}

void interfaz::mostrarDoctor(){
    cout<<"Lista de doctores"<<endl;
    cout<<_hospital->obtenerDoctores()->toString()<<endl;
}


void interfaz::agregarPaciente() {
    int posicion;
    int pos, posi;
    string nombrePaciente, apellidos, direccion, prioridad, tipoCirugia, fecha;
    char genero;
    especialidad* esp;
    paciente* pac;
    arregloPabellones* pb;
    
    
    cout<<"Digite el nombre del paciente: "<<endl;
    cin>>nombrePaciente; 
    
    cout<<"Digite los dos apellidos del paciente: "<<endl;
    cin>>apellidos; 
    
    cout<<"Digite la direccion: "<<endl;
    cin>>direccion; 
    
    cout<<"Digite la prioridad del paciente(baja, media o critica): "<<endl;
    cin>>prioridad; 
    
    cout<<"Digite el tipo de cirugia: "<<endl;
    cin>>tipoCirugia; 
    
    cout<<"Digite la fecha de la cirugia: "<<endl;
    cin>>fecha; 
    
    cout<<"Digite el genero del paciente(F o M): "<<endl;
    cin>>genero;
    pb = _hospital->camaDisponible(genero);
    
    cout<<_hospital->obtenerEspecialidades()->toString()<<endl;
    cout<<"Digite la posicion de la especialidad: "<<endl;
    cin>>posicion;
    esp = _hospital->buscarEspecialidad(posicion+1);
    
    mostrarDoctor();
    cout<<"Digite la posicion del doctor:" ;
    cin>>pos;
    
    while(!_hospital->agregarPacienteDoctor(pac,pos-1)){
        cout<<"Digite la posicion del doctor:" ;
        cin>>pos;
    }
    cout<<"Posicion del doctor asignado al paciente "<<pos<<endl;
    doctor* d=_hospital->obtenerDoctores()->buscarDoctor(pos);  
    mostrarCama();
    
    cout<<"Digite la posicion de la cama:" ;
    cin>>posi;
    
    while(!_hospital->agregarPacienteCama(pac,posi-1)){
        cout<<"Digite la posicion de la cama:" ;
        cin>>posi;
    }
    
    cout<<"Posicion de la cama asignada al paciente "<<posi<<endl;
    cama* c=_hospital->obtenerCamas()->buscarCama(posi);
    
    c->cambiarEstado();
    
    pac = new paciente(nombrePaciente, apellidos, direccion, prioridad, 
            tipoCirugia, fecha, genero, esp, d, c);
    
    d->agregarPacienteDoctor(pac);
    c->agregarPacienteCama(pac);
    
    _hospital->agregarPaciente(pac);
}

void interfaz::mostrarPaciente() {
    cout<<"Lista de pacientes"<<endl;
    cout<<_hospital->obtenerPacientes()->toString()<<endl;
}


void interfaz::eliminarCama() {
    int pos;
    cout<<_hospital->obtenerCamas()->toString()<<endl;
    cout<<"Digite la posicion de la cama que desea eliminar: ";
    cin>>pos; 
    _hospital->eliminarCama(pos-1);
    cout<<"Nueva lista"<<endl;
    cout<<_hospital->obtenerCamas()->toString()<<endl;
}

void interfaz::eliminarDoctor() {
    int pos;
    cout<<_hospital->obtenerDoctores()->toString()<<endl;
    cout<<"Digite la posicion del doctor que desea eliminar: ";
    cin>>pos; 
    _hospital->eliminarDoctor(pos-1);
    cout<<"Nueva lista"<<endl;
    cout<<_hospital->obtenerDoctores()->toString()<<endl;
}
    

void interfaz::eliminarPaciente() {
    int pos;
    cout<<_hospital->obtenerPacientes()->toString()<<endl;
    cout<<"Digite la posicion del paciente que desea eliminar: ";
    cin>>pos; 
    _hospital->eliminarPaciente(pos-1);
    cout<<"Nueva lista"<<endl;
    cout<<_hospital->obtenerPacientes()->toString()<<endl;
}

void interfaz::cambiarCama() {
    int pos;
    paciente* p;
    mostrarCama();
    cout << "Digite la posicion de la cama por la que desea cambiar: ";
    cin >> pos;
    cama* c=_hospital->obtenerCamas()->buscarCama(pos); 
    p->fijarCama(c);

}

void interfaz::cambiarDoctor() {
    int pos;
    paciente* p;
    mostrarDoctor();
    cout << "Digite la posicion del doctor por el que desea cambiar: ";
    cin >> pos;
    doctor* d=_hospital->obtenerDoctores()->buscarDoctor(pos); 
    p->fijarDoctor(d);
    
}

void interfaz::informePaciente(){
    paciente* p;
    int posicion;
    cout<<_hospital->obtenerPacientes()->toString()<<endl;
    cout<<"Digite la posicion del paciente: "<<endl;
    cin>>posicion;
    p = _hospital->buscarPaciente(posicion);
    cout<<p->toString()<<endl;
}


int interfaz::mostrarMenuPrincipal() {;
    cout<<"Menu Principal"<<endl;
    cout<<"1. Administrar especialidades"<<endl;
    cout<<"2. Administrar pabellones"<<endl;
    cout<<"3. Administrar camas"<<endl;
    cout<<"4. Administrar doctores"<<endl;
    cout<<"5. Administrar pacientes"<<endl;
    cout<<"6. Salir"<<endl;
}

int interfaz::pedirOpcion() {
    int opcion;
    cout<<"Digite opcion:"<<endl;
    cin>>opcion;
    return opcion;
}


void interfaz::iniciar() {
    int opcion, opcion1, opcion2, opcion3, opcion4, opcion5;
    do{
        
        mostrarMenuPrincipal();
        opcion=pedirOpcion();
        
        switch(opcion){
            case 1:
                do{
                    
                    cout<<"Menu de especialidades"<<endl;
                    cout<<"1. Agregar especialidad"<<endl;
                    cout<<"2. Mostrar especialidades"<<endl;
                    cout<<"3. Salir"<<endl;
                    cout<<"Digite opcion: ";
                    cin>>opcion1;
                    switch(opcion1){
                        case 1: agregarEspecialidad();
                        break;
                        
                        case 2: mostrarEspecialidad();
                        break;
                        
                        case 3: break;
                        
                        default:
                            cout<<"Error"<<endl;
                        break;
                    }
                } while(opcion1>=1 && opcion1<3);
                break;
                
            case 2:
                do{
                    
                    cout<<"Menu de pabellones"<<endl;
                    cout<<"1. Agregar pabellon"<<endl;
                    cout<<"2. Mostrar pabellones"<<endl;
                    cout<<"3. Salir"<<endl;
                    cout<<"Digite opcion: ";
                    cin>>opcion2;
                    switch(opcion2){
                        case 1: agregarPabellon();
                        break;
                        
                        case 2: mostrarPabellon();
                        break;
                        
                        case 3: break;
                       
                        default:
                            cout<<"Error"<<endl;
                        break;
                    }
                }while(opcion2>=1 && opcion2<3);
                break;
                
            case 3:
                do{
                   
                    cout<<"Menu de camas"<<endl;
                    cout<<"1. Agregar cama"<<endl;
                    cout<<"2. Eliminar cama"<<endl;
                    cout<<"3. Mostrar camas"<<endl;
                    cout<<"4. Salir"<<endl;
                    cout<<"Digite opcion: ";
                    cin>>opcion3;
                    switch(opcion3){
                        case 1: agregarCama();
                        break;
                        
                        case 2: eliminarCama();
                        break;
                        
                        case 3: mostrarCama();
                        break;
                        
                        case 4: break;
                        
                        default:
                            cout<<"Error"<<endl;
                        break;
                    }
                }while(opcion3>=1 && opcion3<4);
                break;
                
            case 4:
                do{
                    
                    cout<<"Menu de doctores"<<endl;
                    cout<<"1. Agregar doctor"<<endl;
                    cout<<"2. Eliminar doctor"<<endl;
                    cout<<"3. Mostrar doctores"<<endl;
                    cout<<"4. Salir"<<endl;
                    cout<<"Digite opcion: ";
                    cin>>opcion4;
                    switch(opcion4){
                        case 1: agregarDoctor();
                        break;
                        
                        case 2: eliminarDoctor();
                        break;
                        
                        case 3: mostrarDoctor();
                        break;
                        
                        case 4: break;
                        
                        default:
                            cout<<"Error"<<endl;
                        break;
                    }
                }while(opcion4>=1 && opcion4<4);
                break;
                    
            case 5:
                do{
                    
                    cout<<"Menu de pacientes"<<endl;
                    cout<<"1. Agregar paciente"<<endl;
                    cout<<"2. Eliminar paciente"<<endl;
                    cout<<"3. Mostrar pacientes"<<endl;
                    cout<<"4. Cambiar doctor de paciente"<<endl;
                    cout<<"5. Cambiar cama de paciente"<<endl;
                    cout<<"6. Informe de paciente"<<endl;
                    cout<<"7. Salir"<<endl;
                    cout<<"Digite opcion: ";
                    cin>>opcion5;
                    switch(opcion5){
                        case 1: agregarPaciente();
                        break;
                        
                        case 2: eliminarPaciente();
                        break;
                        
                        case 3: mostrarPaciente();
                        break;
                        
                        case 4: cambiarDoctor();
                        break;
                        
                        case 5: cambiarCama();
                        break;
                                
                        case 6: informePaciente();
                        break;
                        
                        case 7: break;
                        
                        default:
                            cout<<"Error"<<endl;
                        break;
                    }
                    
                }while(opcion5>=1 && opcion5<7);   
                break;
            case 6:
                break;
              
          default:
                cout<<"La aplicacion se esta cerrando"<<endl;
                
        }
        
    }while(opcion >= 1 && opcion<6);
}







