#include "Usuario.h"
#include "RedSocial.h"
#include <iostream>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <cstdlib>
using namespace std;

int calcularSimilitud(Usuario* usuario1, Usuario* usuario2){
    int numSimilitudes = 0;
    unordered_set<string> gustos_usuario(usuario1->getGustos().begin(), usuario1->getGustos().end());
    
    for (string gusto : usuario2->getGustos()){
        if(gustos_usuario.find(gusto) != gustos_usuario.end()){
            numSimilitudes++;
        }
    }

    return numSimilitudes;
}

vector<string> recomendaciones(Usuario* usuario){
    vector<string> recomendar;
    int max_recomendaciones = 4;
    unordered_map<string, double> gustos_populares;

    //Primero lo llenamos el mapa con los intereses del mismo usuario
    for (string gusto : usuario->getGustos()){
        if (gustos_populares.find(gusto) == gustos_populares.end()){
            gustos_populares[gusto] = 1;
        }else{
            gustos_populares[gusto]++;
        }
    }

    //Despues con los intereses de los amigos
    for(Usuario* amigo : usuario->getAmigos()){
        int gustosComunes = calcularSimilitud(usuario, amigo);
        int totalGustosAmigo = amigo->getGustos().size();
        double pesoAmigo = totalGustosAmigo > 0 ? (double)gustosComunes / totalGustosAmigo : 0.5;
        
        for(string gusto : amigo->getGustos()){
            if (usuario->getGustos().find(gusto) == usuario->getGustos().end()){
                gustos_populares[gusto] += pesoAmigo;
            }
        }
    }

    //Recomendamos solo los mas populares
    vector<pair<string, double>> lista(gustos_populares.begin(), gustos_populares.end());
    sort(lista.begin(), lista.end());
    for (int i = lista.size() - 1; i > -1; i--) {
        if(recomendar.size() == max_recomendaciones) break;
        recomendar.push_back(lista[i].first);
    }

    return recomendar;
}

int main(){
    srand(time(0));
    RedSocial red;
    vector<string> gustos_generales = {
        "Musica",
        "Cine",
        "Tecnologia",
        "Fitness",
        "Viajes",
        "Fotografia",
        "Lectura",
        "Videojuegos",
        "Cocina",
        "Arte",
        "Moda",
        "Deportes",
        "Jardineria",
        "Ciencia",
        "Historia",
        "Baile",
        "Animales",
        "Meditacion",
        "Carros",
        "Naturaleza"
    };

    red.crearUsuario("Sofia");
    red.crearUsuario("Eilyn");
    red.crearUsuario("Genaro");
    red.crearUsuario("Andre");

    for(Usuario* usuario_existente : red.getUsuarios()){
        int num_gustos = 7 + rand() % 13;
        for (int i = 0; i < num_gustos; i++){
            usuario_existente->insertarGusto(gustos_generales[rand() % 20]);
        }
    }

    Usuario* sofia = red.getUsuario("Sofia");
    Usuario* andre = red.getUsuario("Andre");
    Usuario* genaro = red.getUsuario("Genaro");
    Usuario* eilyn = red.getUsuario("Eilyn");

    for(Usuario* usuario : red.getUsuarios()){
        if (usuario->getNombre() != "Sofia") sofia->agregarAmigo(usuario);
    }

    cout << "---------------------------\n";
    cout << "Gustos de los Usuarios: \n";

    for(Usuario* usuario : red.getUsuarios()){ 
        cout << "   - " << usuario->getNombre() << ": \n";
        for(string gusto : usuario->getGustos()){
            cout << "- " << gusto << "\n";
        }
    }

    cout << "---------------------------\n";
    cout << "Similtudes entre Usuarios: \n";
    cout << "Andre y Sofia tienen: " << calcularSimilitud(andre, sofia) << " intereses en comun.\n";
    cout << "Genaro y Eilyn tienen: " << calcularSimilitud(genaro, eilyn) << " intereses en comun.\n";
    cout << "Sofia y Eilyn tienen: " << calcularSimilitud(sofia, eilyn) << " intereses en comun.\n";
    cout << "Eilyn y Andre tienen: " << calcularSimilitud(eilyn, andre) << " intereses en comun.\n";

    cout << "---------------------------\n";
    cout << "Recomendaciones para Sofia basada en su red de amigos: \n";
    for(string gusto : recomendaciones(sofia)){
        cout << "- " << gusto << "\n";
    }
    cout << "---------------------------\n";
    cout << "Recomendaciones para Genaro basada en su red de amigos: \n";
    for(string gusto : recomendaciones(genaro)){
        cout << "- " << gusto << "\n";
    }
    cout << "---------------------------\n";
    cout << "Recomendaciones para Andre basada en su red de amigos: \n";
    for(string gusto : recomendaciones(andre)){
        cout << "- " << gusto << "\n";
    }
    cout << "---------------------------\n";
    cout << "Recomendaciones para Eilyn basada en su red de amigos: \n";
    for(string gusto : recomendaciones(eilyn)){
        cout << "- " << gusto << "\n";
    }
    cout << "---------------------------\n";

    return 0;
}