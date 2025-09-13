# Algoritmos-fundamentales
Repositorio con implementaciones de algoritmos para la clase de Programacion

# Chat History Cleaner 

Este proyecto implementa una simulación de historial de chat y un algoritmo de compactación de mensajes eliminados (garbage collection) en C++.

## Descripción
En una aplicación de chat, cuando un usuario elimina un mensaje, este no se borra inmediatamente de memoria (porque reorganizar memoria constantemente sería costoso).  
En su lugar, se marca el mensaje con un flag `deleted = true`.  

Más adelante, cuando el historial crece demasiado, se ejecuta un **algoritmo de limpieza** que compacta el historial, moviendo los mensajes válidos al frente y dejando los eliminados al final.

Este proyecto muestra:
- Cómo simular un historial de mensajes con usuarios y textos.
- Cómo marcar mensajes como eliminados.
- Cómo usar el algoritmo **two pointers** para compactar eficientemente el historial.

## Funcionalidades
- Generación de un historial de `n` mensajes entre dos usuarios (Alice y Bob).
- Cada cierto número de mensajes, se marcan algunos como eliminados.
- Visualización de los primeros 10 mensajes generados.
- Algoritmo de limpieza que reorganiza el historial:
  - Los mensajes no eliminados quedan al inicio.
  - Los eliminados se mandan al final.
- Reporte de cuántos mensajes fueron eliminados.

## Estructura del código
- `struct Message`: representa cada mensaje (id, remitente, texto, flag eliminado).
- `generateChatHistory(int n)`: genera el historial con mensajes de ejemplo.
- `algoritmoLimpiar(vector<Message>& chat)`: compacta el historial usando *two pointers*.
- `main()`: ejecuta la simulación.

## Ejecución
Compilar el programa y ejecutar:
./chat_cleaner

## Ejemplo de salida
Antes de limpiar:
1 [Alice]: Hola (deleted)
2 [Bob]: ¿Cómo estás?
3 [Alice]: Todo bien
...
Total mensajes generados: 5000

Después de limpiar:
Se han eliminado correctamente 294 mensajes de tu historial.

Los mensajes eliminados se compactan al final, manteniendo el resto del historial válido.

## Algoritmo utilizado
Se utiliza la técnica de Two Pointers:
-left: recorre el historial desde el inicio.
-right: recorre desde el final.
-Cuando left encuentra un eliminado y right encuentra un válido, se intercambian.
-Así, los eliminados se van acumulando al final sin necesidad de borrar elementos uno a uno.
Este enfoque es O(n) y evita realocar memoria muchas veces.
```bash
g++ -std=c++11 chat_cleaner.cpp -o chat_cleaner
