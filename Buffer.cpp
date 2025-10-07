#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void slidingWindow(ifstream& archivo, deque<string>& buffer, int windowSize) {
    string chunk;
    getline(archivo, chunk);
    if (!chunk.empty()) {
        buffer.push_back(chunk);
        cout << "Chunk Recibido: " << chunk << endl;
    }

    if ((int)buffer.size() > windowSize) {
        cout << "Ventana llena: " << buffer.front() << endl;
        buffer.pop_front();
    }
}

void Reproduccion(deque<string>& buffer) {
    if (!buffer.empty()) {
        cout << "Reproduciendo frame: " << buffer.front() << endl;
        buffer.pop_front();
    } else {
        cout << "Buffer vacio -> buffering...\n";
    }
}

int main() {
    ifstream archivo("Datos.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    deque<string> buffer;
    int windowSize = 3;
    bool online = true;
    int ciclos = 0;

    while (!archivo.eof() || !buffer.empty()) {
        if (rand() % 10 < 2) {
            online = false;
            cout << "\nOffline\n";
        }

        if (online) {
            slidingWindow(archivo, buffer, windowSize);
        } else {
            cout << "Offline no puede llegar datos\n";
        }


        Reproduccion(buffer);


        if (!online && rand() % 10 > 7) {
            online = true;
            cout << "Reconectado\n";
        }

        this_thread::sleep_for(chrono::milliseconds(200));
        ciclos++;
        if (archivo.eof() && buffer.empty()) break;
    }

    return 0;
}