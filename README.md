# Implementacion de Estructuras de Datos: Stack y Queue en Python

Este proyecto contiene la implementacion desde cero de dos estructuras de datos fundamentales en programacion: **Stacks** y **Queues**, utilizando Python. Cada estructura incluye sus metodos basicos y se acompaña de un script de prueba que demuestra su funcionamiento.

## Estructuras de Datos Implementadas

### 1. Stack (Pila)

Una pila es una estructura de datos que sigue el principio **LIFO (Last In, First Out)**, lo que significa que el ultimo elemento en entrar es el primero en salir. Es analoga a una pila de platos: solo se puede agregar o quitar un plato de la parte superior.

La implementacion se encuentra en el archivo `stack.py`.

#### Metodos del Stack

| Metodo         | Descripcion                                           |
|----------------|-------------------------------------------------------|
| `push(element)`| Inserta un elemento en la parte superior de la pila.  |
| `pop()`        | Elimina y devuelve el elemento de la parte superior.  |
| `peek()`       | Devuelve el elemento superior sin eliminarlo.         |
| `is_empty()`   | Retorna `True` si la pila esta vacia, `False` en caso contrario. |
| `size()`       | Devuelve el numero total de elementos en la pila.     |

### 2. Queue (Cola)

Una cola es una estructura de datos que sigue el principio **FIFO (First In, First Out)**, donde el primer elemento en entrar es el primero en salir. Funciona como una fila de personas esperando para ser atendidas: la primera persona que llega es la primera en ser atendida.

La implementacion se encuentra en el archivo `queue.py`.

#### Metodos de la Queue

| Metodo           | Descripcion                                         |
|------------------|-----------------------------------------------------|
| `enqueue(element)`| Agrega un elemento al final de la cola.             |
| `dequeue()`      | Elimina y devuelve el elemento del frente.          |
| `front()`        | Devuelve el elemento del frente sin eliminarlo.     |
| `is_empty()`     | Retorna `True` si la cola esta vacia, `False` en caso contrario. |
| `size()`         | Devuelve el numero total de elementos en la cola.   |

## Estructura de Archivos

El proyecto esta organizado de la siguiente manera:

```
/
├── stack.py      # Contiene la clase Stack y su logica.
├── queue.py      # Contiene la clase Queue y su logica.
└── main.py       # Script de prueba con ejemplos de uso para ambas estructuras.
```

## Como Ejecutar las Pruebas

Para probar las implementaciones, simplemente ejecuta el script `main.py` desde la terminal. Este script creara instancias de `Stack` y `Queue`, ejecutara sus metodos principales y mostrara el funcionamiento paso a paso en la consola.

```bash
python3 main.py
```

## Salida de Ejemplo

Al ejecutar `main.py`, veras una salida detallada que demuestra como se agregan y eliminan elementos en ambas estructuras, junto con ejemplos practicos.

```
==================================================
PRUEBA DE STACK (PILA)
==================================================

1. Se crea una pila vacia: Stack([])
   ¿Esta vacia? True
   Tamaño: 0

2. Agregando elementos con push():
   Se agrego 10 -> Stack([10])
   Se agrego 20 -> Stack([10, 20])
   ...

4. Eliminando elementos con pop():
   Se removio 50 -> Stack([10, 20, 30, 40])
   ...

==================================================
PRUEBA DE QUEUE (COLA)
==================================================

1. Se crea una cola vacia: Queue([])
   ¿Esta vacia? True
   Tamaño: 0

2. Agregando elementos con enqueue():
   Se agrego A -> Queue(['A'])
   Se agrego B -> Queue(['A', 'B'])
   ...

4. Eliminando elementos con dequeue():
   Se removio A -> Queue(['B', 'C', 'D', 'E'])
   ...

==================================================
EJEMPLO PRACTICO
==================================================

--- Simulacion de historial de navegacion (Stack) ---
Visitando paginas:
  Visitando: google.com
  ...

--- Simulacion de cola de impresion (Queue) ---
Agregando documentos a la cola:
  En cola: documento1.pdf
  ...

==================================================
TODAS LAS PRUEBAS COMPLETADAS
==================================================
```
