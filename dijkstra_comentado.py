import heapq
from typing import Dict, List, Tuple, Optional

class Graph:
    """
    Clase que representa un grafo ponderado no dirigido.
    Utiliza un diccionario de adyacencia para almacenar las conexiones entre nodos.
    """
    
    def __init__(self):
        """
        Inicializa el grafo con un diccionario vacio de adyacencia.
        La estructura es: {nodo: [(vecino, peso), ...]}
        """
        self.graph: Dict[str, List[Tuple[str, float]]] = {}
    
    def add_edge(self, u: str, v: str, weight: float) -> None:
        """
        Agrega una arista bidireccional entre dos nodos con un peso especifico.
        
        Parametros:
        - u: Nodo origen
        - v: Nodo destino
        - weight: Peso de la arista (distancia en metros)
        """
        # Si el nodo u no existe en el grafo, lo inicializamos
        if u not in self.graph:
            self.graph[u] = []
        # Si el nodo v no existe en el grafo, lo inicializamos
        if v not in self.graph:
            self.graph[v] = []
        
        # Agregamos la arista en ambas direcciones (grafo no dirigido)
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))
    
    def dijkstra(self, start: str) -> Tuple[Dict[str, float], Dict[str, Optional[str]]]:
        """
        Implementa el algoritmo de Dijkstra para encontrar las distancias minimas
        desde un nodo origen a todos los demas nodos del grafo.
        
        Parametros:
        - start: Nodo de inicio
        
        Retorna:
        - distances: Diccionario con las distancias minimas a cada nodo
        - previous: Diccionario con el nodo previo en el camino optimo
        
        Complejidad: O((V + E) log V) usando heap
        """
        # Inicializar distancias con infinito para todos los nodos
        distances: Dict[str, float] = {node: float('infinity') for node in self.graph}
        # La distancia al nodo inicial es 0
        distances[start] = 0
        
        # Diccionario para rastrear el nodo previo en el camino optimo
        previous: Dict[str, Optional[str]] = {node: None for node in self.graph}
        
        # Cola de prioridad (min-heap) para procesar nodos por distancia minima
        # Formato: (distancia, nodo)
        priority_queue: List[Tuple[float, str]] = [(0, start)]
        
        # Conjunto de nodos visitados para evitar reprocesamiento
        visited = set()
        
        while priority_queue:
            # Extraer el nodo con la distancia minima
            current_distance, current_node = heapq.heappop(priority_queue)
            
            # Si ya visitamos este nodo, continuamos
            if current_node in visited:
                continue
            
            # Marcamos el nodo como visitado
            visited.add(current_node)
            
            # Si la distancia actual es mayor que la registrada, continuamos
            if current_distance > distances[current_node]:
                continue
            
            # Explorar todos los vecinos del nodo actual
            for neighbor, weight in self.graph[current_node]:
                # Calcular la nueva distancia al vecino
                distance = current_distance + weight
                
                # Si encontramos un camino mas corto, actualizamos
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    previous[neighbor] = current_node
                    # Agregamos el vecino a la cola de prioridad
                    heapq.heappush(priority_queue, (distance, neighbor))
        
        return distances, previous
    
    def print_graph(self) -> None:
        """
        Muestra la estructura del grafo con todos sus nodos y aristas.
        Imprime cada nodo con sus vecinos y las distancias correspondientes.
        """
        print("\n=== ESTRUCTURA DEL GRAFO ===")
        print("Nodos y sus conexiones:\n")
        
        # Ordenar los nodos alfabeticamente para mejor visualizacion
        for node in sorted(self.graph.keys()):
            print(f"Nodo {node}:")
            # Ordenar vecinos alfabeticamente
            neighbors = sorted(self.graph[node], key=lambda x: x[0])
            for neighbor, weight in neighbors:
                print(f"  -> {neighbor}: {weight:.2f}m")
            print()
    
    def print_shortest_path(self, dest: str, distances: Dict[str, float], 
                           previous: Dict[str, Optional[str]], start: str) -> None:
        """
        Muestra el camino mas corto desde el nodo origen hasta un destino especifico.
        
        Parametros:
        - dest: Nodo destino
        - distances: Diccionario de distancias minimas
        - previous: Diccionario de nodos previos
        - start: Nodo de inicio
        """
        # Verificar si el destino es alcanzable
        if distances[dest] == float('infinity'):
            print(f"\nNo existe camino desde {start} hasta {dest}")
            return
        
        # Reconstruir el camino desde el destino hasta el origen
        path = []
        current = dest
        while current is not None:
            path.append(current)
            current = previous[current]
        
        # Invertir el camino para mostrarlo desde origen a destino
        path.reverse()
        
        # Mostrar el resultado
        print(f"\n=== CAMINO MAS CORTO DE {start} A {dest} ===")
        print(f"Ruta: {' -> '.join(path)}")
        print(f"Distancia total: {distances[dest]:.2f}m")
        
        # Mostrar detalles de cada segmento del camino
        print("\nDetalles del recorrido:")
        for i in range(len(path) - 1):
            current_node = path[i]
            next_node = path[i + 1]
            # Buscar el peso de la arista entre los nodos consecutivos
            for neighbor, weight in self.graph[current_node]:
                if neighbor == next_node:
                    print(f"  {current_node} -> {next_node}: {weight:.2f}m")
                    break


