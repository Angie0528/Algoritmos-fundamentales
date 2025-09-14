#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>

/**
 * Estructura para representar un par clave-valor en la tabla hash
 */
struct HashEntry {
    std::string key;
    std::string value;
    bool deleted;  // Flag para marcar elementos eliminados (lazy deletion)
    
    HashEntry() : key(""), value(""), deleted(false) {}
    HashEntry(const std::string& k, const std::string& v) 
        : key(k), value(v), deleted(false) {}
};

/**
 * Clase HashTable - Implementación de tabla hash con quadratic probing
 * para resolución de colisiones
 */
class HashTable {
private:
    std::vector<HashEntry> table;  // Array dinámico para almacenar los elementos
    int capacity;                  // Tamaño de la tabla
    int size;                     // Número de elementos activos
    
    /**
     * Función hash simple usando el método de división
     * @param key: clave a hashear
     * @return: índice en la tabla
     */
    int hashFunction(const std::string& key);
    
    /**
     * Encuentra la posición de una clave usando quadratic probing
     * @param key: clave a buscar
     * @return: índice donde está o donde debería estar la clave
     */
    int findPosition(const std::string& key);
    
    /**
     * Verifica si la tabla necesita ser redimensionada
     * @return: true si el factor de carga > 0.7
     */
    bool needsResize();
    
    /**
     * Redimensiona la tabla cuando el factor de carga es muy alto
     */
    void resize();

public:
    /**
     * Constructor: inicializa la tabla hash con capacidad inicial
     * @param initialCapacity: tamaño inicial de la tabla (default: 11)
     */
    explicit HashTable(int initialCapacity = 11);
    
    /**
     * Destructor
     */
    ~HashTable();
    
    /**
     * Inserta un par clave-valor en la tabla
     * @param key: clave del elemento
     * @param value: valor asociado a la clave
     * @return: true si se insertó correctamente, false si ya existía
     */
    bool insert(const std::string& key, const std::string& value);
    
    /**
     * Obtiene el valor asociado a una clave
     * @param key: clave a buscar
     * @return: valor asociado o string vacío si no existe
     */
    std::string get(const std::string& key);
    
    /**
     * Elimina un elemento de la tabla
     * @param key: clave del elemento a eliminar
     * @return: true si se eliminó correctamente, false si no existía
     */
    bool remove(const std::string& key);
    
    /**
     * Muestra el contenido completo de la tabla hash
     */
    void display();
    
    /**
     * Obtiene información estadística de la tabla
     */
    void showStats();
    
    /**
     * Verifica si la tabla está vacía
     * @return: true si no tiene elementos
     */
    bool isEmpty();
    
    /**
     * Obtiene el número de elementos en la tabla
     * @return: cantidad de elementos activos
     */
    int getSize();
};