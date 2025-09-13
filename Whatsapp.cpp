#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Message {
    int id;
    string sender;
    string text;
    bool deleted;
};

vector<Message> generateChatHistory(int n) {
    vector<Message> history;
    history.reserve(n);

    int eliminados = 0;

    vector<string> sampleTexts = {
        "Hola", "¿Cómo estás?", "Todo bien", "Ok", "Nos vemos",
        "¿Dónde estás?", "Manda ubicación", "Ya voy", "Adiós", "👍"
    };

    for (int i = 0; i < n; i++) {
        Message msg;
        msg.id = i + 1;
        msg.sender = (i % 2 == 0 ? "Alice" : "Bob");
        msg.text = sampleTexts[i % sampleTexts.size()];
        msg.deleted = (i % 17 == 0); // cada 17 mensajes, se elimina uno
        if (msg.deleted) ++eliminados;
        history.push_back(msg);
    }
    cout << eliminados << " eliminados pero no borrados.\n";
    return history;
}

void algoritmoLimpiar(vector<Message>& chat) {
    int left = 0;
    int right = chat.size() - 1;
    int eliminados = 0;

    while (left < right){
        if (chat[left].deleted){
            if (!chat[right].deleted){
                Message temp = chat[left];
                chat[left] = chat[right];
                chat[right] = temp;
                ++eliminados;
                ++left;
            }else ++eliminados;

            --right;

        }else ++left;
    }
    cout << "Se han eliminado correctamente " << eliminados << " mensajes de tu historial.\n";
}

int main() {
    vector<Message> chat = generateChatHistory(5000);

    // Mostrar solo los primeros 10 
    for (int i = 0; i < 10; i++) {
        cout << chat[i].id << " [" << chat[i].sender << "]: "
             << chat[i].text
             << (chat[i].deleted ? " (deleted)" : "")
             << endl;
    }

    cout << "Total mensajes generados: " << chat.size() << endl;

    algoritmoLimpiar(chat); // Implementamos un algoritmo usando two pointers, donde los eliminados estan al final del vector
}
