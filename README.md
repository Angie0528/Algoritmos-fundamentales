# Modulo 1: Algoritmo de Dijkstra con animación.

aaaa





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

## Entregables del Proyecto

Este repositorio incluye los siguientes archivos:

- `load_balancer_round_robin.py`: El codigo fuente principal de la simulacion.

- `documento_explicativo.md`: Un documento que profundiza en la descripcion del algoritmo, la justificacion del modelo y el analisis de complejidad.

- `distribucion_carga_round_robin.png`: La imagen generada por la simulacion que muestra la distribucion de la carga.

- `README.md`: Este mismo archivo, que sirve como guia general del proyecto.


# Modulo 3: Algoritmo de Recomendaciones basado en amigos ( Red Social )

aaaa
