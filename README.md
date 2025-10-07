# Streaming de video con un buffer controlado
En el sistema se hace un simulacion de streaming usando un buffer controlado por un algoritmo de Slidign Window. El sistema lee los datos del archivo, los almacena en el buffer y simula las perdidas de conexion y reconexion.

#

## Librerias utilizadas
- #include <iostream>           Para el cout
- #include <fstream>            Lectura del archivo de chunks
- #include <string>             Texto
- #include <deque>              Implemetaicon de buffer
- #include <thread>             Red o reproduccion
- #include <chrono>             Pausas entre frames

