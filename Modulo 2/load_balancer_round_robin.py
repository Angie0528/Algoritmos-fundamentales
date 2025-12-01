from collections import deque

# Intentar importar matplotlib de forma opcional para que el script funcione
# incluso si la libreria no está instalada ( Fix para Mac )
try:
    import matplotlib.pyplot as plt
    _MATPLOTLIB_DISPONIBLE = True
except ImportError:
    plt = None
    _MATPLOTLIB_DISPONIBLE = False

# -----------------------------------------------------------------------------

class Servidor:
    "Clase que representa un servidor en el sistema"
    
    def __init__(self, nombre):
        self.nombre = nombre
        self.requests_recibidos = 0
    
    def procesar_request(self, request_id):
        "Procesa un request y actualiza el contador"
        self.requests_recibidos += 1
        return f"Request {request_id} procesado por {self.nombre}"


class LoadBalancerRoundRobin:
    """
    Balanceador de carga que implementa el algoritmo Round Robin.
    Utiliza una lista circular (Circular Linked List) para distribuir
    las solicitudes de manera equitativa entre los servidores.
    """
    
    def __init__(self, servidores):
        """
        Inicializa el balanceador con una lista de servidores
        
        Args:
            servidores: Lista de objetos Servidor
        """
        self.servidores = deque(servidores)
        self.total_requests = 0
        self.historial = []
    
    def asignar_request(self, request_id):
        """
        Asigna un request al siguiente servidor disponible usando Round Robin
        
        Args:
            request_id: Identificador del request
            
        Returns:
            Mensaje de confirmacion del procesamiento
        """
        # Obtener el servidor actual (primero en la cola)
        servidor_actual = self.servidores[0]
        
        # Procesar el request
        resultado = servidor_actual.procesar_request(request_id)
        
        # Registrar en el historial
        self.historial.append({
            'request_id': request_id,
            'servidor': servidor_actual.nombre
        })
        
        # Rotar la cola (mover el servidor actual al final)
        self.servidores.rotate(-1)
        
        self.total_requests += 1
        
        return resultado
    
    def obtener_estadisticas(self):
        """
        Genera estadisticas de carga de cada servidor
        
        Retorna:
            Diccionario con estadisticas por servidor
        """
        estadisticas = {}
        for servidor in self.servidores:
            estadisticas[servidor.nombre] = {
                'requests': servidor.requests_recibidos,
                'porcentaje': (servidor.requests_recibidos / self.total_requests * 100) 
                              if self.total_requests > 0 else 0
            }
        return estadisticas
    
    def mostrar_estadisticas(self):
        """Imprime las estadisticas de carga en consola."""
        print("\n" + "="*60)
        print("ESTADISTICAS DE DISTRIBUCION DE CARGA")
        print("="*60)
        print(f"Total de requests procesados: {self.total_requests}\n")
        
        estadisticas = self.obtener_estadisticas()
        
        print(f"{'Servidor':<20} {'Requests':<15} {'Porcentaje':<15}")
        print("-"*60)
        
        for servidor, stats in estadisticas.items():
            print(f"{servidor:<20} {stats['requests']:<15} {stats['porcentaje']:.2f}%")
        
        print("="*60)
    
    def visualizar_distribucion(self, guardar_archivo=True):
        """
        Crea una visualizacion grafica de la distribucion de carga.

        Si matplotlib no está instalado, solo muestra un mensaje en consola
        indicando cómo instalarlo para ver la gráfica.
        
        Args:
            guardar_archivo: Si True, guarda la grafica como imagen
        """
        if not _MATPLOTLIB_DISPONIBLE:
            print("\n[AVISO] matplotlib no está instalado. Ejecuta:")
            print("  pip install matplotlib")
            print("para habilitar la visualización gráfica.")
            return

        estadisticas = self.obtener_estadisticas()
        
        servidores = list(estadisticas.keys())
        requests = [stats['requests'] for stats in estadisticas.values()]
        
        # Crear figura con dos subplots
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
        
        # Grafica de barras
        colores = plt.cm.viridis([i/len(servidores) for i in range(len(servidores))])
        bars = ax1.bar(servidores, requests, color=colores, edgecolor='black', linewidth=1.5)
        ax1.set_xlabel('Servidores', fontsize=12, fontweight='bold')
        ax1.set_ylabel('Numero de Requests', fontsize=12, fontweight='bold')
        ax1.set_title('Distribucion de Carga - Round Robin', fontsize=14, fontweight='bold')
        ax1.grid(axis='y', alpha=0.3, linestyle='--')
        
        # Agregar valores sobre las barras
        for bar in bars:
            height = bar.get_height()
            ax1.text(bar.get_x() + bar.get_width()/2., height,
                    f'{int(height)}',
                    ha='center', va='bottom', fontsize=10, fontweight='bold')
        
        # Grafica de pastel
        ax2.pie(requests, labels=servidores, autopct='%1.1f%%', 
                colors=colores, startangle=90, textprops={'fontsize': 10, 'fontweight': 'bold'})
        ax2.set_title('Porcentaje de Carga por Servidor', fontsize=14, fontweight='bold')
        
        plt.tight_layout()
        
        if guardar_archivo:
            # Guardar en el directorio actual para que funcione en cualquier sistema
            plt.savefig('distribucion_carga_round_robin.png', dpi=300, bbox_inches='tight')
            print("\nGrafica guardada como: distribucion_carga_round_robin.png")
        
        plt.show()
    
    def mostrar_primeros_requests(self, n=20):
        """
        Muestra los primeros N requests y su asignacion
        
        Args:
            n: Numero de requests a mostrar
        """
        print("\n" + "="*60)
        print(f"PRIMEROS {n} REQUESTS ASIGNADOS")
        print("="*60)
        print(f"{'Request ID':<15} {'Servidor Asignado':<30}")
        print("-"*60)
        
        for i in range(min(n, len(self.historial))):
            entry = self.historial[i]
            print(f"{entry['request_id']:<15} {entry['servidor']:<30}")
        
        print("="*60)


def main():
    "Funcion principal que ejecutase"
    
    print("="*60)
    print("SIMULACION DE BALANCEADOR DE CARGA - ROUND ROBIN")
    print("="*60)
    
    # Configuracion
    NUM_SERVIDORES = 5
    NUM_REQUESTS = 10000
    
    # Crear servidores
    servidores = [Servidor(f"Servidor-{i+1}") for i in range(NUM_SERVIDORES)]
    
    print(f"\nConfiguracion:")
    print(f"- Numero de servidores: {NUM_SERVIDORES}")
    print(f"- Numero de requests: {NUM_REQUESTS}")
    print(f"- Algoritmo: Round Robin (Circular Linked List)")
    
    # Crear balanceador
    balancer = LoadBalancerRoundRobin(servidores)
    
    # Simular requests
    print(f"\nProcesando {NUM_REQUESTS} requests...")
    for i in range(1, NUM_REQUESTS + 1):
        balancer.asignar_request(i)
        
        # Mostrar progreso cada 2000 requests
        if i % 2000 == 0:
            print(f"  - Procesados: {i}/{NUM_REQUESTS}")
    
    print(f"  - Completado: {NUM_REQUESTS}/{NUM_REQUESTS}")
    
    # Mostrar resultados
    balancer.mostrar_primeros_requests(20)
    balancer.mostrar_estadisticas()
    balancer.visualizar_distribucion(guardar_archivo=True)


if __name__ == "__main__":
    main()
