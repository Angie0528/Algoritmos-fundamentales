class Queue:
    """Implementacion de una Cola (Queue) - estructura FIFO (First In, First Out)"""
    
    def __init__(self):
        self.items = []
    
    def enqueue(self, element):
        self.items.append(element)
    
    def dequeue(self):
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        return self.items.pop(0)
    
    def front(self):
        if self.is_empty():
            raise IndexError("front from empty queue")
        return self.items[0]
    
    def is_empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)
    
    def __str__(self):
        return f"Queue({self.items})"

