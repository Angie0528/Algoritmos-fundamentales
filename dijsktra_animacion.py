import heapq
from typing import Dict, List, Tuple, Optional
import matplotlib.pyplot as plt
import networkx as nx
import matplotlib.animation as animation

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

    def dijkstra(self, start: str) -> Tuple[Dict[str, float], Dict[str, Optional[str]], List[str]]:
        distances: Dict[str, float] = {node: float('infinity') for node in self.graph}
        distances[start] = 0
        previous: Dict[str, Optional[str]] = {node: None for node in self.graph}
        priority_queue: List[Tuple[float, str]] = [(0, start)]
        visited_order = []

        visited = set()
        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)
            if current_node in visited:
                continue
            visited.add(current_node)
            visited_order.append(current_node)

            for neighbor, weight in self.graph[current_node]:
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    previous[neighbor] = current_node
                    heapq.heappush(priority_queue, (distance, neighbor))

        return distances, previous, visited_order

    def reconstruct_path(self, dest: str, previous: Dict[str, Optional[str]]) -> List[str]:
        path = []
        current = dest
        while current is not None:
            path.append(current)
            current = previous[current]
        path.reverse()
        return path


def animate_dijkstra(graph: Graph, start: str, dest: str):
    G = nx.Graph()
    for u in graph.graph:
        for v, w in graph.graph[u]:
            G.add_edge(u, v, weight=w)

    distances, previous, visited_order = graph.dijkstra(start)
    path = graph.reconstruct_path(dest, previous)

    pos = {
    'A': (0, 0),
    'B': (10, -3),
    'D': (10, 50),
    'F': (25, 50),
    'H': (25, 120),
    'K': (25, 180),
    'J': (10, 180),
    'I': (10, 120),
    'G': (-3, 120),
    'E': (-3, 60),
    'C': (-3, 20)
    }

    labels = nx.get_edge_attributes(G, 'weight')

    fig, ax = plt.subplots(figsize=(10, 8))
    visited_nodes = []
    visited_edges = []

    def update(frame):
        ax.clear()
        nx.draw(G, pos, with_labels=True, node_color="lightblue", ax=ax)
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, ax=ax)

        if frame < len(visited_order):
            visited_nodes.append(visited_order[frame])
        nx.draw_networkx_nodes(G, pos, nodelist=visited_nodes, node_color="orange", ax=ax)

        if frame >= len(visited_order):
            path_edges = [(path[i], path[i+1]) for i in range(len(path)-1)]
            nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color="red", width=2, ax=ax)
            nx.draw_networkx_nodes(G, pos, nodelist=path, node_color="red", ax=ax)

        ax.set_title(f"Recorrido de Dijkstra (paso {frame+1})")

    ani = animation.FuncAnimation(fig, update, frames=len(visited_order)+2, interval=1000, repeat=False)
    plt.show()


def main():
    graph = Graph()
    # Grafo basado en tu imagen del campus Tec Guadalajara
    graph.add_edge('A', 'B', 33.35)
    graph.add_edge('B', 'D', 58.10)
    graph.add_edge('D', 'F', 77.73)
    graph.add_edge('F', 'H', 94.25)
    graph.add_edge('H', 'K', 78.31)
    graph.add_edge('K', 'J', 82.05)
    graph.add_edge('J', 'I', 74.28)
    graph.add_edge('I', 'G', 54.47)
    graph.add_edge('G', 'E', 95.66)
    graph.add_edge('E', 'C', 44.50)
    graph.add_edge('C', 'A', 30.42)

    print("=== ALGORITMO DE DIJKSTRA ===")
    print(f"Nodos disponibles: {', '.join(sorted(graph.graph.keys()))}")
    start_node = input("Nodo origen: ").strip().upper()
    dest_node = input("Nodo destino: ").strip().upper()

    if start_node not in graph.graph or dest_node not in graph.graph:
        print("Error: nodo inválido.")
        return

    distances, previous, _ = graph.dijkstra(start_node)
    path = graph.reconstruct_path(dest_node, previous)

    print(f"\nCamino más corto de {start_node} a {dest_node}: {' -> '.join(path)}")
    print(f"Distancia total: {distances[dest_node]:.2f}m")

    animate_dijkstra(graph, start_node, dest_node)


if __name__ == "__main__":
    main()
