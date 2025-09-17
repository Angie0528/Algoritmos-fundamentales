class LinkedList:
    
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
    
    def __init__(self):
        self.head = None
    
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
        new_node.next = self.head
        self.head = new_node
    
    def insertAtEnd(self, value):
        new_node = self.Node(value)
        
        if self.head is None:
            self.head = new_node
            return
        
        current = self.head
        while current.next:
            current = current.next
        
        current.next = new_node
    
    def insertAtPosition(self, pos, value):
        if pos < 0:
            raise ValueError("Error: La posicion no puede ser negativa")
        
        if pos == 0:
            self.insertAtBeginning(value)
            return
        
        size = self.size()
        if pos > size:
            raise ValueError(f"Error: Posicion {pos} fuera de rango. Tamaño actual: {size}")
        
        if pos == size:
            self.insertAtEnd(value)
            return
        
        new_node = self.Node(value)
        current = self.head
        
        for i in range(pos - 1):
            current = current.next
        
        new_node.next = current.next
        current.next = new_node
    
    def deleteValue(self, value):
        if self.head is None:
            return False
        
        if self.head.data == value:
            self.head = self.head.next
            return True
        
        current = self.head
        while current.next:
            if current.next.data == value:
                current.next = current.next.next
                return True
            current = current.next
        
        return False
    
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
        
        return f"LinkedList: [{' -> '.join(elements)}]"
    
    def __repr__(self):
        return self.__str__()

