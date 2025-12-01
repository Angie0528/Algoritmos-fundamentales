# Modulo 1: Algoritmo de Dijkstra con animación.
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


## Video explicatorio: ( URL )



# Modulo 2: Simulador de Balanceador de Carga - Algoritmo Round Robin

Este proyecto es una simulacion en Python del comportamiento de un balanceador de carga que distribuye solicitudes entre multiples servidores utilizando el algoritmo **Round Robin**. El objetivo es demostrar como se logra una distribucion equitativa de la carga y visualizar los resultados.

## Caracteristicas

- **Simulacion de Carga**: Capacidad para simular un gran numero de solicitudes (configurable, por defecto 10,000) dirigidas a un conjunto de servidores.

- **Algoritmo Round Robin**: Implementacion del algoritmo de asignacion secuencial y rotativa, garantizando una distribucion uniforme.

- **Modelo Orientado a Objetos**: El codigo esta estructurado con clases `Servidor` y `LoadBalancerRoundRobin` para una mayor claridad y modularidad.

- **Estadisticas Detalladas**: Genera y muestra estadisticas completas sobre la cantidad y el porcentaje de solicitudes que cada servidor ha procesado.

- **Visualizacion de Datos**: Crea una grafica de barras y un diagrama de pastel utilizando `matplotlib` para visualizar la distribucion de la carga, guardando el resultado en un archivo de imagen.

- **Registro de Asignaciones**: Muestra un historial de las primeras asignaciones para verificar el correcto funcionamiento del algoritmo.

## Implementacion

La logica del Round Robin se implemento utilizando una estructura de datos `collections.deque` (cola de doble extremo) de Python. Esta eleccion simula eficientemente una lista enlazada circular, aprovechando el metodo `rotate(-1)` para mover el servidor recien utilizado al final de la cola en tiempo constante **O(1)**.

Este enfoque es performante y se considera una practica recomendada en Python para este tipo de problemas, evitando la necesidad de implementar una lista circular manualmente.

## Como Ejecutar el Proyecto

### Requisitos

- Python 3.x

- Biblioteca `matplotlib`

Si no tienes `matplotlib` instalado, puedes hacerlo con pip:

```bash
pip install matplotlib
```

### Ejecucion

Para correr la simulacion, simplemente ejecuta el script de Python desde la terminal:

```bash
python3 load_balancer_round_robin.py
```

El script es autonomo y no requiere argumentos adicionales. Los parametros de la simulacion (numero de servidores y de solicitudes) se pueden modificar directamente en la funcion `main()` del archivo.

## Salida Esperada

Al ejecutar el script, veras la siguiente informacion en la consola:

1. **Configuracion de la Simulacion**: Detalles sobre el numero de servidores y solicitudes.

1. **Progreso del Procesamiento**: Actualizaciones a medida que se procesan las solicitudes.

1. **Primeras Asignaciones**: Una tabla que muestra a que servidor se asignaron los primeros 20 requests.

1. **Estadisticas Finales**: Una tabla resumen con el total de requests y el porcentaje de carga por servidor.

1. **Archivo de Imagen**: Se generara y guardara un archivo llamado `distribucion_carga_round_robin.png` en el mismo directorio, conteniendo las visualizaciones graficas.

## Video explicatorio: ( URL )



# Modulo 3: Algoritmo de Recomendaciones basado en amigos ( Red Social )

aaaa

## Video explicatorio: ( URL )
