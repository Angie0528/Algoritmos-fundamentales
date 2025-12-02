import heapq
from typing import Dict, List, Tuple, Optional

class Graph:
    
    def __init__(self):
        self.graph: Dict[str, List[Tuple[str, float]]] = {}
    
    def add_edge(self, u: str, v: str, weight: float) -> None:
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
        
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))
    
    def dijkstra(self, start: str) -> Tuple[Dict[str, float], Dict[str, Optional[str]]]:
        distances: Dict[str, float] = {node: float('infinity') for node in self.graph}
        distances[start] = 0
        
        previous: Dict[str, Optional[str]] = {node: None for node in self.graph}
        
        priority_queue: List[Tuple[float, str]] = [(0, start)]
        
        visited = set()
        
        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)
            
            if current_node in visited:
                continue
            
            visited.add(current_node)
            
            if current_distance > distances[current_node]:
                continue
            
            for neighbor, weight in self.graph[current_node]:
                distance = current_distance + weight
                
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    previous[neighbor] = current_node
                    heapq.heappush(priority_queue, (distance, neighbor))
        
        return distances, previous
    
    def print_graph(self) -> None:
        print("\n=== ESTRUCTURA DEL GRAFO ===")
        print("Nodos y sus conexiones:\n")
        
        for node in sorted(self.graph.keys()):
            print(f"Nodo {node}:")
            neighbors = sorted(self.graph[node], key=lambda x: x[0])
            for neighbor, weight in neighbors:
                print(f"  -> {neighbor}: {weight:.2f}m")
            print()
    
    def print_shortest_path(self, dest: str, distances: Dict[str, float], 
                           previous: Dict[str, Optional[str]], start: str) -> None:
        if distances[dest] == float('infinity'):
            print(f"\nNo existe camino desde {start} hasta {dest}")
            return
        
        path = []
        current = dest
        while current is not None:
            path.append(current)
            current = previous[current]
        
        path.reverse()
        
        print(f"\n=== CAMINO MAS CORTO DE {start} A {dest} ===")
        print(f"Ruta: {' -> '.join(path)}")
        print(f"Distancia total: {distances[dest]:.2f}m")
        
        print("\nDetalles del recorrido:")
        for i in range(len(path) - 1):
            current_node = path[i]
            next_node = path[i + 1]
            for neighbor, weight in self.graph[current_node]:
                if neighbor == next_node:
                    print(f"  {current_node} -> {next_node}: {weight:.2f}m")
                    break


def main():
    graph = Graph()
    
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
    
    graph.print_graph()
    
    print("=== ALGORITMO DE DIJKSTRA ===")
    print(f"Nodos disponibles: {', '.join(sorted(graph.graph.keys()))}")
    start_node = input("\nIngrese el nodo origen: ").strip().upper()
    
    if start_node not in graph.graph:
        print(f"Error: El nodo '{start_node}' no existe en el grafo.")
        return
    
    distances, previous = graph.dijkstra(start_node)
    
    print(f"\n=== DISTANCIAS MINIMAS DESDE {start_node} ===")
    for node in sorted(distances.keys()):
        if distances[node] == float('infinity'):
            print(f"{start_node} -> {node}: INALCANZABLE")
        else:
            print(f"{start_node} -> {node}: {distances[node]:.2f}m")
    
    print("\n=== CAMINOS OPTIMOS A DESTINOS ESPECIFICOS ===")
    
    other_nodes = [node for node in sorted(graph.graph.keys()) if node != start_node]
    
    destinations = other_nodes[:min(3, len(other_nodes))]
    
    for dest in destinations:
        graph.print_shortest_path(dest, distances, previous, start_node)
    
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
