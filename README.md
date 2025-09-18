# Tarea Linked List

# Video explicativo del codigo
[![Video Explicativo](https://youtu.be/tXfiSuJEbd8)](https://youtu.be/tXfiSuJEbd8)

## ¿Que es una Lista Ligada?

Una Lista Ligada es una estructura de datos donde cada elemento (nodo) contiene datos y una referencia al siguiente nodo:

```
[Dato|Next] -> [Dato|Next] -> [Dato|Next] -> NULL
     ^
   Head
```

## Lista Ligada vs Array

| Aspecto | Lista Ligada | Array |
|---------|--------------|-------|
| **Insercion/Eliminacion** | O(1) con referencia | O(n) requiere desplazamiento |
| **Acceso por indice** | O(n) debe recorrer | O(1) acceso directo |
| **Memoria** | Dinamica, solo lo necesario | Fija o redimensionable |
| **Uso recomendado** | Muchas inserciones/eliminaciones | Acceso frecuente por indice |

## Complejidad Temporal

| Operaciin | Complejidad |
|-----------|-------------|
| `insertAtBeginning()` | **O(1)** |
| `insertAtEnd()` | **O(n)** |
| `insertAtPosition()` | **O(n)** |
| `deleteValue()` | **O(n)** |
| `search()` | **O(n)** |

## Uso Rapido

```python
from linkedlist import LinkedList

lista = LinkedList()
lista.insertAtBeginning(10)
lista.insertAtEnd(20)
lista.insertAtPosition(1, 15)
lista.display()  # Output: Lista: [10, 15, 20]

print(lista.search(15))  # True
lista.deleteValue(15)
lista.display()  # Output: Lista: [10, 20]
```

## Archivos

- `linkedlist.py` - Implementación completa con documentación
- `linkedlist_clean.py` - Versión sin comentarios
- `test_linkedlist.py` - Suite de pruebas
- `documentacion.md` - Documentación técnica detallada

## Para ejecutar Pruebas

```bash
python test_linkedlist.py
```

## Metodos Principales

**Insercion:**
- `insertAtBeginning(value)`, `insertAtEnd(value)`, `insertAtPosition(pos, value)`

**Consulta:**
- `search(value)`, `display()`, `size()`, `is_empty()`

**Eliminacion:**
- `deleteValue(value)`

---

