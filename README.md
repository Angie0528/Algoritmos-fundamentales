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


## Video explicatorio:
https://youtu.be/M8cv2TapcXs



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

## Video explicatorio:
( https://youtu.be/UctuGu1ybPY )




# Modulo 3: Algoritmo de Recomendaciones basado en amigos ( Red Social )

 Sistema de Red Social con Recomendaciones Inteligentes
📋 Descripción del Proyecto
Este proyecto implementa una red social completa con un sistema avanzado de recomendaciones basado en análisis de afinidades entre usuarios. El sistema permite gestionar usuarios, sus intereses, relaciones de amistad y proporciona recomendaciones personalizadas utilizando algoritmos eficientes y optimizados.

🏗️ Arquitectura del Sistema
Estructura de Archivos
text
├── Usuario.h           # Definición de la clase Usuario
├── Usuario.cpp         # Implementación de métodos de Usuario
├── RedSocial.h         # Definición de la clase RedSocial  
├── RedSocial.cpp       # Implementación de métodos de RedSocial
└── main.cpp            # Programa principal con algoritmos de recomendación
Clases Principales
👤 Clase Usuario
Atributos:

nombre: Identificador único del usuario

gustos: Conjunto de intereses (unordered_set<string>)

amigos: Lista de conexiones sociales (vector<Usuario*>)

Funcionalidades:

Gestión de gustos/intereses

Gestión de relaciones de amistad

Acceso controlado a datos privados

🌐 Clase RedSocial
Atributos:

usuarios: Mapa de usuarios indexados por nombre (unordered_map<string, Usuario*>)

Funcionalidades:

Creación y eliminación de usuarios

Búsqueda eficiente de usuarios

Gestión automática de memoria

⚡ Algoritmos Implementados
1. 🎯 Algoritmo de Cálculo de Similitud (Optimizado)
cpp
Complejidad: O(n + m) donde n y m son gustos de cada usuario
Estrategia: Utiliza unordered_set para búsquedas en tiempo constante O(1)

Ventaja: Evita el enfoque O(n²) tradicional mediante hashing

Resultado: Calcula gustos compartidos entre dos usuarios eficientemente

2. 🤝 Algoritmo de Recomendación con Ponderación por Afinidad
cpp
Complejidad: O(U + A×G + G log G)
Fase 1: Calcula "fuerza de amistad" basada en similitud porcentual

Fase 2: Pondera recomendaciones según afinidad con cada amigo

Fase 3: Selecciona los 3 gustos mejor puntuados excluyendo los ya existentes

Fórmula de Ponderación:

text
peso_amigo = gustos_comunes / total_gustos_amigo
puntuación_gusto = Σ peso_amigo (para cada amigo que tenga ese gusto)
🚀 Características Técnicas
🔄 Estructuras de Datos Optimizadas
unordered_set<string>: Para gustos (inserción y búsqueda O(1))

unordered_map<string, Usuario*>: Para usuarios (acceso O(1) por nombre)

vector<Usuario*>: Para relaciones (iteración eficiente)

💾 Gestión de Memoria
Sistema de propiedad claro: RedSocial posee todos los objetos Usuario

Destructor automático que libera toda la memoria

Uso de punteros raw para relaciones (sin overhead de smart pointers)

🎲 Generación de Datos Realista
20 categorías de gustos predefinidas

Asignación aleatoria de 5-20 gustos por usuario

Configuración flexible de redes sociales

📊 Ejemplo de Salida
text
---------------------------
Gustos de los Usuarios: 
   - Sofia: 
   - Musica
   - Cine
   - Tecnologia
   ...
---------------------------
Similitudes entre Usuarios: 
Andre y Sofia tienen: 8 intereses en comun.
Genaro y Eilyn tienen: 5 intereses en comun.
...
---------------------------
Recomendaciones para Sofia: 
- Fotografia
- Viajes
- Lectura
---------------------------
🔧 Compilación y Ejecución
Compilación
bash
g++ -std=c++11 -o red_social *.cpp
Ejecución
bash
./red_social
📈 Rendimiento
Similitud entre usuarios: O(n + m) en lugar de O(n × m)

Búsqueda de usuarios: O(1) mediante hash tables

Gestión de gustos: Operaciones O(1) promedio

Escalabilidad: Diseñado para soportar miles de usuarios eficientemente

🎯 Casos de Uso
Análisis de Afinidades: Descubre qué usuarios comparten intereses

Recomendaciones Personalizadas: Sugiere nuevos intereses basados en la red social

Gestión de Comunidades: Administra usuarios y sus relaciones

Simulación de Redes: Crea redes sociales virtuales para pruebas

✅ Ventajas del Diseño
Alto Rendimiento
Algoritmos optimizados con complejidades lineales

Estructuras de datos seleccionadas específicamente para cada operación

Sin cuellos de botella computacionales

Mantenibilidad
Separación clara de responsabilidades

Código legible y bien documentado

Fácil extensión para nuevas funcionalidades

Robustez
Manejo de excepciones para casos límite

Validación de entrada de datos

Gestión automática de recursos

🧠 Conceptos de Ciencias de la Computación Aplicados
Estructuras de Datos: Hash tables, sets, vectors, maps

Algoritmos: Búsqueda, ordenamiento, análisis de grafos

Complejidad Computacional: Análisis Big O optimizado

Gestión de Memoria: Ownership patterns y RAII

Programación Orientada a Objetos: Encapsulación, abstracción

📝 Notas Técnicas
Lenguaje: C++11 estándar

Paradigma: Orientado a objetos con algoritmos procedurales

Dependencias: Solo biblioteca estándar de C++

Plataforma: Multiplataforma (Windows/Linux/macOS)

🏆 Puntos Destacados
Algoritmo de similitud optimizado que evita complejidad cuadrática

Sistema de recomendaciones que considera calidad sobre cantidad

Arquitectura limpia con responsabilidades bien definidas

Código eficiente que prioriza rendimiento sin sacrificar legibilidad

🎯 Objetivo Logrado: Sistema de red social funcional con recomendaciones inteligentes, algoritmos eficientes y arquitectura sólida.



## Video explicatorio: ( URL )
( https://youtu.be/AbbKrJhisIQ )
