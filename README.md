# Binary Search Tree
Este proyecto consiste en la implementación de un Binary Search Tree en C++, utilizando clases, punteros y estructuras de stack para realizar recorridos iterativos.

## Que incluye?
La clase BinarySearchTree permite:
- Insertar elementos en el arbol
- Buscar si  un valor existe o no
- Eliminar nodos (sin hijos, con uno o con dos)
- Mostrar el arbol en consola
- Recorrer el arbol en:
  - Orden (inorder)
  - Preorder (preorder)
  - Postorder (postorder)
  
## Como compilar
```
g++ main.cpp BinarySearchTree.cpp -o bst
./bst
```


## Ejemplo de salida
```
Inorder: 4 12 20 30 49 80 

Preorder: 20 12 4 49 30 80 

Postorder: 4 12 20 30 49 80 

----------------------
1 - Si existe
0 - No existe
1 - Si existe
----------------------
        80
    49
        30
20
    12
        4
----------------------
    49
30
    12
        4
----------------------
    50
30
    12
        4
----------------------

```
