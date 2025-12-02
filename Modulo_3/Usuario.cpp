#include "Usuario.h"

void Usuario::insertarGusto(string nuevo_gusto){
    gustos.insert(nuevo_gusto);
}

void Usuario::insertarGustos(const vector<string>& nuevos_gustos){
    for(string gusto : nuevos_gustos){
        gustos.insert(gusto);
    }
}

void Usuario::agregarAmigo(Usuario* amigo){
    amigos.push_back(amigo);
}

string Usuario::getNombre() const{
    return nombre;
}

const unordered_set<string>& Usuario::getGustos() const{
    return gustos;
}

const vector<Usuario*>& Usuario::getAmigos() const{
    return amigos;
}
