#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void slidingWindow(deque<string>& buffer, ifstream& archivo){
    string nuevo;
    if (getline(archivo, nuevo)) {
        buffer.push_back(nuevo);
        cout << "Chunk recibido: " << nuevo << "\n";
    }
}

void Reproduccion(deque<string>& buffer, ifstream& archivo, bool online){
    if (buffer.empty()) { 
        cout << "Buffer vacio - buffering...\n";
        return;
    }

    string antiguo = buffer.front();
    buffer.pop_front();
    cout << "Reproduciendo frame: " << antiguo << "\n";

    if(online) slidingWindow(buffer, archivo);
}

bool estadoRed(){
    int random = rand() % 10;
    if (random <= 3){
        cout << "Error en la conexion - Offline\n";
        return false; 
    }
    return true;
}

void Recuperacion(deque<string>& buffer, ifstream& archivo){
    if(archivo.eof()) return;
    cout << "Llenando buffer...\n";
    slidingWindow(buffer, archivo);
}

int main(){
    ifstream archivo("Datos.txt");
    deque<string> buffer;
    int windowSize = 8;

    for (int i = 0; i < windowSize && !archivo.eof(); i++) {
        Recuperacion(buffer, archivo);
    }
    cout << "Online\n";

    while(!archivo.eof() || !buffer.empty()){
        bool online = estadoRed();

        if(online){
            if(buffer.size() < windowSize){
                Recuperacion(buffer, archivo);
            }else{
                Reproduccion(buffer, archivo, online);
            }
        }else{
            if(!buffer.empty()) Reproduccion(buffer, archivo, online);
        }

        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "\nFin de lectura del archivo\n";
}
