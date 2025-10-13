from stack import Stack
from queue import Queue


def test_stack():
    print("=" * 50)
    print(" PRUEBA DE STACK (PILA) ")
    print("=" * 50)
    
    stack = Stack()
    print(f"\n 1. Se crea una pila vacia: {stack}")
    print(f" Esta vacia? {stack.is_empty()}")
    print(f" Tamaño: {stack.size()}")
    
    print("\n 2. Agregando elementos con push(): ")
    elementos = [10, 20, 30, 40, 50]
    for elem in elementos:
        stack.push(elem)
        print(f" Se agrego {elem} -> {stack}")
    
    print(f"\n Tamaño actual: {stack.size()}")
    
    print(f"\n 3. Elemento en la parte superior (peek): {stack.peek()}")
    print(f" La pila sigue igual: {stack}")
    
    print("\n 4. Eliminando elementos con pop():")
    while not stack.is_empty():
        elemento = stack.pop()
        print(f" Se removio {elemento} -> {stack}")
    
    print(f"\n Esta vacia? {stack.is_empty()}")
    print(f" Tamaño: {stack.size()}")
    
    print("\n 5. Intentando pop() en pila vacia:")
    try:
        stack.pop()
    except IndexError as e:
        print(f" Error: {e}")


def test_queue():
    print("\n\n" + "=" * 50)
    print(" PRUEBA DE QUEUE (COLA) ")
    print("=" * 50)
    
    queue = Queue()
    print(f"\n 1. Se crea una cola vacia: {queue}")
    print(f" Esta vacia? {queue.is_empty()}")
    print(f" Tamaño: {queue.size()}")
    
    print("\n 2. Agregando elementos con enqueue():")
    elementos = ['A', 'B', 'C', 'D', 'E']
    for elem in elementos:
        queue.enqueue(elem)
        print(f" Se agrego {elem} -> {queue}")
    
    print(f"\n Tamaño actual: {queue.size()}")
    
    print(f"\n 3. Elemento al frente (front): {queue.front()}")
    print(f" La cola sigue igual: {queue}")
    
    print("\n 4. Eliminando elementos con dequeue():")
    while not queue.is_empty():
        elemento = queue.dequeue()
        print(f" Se removio {elemento} -> {queue}")
    
    print(f"\n Esta vacia? {queue.is_empty()}")
    print(f" Tamaño: {queue.size()}")
    
    print("\n 5. Intentando dequeue() en cola vacia:")
    try:
        queue.dequeue()
    except IndexError as e:
        print(f" Error: {e}")


def ejemplo_practico():
    print("\n\n" + "=" * 50)
    print(" EJEMPLO PRACTICO ")
    print("=" * 50)
    
    print("\n--- Simulacion de historial de navegacion (Stack) ---")
    historial = Stack()
    paginas = ["google.com", "youtube.com", "github.com", "stackoverflow.com"]
    
    print(" Visitando paginas: ")
    for pagina in paginas:
        historial.push(pagina)
        print(f" Visitando: {pagina}")
    
    print(f"\n Pagina actual: {historial.peek()}")
    print("\n Retrocediendo en el historial:")
    for _ in range(2):
        pagina = historial.pop()
        print(f" Saliendo de: {pagina}")
    print(f" Pagina actual: {historial.peek()}")
    
    print("\n\n --- Simulacion de cola de impresion (Queue) ---")
    cola_impresion = Queue()
    documentos = ["documento1.pdf", "imagen.jpg", "reporte.docx", "presentacion.pptx"]
    
    print(" Agregando documentos a la cola: ")
    for doc in documentos:
        cola_impresion.enqueue(doc)
        print(f" En cola: {doc}")
    
    print(f"\n Documentos en cola: {cola_impresion.size()}")
    print("\n Imprimiendo documentos:")
    while not cola_impresion.is_empty():
        doc = cola_impresion.dequeue()
        print(f" Imprimiendo: {doc}")
    
    print(f"\n Documentos restantes: {cola_impresion.size()}")


if __name__ == "__main__":
    test_stack()
    test_queue()
    ejemplo_practico()
    
    print("\n\n" + "=" * 50)
    print(" PRUEBAS COMPLETADAS ")
    print("=" * 50)

