# Streaming de video con un buffer controlado
Se hace un simulacion de streaming usando un buffer controlado por un algoritmo de Slidign Window. El sistema lee los datos de un archivo, los almacena en el buffer y simula las perdidas de conexion y reconexion.

#Funcionalidad
**Sliding Window:** Este nos ayuda a simular el almacenamiento de datos en el buffer y va haciendo la sliding window con el tamaño fijo. Este va a leer el una linea del chunk, si el chunk no etsa vacio, se agrega al final del buffer. Si el tamaño del buffer es mayor al al de la ventana entonces se elimina el el primero en la cola.

**Reproduccion:** Simula la reproduccion de los datos que estan dentro del buffer. Si el buffer no esta vacio entonces agarra el primer elemento en la cola, lo muestra en al consola y lo elimina del buffer.

## Librerias utilizadas
- `#include <iostream>`           Para el cout
- `#include <fstream>`            Lectura del archivo de chunks
- `#include <string>`             Texto
- `#include <deque>`              Implemetaicon de buffer
- `#include <thread>`             Red o reproduccion
- `#include <chrono>`             Pausas entre frames

