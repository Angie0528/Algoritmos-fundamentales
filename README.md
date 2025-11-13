# Implementación del Algoritmo de Dijkstra

Este proyecto contiene una implementación en Python del algoritmo de Dijkstra para encontrar la ruta más corta en un grafo ponderado no dirigido. El programa utiliza un mapa específico como base para construir el grafo y calcular las rutas óptimas entre diferentes puntos.

## Grafo del Mapa

El grafo se basa en el siguiente mapa, que define los nodos (A-K) y las distancias (aristas) entre ellos:

![Mapa del Grafo](https://private-us-east-1.manuscdn.com/sessionFile/N5LFT4Zr7FifJv0QMIn4Oy/sandbox/y4LzydKHP33uj1opPLOV5C-images_1763002754349_na1fn_L2hvbWUvdWJ1bnR1L21hcGFfZ3JhZm8.jpeg?Policy=eyJTdGF0ZW1lbnQiOlt7IlJlc291cmNlIjoiaHR0cHM6Ly9wcml2YXRlLXVzLWVhc3QtMS5tYW51c2Nkbi5jb20vc2Vzc2lvbkZpbGUvTjVMRlQ0WnI3RmlmSnYwUU1JbjRPeS9zYW5kYm94L3k0THp5ZEtIUDMzdWoxb3BQTE9WNUMtaW1hZ2VzXzE3NjMwMDI3NTQzNDlfbmExZm5fTDJodmJXVXZkV0oxYm5SMUwyMWhjR0ZmWjNKaFptOC5qcGVnIiwiQ29uZGl0aW9uIjp7IkRhdGVMZXNzVGhhbiI6eyJBV1M6RXBvY2hUaW1lIjoxNzk4NzYxNjAwfX19XX0_&Key-Pair-Id=K2HSFNDJXOU9YS&Signature=sNts0wC7auS~8IxJdjTnhxfeXMGRr-VTlefMB6j6bvFo-pibdxuxVIZOmRKtY4MfYerMROrK04oG1ZFOUrjGSUYJ4Q0~R1BNiXy1XLdGONmVdzY8AKcaO4Jj9HOj7L1MhKJivnXL9hdeJM9J~LM97FBlNO~aKTSeu00KgTn5N6Gj0Dw1sR0UUffjQizEI4NR1mRKgjxbmUFHbJfOoNJUH4BATh1MuMAAHLTKNeZTxUphim779xksQ54cJO8UUpSfWefWM-wGnxBXpgeFwEDFLEojvSZCktPtnMej9flb0X8CG-8bsWMKpznWeX7ijT0ORaU7JW1qXX6abCoxeC61qg__)

## Características

- **Representación del Grafo**: Utiliza un diccionario de adyacencia para una representación eficiente del grafo.
- **Algoritmo de Dijkstra**: Implementado con una cola de prioridad (min-heap) para un rendimiento óptimo, logrando una complejidad de `O((V + E) log V)`.
- **Interactividad**: Permite al usuario seleccionar un nodo de origen para iniciar los cálculos.
- **Resultados Detallados**: Muestra las distancias mínimas desde el origen a todos los demás nodos.
- **Visualización de Rutas**: Imprime el camino más corto, la distancia total y los segmentos individuales para cualquier destino solicitado.

## Estructura del Código

El código está organizado en una clase `Graph` que encapsula toda la lógica del grafo y una función `main` que maneja la ejecución del programa.

### Clase `Graph`

| Método                 | Descripción                                                                 |
| ---------------------- | --------------------------------------------------------------------------- |
| `__init__()`           | Inicializa un grafo vacío.                                                  |
| `add_edge(u, v, w)`    | Agrega una arista bidireccional entre los nodos `u` y `v` con peso `w`.     |
| `dijkstra(start)`      | Ejecuta el algoritmo de Dijkstra desde el nodo `start` y devuelve las distancias y rutas. |
| `print_graph()`        | Muestra la estructura de adyacencia completa del grafo.                     |
| `print_shortest_path(dest, ...)` | Reconstruye y muestra la ruta más corta hacia un nodo `dest`.               |

### Función `main()`

Esta función es el punto de entrada del programa. Se encarga de:
1. Crear una instancia de `Graph`.
2. Poblar el grafo con los nodos y aristas del mapa.
3. Mostrar la estructura inicial del grafo.
4. Solicitar al usuario un nodo de origen.
5. Ejecutar el algoritmo de Dijkstra.
6. Presentar los resultados (distancias mínimas y ejemplos de rutas cortas).
7. Permitir al usuario consultar rutas específicas de forma interactiva.

## Cómo Ejecutar el Programa

1.  **Requisitos**: Tener Python 3 instalado.
2.  **Ejecución**: Abre una terminal y ejecuta el siguiente comando en el directorio donde se encuentra el archivo `dijkstra.py`:

    ```bash
    python3 dijkstra.py
    ```

3.  **Interacción**:
    - El programa te pedirá que ingreses un nodo de origen (por ejemplo, `A`).
    - A continuación, mostrará las distancias mínimas a todos los demás nodos.
    - Finalmente, podrás ingresar nodos de destino para ver la ruta detallada o escribir `salir` para terminar.
