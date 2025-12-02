#include "RedSocial.h"
#include <string>
#include <iostream>
using namespace std;

RedSocial::~RedSocial() {
    for (auto& par : usuarios) {
        delete par.second;
    }
}

void RedSocial::crearUsuario(string nombre){
    if (usuarios.find(nombre) != usuarios.end()){
        cout << "Ya existe este usuario, elige otro nombre.\n";
        return;
    }
    usuarios[nombre] = new Usuario(nombre);
}

Usuario* RedSocial::getUsuario(string nombre){
    if (usuarios.find(nombre) == usuarios.end()){
        throw out_of_range("No existe el usuario: " + nombre);
    }
    return usuarios[nombre];
}

vector<Usuario*> RedSocial::getUsuarios(){
    vector<Usuario*> usuarios_existentes;

    for(pair<string, Usuario*> usuario : usuarios){
        usuarios_existentes.push_back(usuario.second);
    }

    return usuarios_existentes;
}