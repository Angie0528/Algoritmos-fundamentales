# Streaming de video con un buffer controlado
En el sistema se hace un simulacion de streaming usando un buffer controlado por un algoritmo de Slidign Window. El sistema lee los datos del archivo, los almacena en el buffer y simula las perdidas de conexion y reconexion.

#

## Librerias utilizadas
- <iostream>           Para el cout
- <fstream>            Lectura del archivo de chunks
- <string>             Texto
- <deque>              Implemetaicon de buffer
- <thread>             Red o reproduccion
- <chrono>             Pausas entre frames

