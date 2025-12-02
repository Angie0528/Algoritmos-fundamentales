#pragma once
#include "Usuario.h"
#include <unordered_map>
#include <string>
using namespace std;

class RedSocial{
    private:
        unordered_map<string, Usuario*> usuarios;        
    public:
        ~RedSocial();
        void crearUsuario(string nombre);
        Usuario* getUsuario(string nombre);
        vector<Usuario*> getUsuarios();
};