class LinkedList:
    
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
    
    def __init__(self):
        self.head = None  # Puntero al primer nodo (lista inicialmente vacia)
    
    def is_empty(self):
        return self.head is None
    
    def size(self):
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count
    
    def insertAtBeginning(self, value):
        new_node = self.Node(value)
        new_node.next = self.head  # El nuevo nodo apunta al anterior primer nodo
        self.head = new_node  # Actualizar head para que apunte al nuevo nodo
    
    def insertAtEnd(self, value):
        new_node = self.Node(value)
        
        if self.head is None:  # Si la lista esta vacia
            self.head = new_node
            return
        
        current = self.head
        while current.next:  # Recorrer hasta encontrar el ultimo nodo
            current = current.next
        current.next = new_node  # Conectar el ultimo nodo con el nuevo
    
    def insertAtPosition(self, pos, value):
        if pos < 0:
            raise ValueError("Error: La posicion no puede ser negativa")
        
        if pos == 0:  # Insertar al inicio
            self.insertAtBeginning(value)
            return
        
        size = self.size()
        if pos > size:  # Validar que la posicion no exceda el tamaño
            raise ValueError(f"Error: Posicion {pos} fuera de rango. Tamaño actual: {size}")
        
        if pos == size:  # Insertar al final
            self.insertAtEnd(value)
            return
        
        new_node = self.Node(value)
        current = self.head
        
        for i in range(pos - 1):  # Avanzar hasta la posicion anterior a donde insertar
            current = current.next
        # Insertar el nuevo nodo entre current y current.next
        new_node.next = current.next
        current.next = new_node
    
    def deleteValue(self, value):
        if self.head is None:  # Lista vacia
            return False
        
        if self.head.data == value:  # Eliminar el primer nodo
            self.head = self.head.next
            return True
        
        current = self.head
        while current.next:
            if current.next.data == value:  # Encontrado el nodo a eliminar
                current.next = current.next.next  # Saltar el nodo a eliminar
                return True
            current = current.next
        
        return False  # Valor no encontrado
    
    def search(self, value):
        current = self.head
        while current:
            if current.data == value:
                return True
            current = current.next
        return False
    
    def display(self):
        if self.head is None:
            print("Lista vacia: []")
            return
        
        elements = []
        current = self.head
        while current:
            elements.append(str(current.data))
            current = current.next
        print(f"Lista: [{', '.join(elements)}]")
    
    def get_list(self):
        elements = []
        current = self.head
        while current:
            elements.append(current.data)
            current = current.next
        return elements
    
    def __str__(self):
        if self.head is None:
            return "LinkedList: []"
        
        elements = []
        current = self.head
        while current:
            elements.append(str(current.data))
            current = current.next
        return f"LinkedList: [{' -> '.join(elements)}]"  # Mostrar conexiones con flechas
    
    def __repr__(self):
        return self.__str__()
