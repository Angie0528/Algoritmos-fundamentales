# Algoritmos-fundamentales
Repositorio con implementaciones de algoritmos para la clase de Programacion

# ¿Que es un Hash Table?
Es una esructura de datos que ayuda a almacenar key y values. Su ventaja principal es que las operaciones de insert, get y remove tienen un tiempo cercan a 0(1), esto es ideal cuando se reuiere un acceso rapido, como bases de datos o compliadores.

# Implementacion de Hash Table 
El proyecto implemeta una estructura de datos Hash Table en C++ aplicando los conceptos de:
- Funciones hash
- Manejo de colisiones
- Opreaciones (insert, get, remove)

## Componentes Principales
- Array/Vector: Almacena los elementos
- Función Hash: Convierte claves en índices válidos
- Manejo de Colisiones: Resuelve cuando dos claves generan el mismo índice


## ¿Por qué Quadratic Probing?
Se eligió Quadratic Probing para resolver colisiones por las siguientes ventajas:
- Mejor distribución: Evita el clustering primario del linear probing
- Eficiencia de caché: Mantiene localidad espacial mejor que separate chaining
- Memoria optimizada: No requiere estructuras adicionales como listas enlazadas
- **Implementación simple**: Más directo que double hashing

## Funcionamiento
Cuando ocurre una colisión en la posición `h(k)`, se prueba:
- `h(k) + 1²`, `h(k) + 2²`, `h(k) + 3²`, etc.
- Fórmula: `(h(k) + i²) % capacity`

## Análisis de Complejidad
Método `insert(key, value)`
- Caso promedio: O(1)
- Caso peor: O(n) - cuando hay muchas colisiones
- Explicación: Con factor de carga < 0.7, el probing encuentra posición rápidamente

Método `get(key)` 
- Caso promedio: O(1)
- Caso peor: O(n) - búsqueda exhaustiva
- Explicación: Similar a insert, depende del clustering y factor de carga

Método `remove(key)`
- Caso promedio: O(1) 
- Caso peor: O(n) - búsqueda + lazy deletion
- Explicación: Usa lazy deletion (marca como eliminado) para mantener cadenas de probing



## Características de la Implementación
Funcionalidades Implementadas:
- Función Hash: Suma de valores ASCII con módulo
- Quadratic Probing: Resolución de colisiones eficiente
- Redimensionamiento: Automático cuando factor de carga > 0.7
- Lazy Deletion: Mantiene integridad de búsquedas
- Estadísticas: Monitoreo de rendimiento  

Optimizaciones:
- Factor de carga controlado para mantener eficiencia
- Redimensionamiento dinámico para evitar degradación
- Reutilización de espacios eliminados
- Validaciones de entrada robustas

## Instrucciones de Compilación
```bash
Compilar
make all

Ejecutar
make run

Limpiar
make clean
```


## Video
https://youtu.be/VWKGEuNa4eQ
