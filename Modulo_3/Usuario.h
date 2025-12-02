#pragma once
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Usuario{
    private:
        string nombre;
        unordered_set<string> gustos;
        vector<Usuario*> amigos;
    public:
        Usuario(string nombre){this->nombre = nombre;}
        void insertarGusto(string nuevo_gusto);
        void insertarGustos(const vector<string>& nuevos_gustos);
        void agregarAmigo(Usuario* amigo);
        string getNombre() const;
        const unordered_set<string>& getGustos() const;
        const vector<Usuario*>& getAmigos() const;
};