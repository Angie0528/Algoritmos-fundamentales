# Actividad: Implementación de Algoritmos de Ordenamiento

# Video Explicativo
[![Video Explicativo](https://youtu.be/by9gzt9yq6o)](https://youtu.be/by9gzt9yq6o)

## Algoritmos Implementados

### 1. Bubble Sort
- **Logica**: Compara repetidamente pares de elementos adyacentes y los intercambia si estan en el orden incorrecto. El proceso se repite hasta que no se necesiten mas intercambios.
- **Ventajas**: Simple de entender e implementar.
- **Desventajas**: Muy ineficiente para listas grandes.

### 2. Selection Sort
- **Logica**: Divide la lista en dos partes: una sublista ordenada y una sublista desordenada. Repetidamente encuentra el elemento minimo de la sublista desordenada y lo mueve al final de la sublista ordenada.
- **Ventajas**: Simple y predecible en su rendimiento.
- **Desventajas**: Ineficiente para listas grandes, siempre realiza el mismo numero de comparaciones.

### 3. Insertion Sort
- **Logica**: Construye la lista ordenada final un elemento a la vez. Itera sobre los elementos de entrada, y en cada iteracion, inserta el elemento actual en su posicion correcta dentro de la sublista ya ordenada.
- **Ventajas**: Eficiente para listas pequeñas y para listas que estan casi ordenadas.
- **Desventajas**: Ineficiente para listas grandes.

### 4. Merge Sort
- **Logica**: Utiliza el paradigma "divide y venceras". Divide recursivamente la lista en mitades hasta que cada sublista contenga un solo elemento. Luego, fusiona (merge) las sublistas para producir nuevas sublistas ordenadas hasta que solo quede una lista final ordenada.
- **Ventajas**: Eficiente y estable, con rendimiento garantizado de O(n log n).
- **Desventajas**: Requiere espacio adicional en memoria para los sub-arreglos temporales.

### 5. Quick Sort
- **Logica**: Tambien usa "divide y venceras". Selecciona un elemento como "pivote" y particiona los demas elementos en dos sub-arreglos, segun si son menores o mayores que el pivote. Luego, ordena recursivamente los sub-arreglos.
- **Ventajas**: Muy rapido en la practica, a menudo mas rapido que otros algoritmos O(n log n).
- **Desventajas**: El peor caso es O(n²), aunque es raro. No es estable.

## Comparacion de Complejidad

| Algoritmo | Mejor Caso | Caso Promedio | Peor Caso | Complejidad Espacial |
|----------------|------------|---------------|-----------|----------------------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) |
| **Selection Sort**| O(n²) | O(n²) | O(n²) | O(1) |
| **Insertion Sort**| O(n) | O(n²) | O(n²) | O(1) |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) |

### O(n²) vs O(n log n)

- **O(n²)**: Algoritmos como Bubble, Selection e Insertion Sort tienen una complejidad cuadratica. Esto significa que su tiempo de ejecucion crece exponencialmente con el tamaño de la entrada. Son adecuados para listas pequeñas, pero se vuelven muy lentos para listas grandes.
- **O(n log n)**: Algoritmos como Merge y Quick Sort son mucho mas eficientes. Su tiempo de ejecucion crece de manera mucho mas controlada, lo que los hace ideales para ordenar listas grandes.

## Uso

### Compilacion
```bash
g++ -std=c++17 -Wall -Wextra -O2 -o sorting_test main.cpp sorting.cpp
```

### Ejecucion
```bash
./sorting_test
```

## Estructura del codigo

```
sorting-cpp/
│
├── sorting.h       # Archivo de cabecera con las declaraciones de funciones
├── sorting.cpp     # Implementacion de los algoritmos de ordenamiento
├── main.cpp        # Archivo principal con las pruebas de funcionalidad
└── README.md       # Este archivo
```

## Pruebas

El archivo `main.cpp` realiza las siguientes pruebas:

1. Genera un vector de enteros aleatorios.
2. Prueba cada algoritmo de ordenamiento con una copia del vector.
3. Muestra el vector antes y despues de ordenar para cada algoritmo.
4. Compara los resultados de todos los algoritmos para asegurar que sean identicos.
5. Prueba casos especiales (listas ya ordenadas, ordenadas inversamente, con duplicados).