def main():
    """
    Funcion principal que ejecuta el programa.
    Crea el grafo, ejecuta Dijkstra y muestra los resultados.
    """
    # Crear instancia del grafo
    graph = Graph()
    
    # Agregar todas las aristas del mapa con sus distancias
    # Basado en el mapa proporcionado con nodos A-K
    graph.add_edge('A', 'B', 33.35)
    graph.add_edge('A', 'C', 30.42)
    graph.add_edge('B', 'D', 58.10)
    graph.add_edge('C', 'E', 44.50)
    graph.add_edge('D', 'E', 77.73)
    graph.add_edge('D', 'F', 77.73)
    graph.add_edge('E', 'G', 95.66)
    graph.add_edge('F', 'H', 94.25)
    graph.add_edge('G', 'I', 54.47)
    graph.add_edge('H', 'I', 100.00)
    graph.add_edge('I', 'J', 74.28)
    graph.add_edge('J', 'K', 82.05)
    graph.add_edge('K', 'H', 78.31)
    
    # Mostrar la estructura del grafo
    graph.print_graph()
    
    # Solicitar al usuario el nodo de origen
    print("=== ALGORITMO DE DIJKSTRA ===")
    print(f"Nodos disponibles: {', '.join(sorted(graph.graph.keys()))}")
    start_node = input("\nIngrese el nodo origen: ").strip().upper()
    
    # Validar que el nodo existe
    if start_node not in graph.graph:
        print(f"Error: El nodo '{start_node}' no existe en el grafo.")
        return
    
    # Ejecutar el algoritmo de Dijkstra
    distances, previous = graph.dijkstra(start_node)
    
    # Mostrar las distancias minimas a todos los nodos
    print(f"\n=== DISTANCIAS MINIMAS DESDE {start_node} ===")
    for node in sorted(distances.keys()):
        if distances[node] == float('infinity'):
            print(f"{start_node} -> {node}: INALCANZABLE")
        else:
            print(f"{start_node} -> {node}: {distances[node]:.2f}m")
    
    # Mostrar caminos optimos a tres destinos diferentes
    print("\n=== CAMINOS OPTIMOS A DESTINOS ESPECIFICOS ===")
    
    # Obtener todos los nodos excepto el origen
    other_nodes = [node for node in sorted(graph.graph.keys()) if node != start_node]
    
    # Seleccionar hasta 3 destinos diferentes
    destinations = other_nodes[:min(3, len(other_nodes))]
    
    for dest in destinations:
        graph.print_shortest_path(dest, distances, previous, start_node)
    
    # Opcion para consultar mas destinos
    print("\n" + "="*50)
    while True:
        dest_input = input("\nIngrese un nodo destino para ver el camino (o 'salir' para terminar): ").strip().upper()
        if dest_input == 'SALIR':
            break
        if dest_input not in graph.graph:
            print(f"Error: El nodo '{dest_input}' no existe en el grafo.")
            continue
        graph.print_shortest_path(dest_input, distances, previous, start_node)
    
    print("\nPrograma finalizado.")


if __name__ == "__main__":
    main()
