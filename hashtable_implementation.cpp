#include "HashTable.h"
#include <iomanip>

// Constructor: inicializa la tabla con capacidad dada
HashTable::HashTable(int initialCapacity) : capacity(initialCapacity), size(0) {
    table.resize(capacity);
    std::cout << "Tabla hash creada con capacidad: " << capacity << std::endl;
}

// Destructor
HashTable::~HashTable() {
    std::cout << "Tabla hash destruida." << std::endl;
}

// Función hash simple usando método de división
int HashTable::hashFunction(const std::string& key) {
    int hashValue = 0;
    // Suma los valores ASCII de todos los caracteres
    for (char c : key) {
        hashValue += static_cast<int>(c);
    }
    // Aplica módulo para obtener índice válido
    return hashValue % capacity;
}

// Encuentra posición usando quadratic probing
int HashTable::findPosition(const std::string& key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;
    
    // Quadratic probing: h(k) + i²
    while (!table[index].key.empty() && table[index].key != key && !table[index].deleted) {
        index = (originalIndex + i * i) % capacity;
        i++;
        
        // Evitar bucle infinito si la tabla está llena
        if (i > capacity) {
            return -1;
        }
    }
    
    return index;
}

// Verifica si necesita redimensionarse (factor de carga > 0.7)
bool HashTable::needsResize() {
    return (static_cast<double>(size) / capacity) > 0.7;
}

// Redimensiona la tabla duplicando su tamaño
void HashTable::resize() {
    std::cout << "Redimensionando tabla de " << capacity << " a ";
    
    // Guardar datos actuales
    std::vector<HashEntry> oldTable = table;
    int oldCapacity = capacity;
    
    // Duplicar capacidad (usar siguiente número primo para mejor distribución)
    capacity = capacity * 2 + 1;
    size = 0;
    table.clear();
    table.resize(capacity);
    
    std::cout << capacity << " elementos." << std::endl;
    
    // Re-insertar todos los elementos no eliminados
    for (int i = 0; i < oldCapacity; i++) {
        if (!oldTable[i].key.empty() && !oldTable[i].deleted) {
            insert(oldTable[i].key, oldTable[i].value);
        }
    }
}

// Inserta un par clave-valor
bool HashTable::insert(const std::string& key, const std::string& value) {
    // Verificar si necesita redimensionarse
    if (needsResize()) {
        resize();
    }
    
    int index = findPosition(key);
    
    if (index == -1) {
        std::cout << "Error: No se puede insertar, tabla llena." << std::endl;
        return false;
    }
    
    // Si la clave ya existe y no está eliminada, actualizar valor
    if (!table[index].key.empty() && table[index].key == key && !table[index].deleted) {
        table[index].value = value;
        std::cout << "Valor actualizado para clave: " << key << std::endl;
        return true;
    }
    
    // Insertar nuevo elemento
    table[index] = HashEntry(key, value);
    size++;
    std::cout << "Insertado: [" << key << " -> " << value << "] en posición " << index << std::endl;
    return true;
}

// Obtiene el valor asociado a una clave
std::string HashTable::get(const std::string& key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;
    
    // Buscar usando quadratic probing
    while (!table[index].key.empty()) {
        if (table[index].key == key && !table[index].deleted) {
            std::cout << "Encontrado: [" << key << " -> " << table[index].value 
                      << "] en posición " << index << std::endl;
            return table[index].value;
        }
        
        index = (originalIndex + i * i) % capacity;
        i++;
        
        if (i > capacity) break;
    }
    
    std::cout << "Clave '" << key << "' no encontrada." << std::endl;
    return "";
}

// Elimina un elemento (lazy deletion)
bool HashTable::remove(const std::string& key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;
    
    // Buscar el elemento usando quadratic probing
    while (!table[index].key.empty()) {
        if (table[index].key == key && !table[index].deleted) {
            table[index].deleted = true;  // Marcar como eliminado
            size--;
            std::cout << "Eliminado: [" << key << "] de la posición " << index << std::endl;
            return true;
        }
        
        index = (originalIndex + i * i) % capacity;
        i++;
        
        if (i > capacity) break;
    }
    
    std::cout << "No se puede eliminar: clave '" << key << "' no encontrada." << std::endl;
    return false;
}

// Muestra el contenido completo de la tabla
void HashTable::display() {
    std::cout << "\n=== CONTENIDO DE LA TABLA HASH ===" << std::endl;
    std::cout << std::setw(6) << "Índice" << std::setw(15) << "Clave" 
              << std::setw(15) << "Valor" << std::setw(12) << "Estado" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (int i = 0; i < capacity; i++) {
        std::cout << std::setw(6) << i;
        
        if (table[i].key.empty()) {
            std::cout << std::setw(15) << "--" << std::setw(15) << "--" 
                      << std::setw(12) << "Vacío" << std::endl;
        } else if (table[i].deleted) {
            std::cout << std::setw(15) << table[i].key << std::setw(15) << table[i].value 
                      << std::setw(12) << "Eliminado" << std::endl;
        } else {
            std::cout << std::setw(15) << table[i].key << std::setw(15) << table[i].value 
                      << std::setw(12) << "Activo" << std::endl;
        }
    }
    std::cout << std::string(50, '-') << std::endl;
}

// Muestra estadísticas de la tabla
void HashTable::showStats() {
    double loadFactor = static_cast<double>(size) / capacity;
    
    std::cout << "\n=== ESTADÍSTICAS DE LA TABLA ===" << std::endl;
    std::cout << "Capacidad total: " << capacity << std::endl;
    std::cout << "Elementos activos: " << size << std::endl;
    std::cout << "Factor de carga: " << std::fixed << std::setprecision(3) 
              << loadFactor << std::endl;
    std::cout << "Espacios vacíos: " << (capacity - size) << std::endl;
    std::cout << "================================\n" << std::endl;
}

// Verifica si está vacía
bool HashTable::isEmpty() {
    return size == 0;
}

// Obtiene el tamaño actual
int HashTable::getSize() {
    return size;
}