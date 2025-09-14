#include "HashTable.h"
#include <iostream>
#include <string>

void testBasicOperations(HashTable& ht);
void testCollisions(HashTable& ht);
void testEdgeCases(HashTable& ht);
void separator(const std::string& title);

int main() {
    std::cout << "=== DEMOSTRACIÓN DE TABLA HASH CON QUADRATIC PROBING ===" << std::endl;
    
    // Crear tabla hash con capacidad inicial pequeña para forzar colisiones
    HashTable hashTable(7);
    
    // Ejecutar pruebas
    testBasicOperations(hashTable);
    testCollisions(hashTable);
    testEdgeCases(hashTable);
    
    std::cout << "\n=== FIN DE LAS PRUEBAS ===" << std::endl;
    return 0;
}

void testBasicOperations(HashTable& ht) {
    separator("PRUEBAS DE OPERACIONES BÁSICAS");
    
    std::cout << "1. Insertando elementos iniciales..." << std::endl;
    ht.insert("nombre", "Juan");
    ht.insert("edad", "25");
    ht.insert("ciudad", "Guadalajara");
    ht.insert("profesion", "Ingeniero");
    
    ht.showStats();
    
    std::cout << "2. Buscando elementos existentes..." << std::endl;
    ht.get("nombre");
    ht.get("edad");
    ht.get("ciudad");
    
    std::cout << "\n3. Buscando elemento inexistente..." << std::endl;
    ht.get("telefono");
    
    std::cout << "\n4. Actualizando valor existente..." << std::endl;
    ht.insert("edad", "26");  // Actualizar edad
    ht.get("edad");
    
    ht.display();
}

void testCollisions(HashTable& ht) {
    separator("PRUEBAS DE MANEJO DE COLISIONES");
    
    std::cout << "Insertando claves que pueden generar colisiones..." << std::endl;
    
    // Estas claves pueden generar colisiones dependiendo de la función hash
    ht.insert("abc", "valor1");
    ht.insert("bca", "valor2");  // Suma ASCII similar a "abc"
    ht.insert("cab", "valor3");  // Suma ASCII similar a "abc" y "bca"
    ht.insert("universidad", "ITESO");
    ht.insert("materia", "Estructuras");
    
    std::cout << "\nBuscando elementos después de colisiones..." << std::endl;
    ht.get("abc");
    ht.get("bca");
    ht.get("cab");
    ht.get("universidad");
    
    ht.display();
    ht.showStats();
}

void testEdgeCases(HashTable& ht) {
    separator("PRUEBAS DE CASOS ESPECIALES");
    
    std::cout << "1. Eliminando elementos..." << std::endl;
    ht.remove("abc");
    ht.remove("profesion");
    ht.remove("elemento_inexistente");  // Intentar eliminar algo que no existe
    
    ht.display();
    
    std::cout << "\n2. Verificando que elementos eliminados no se pueden encontrar..." << std::endl;
    ht.get("abc");
    ht.get("profesion");
    
    std::cout << "\n3. Re-insertando en posiciones eliminadas..." << std::endl;
    ht.insert("nuevo_elemento", "nuevo_valor");
    ht.insert("otro_elemento", "otro_valor");
    
    std::cout << "\n4. Forzando redimensionamiento con más inserciones..." << std::endl;
    ht.insert("elemento1", "valor1");
    ht.insert("elemento2", "valor2");
    ht.insert("elemento3", "valor3");
    ht.insert("elemento4", "valor4");
    ht.insert("elemento5", "valor5");
    
    ht.display();
    ht.showStats();
    
    std::cout << "\n5. Verificando estado final..." << std::endl;
    std::cout << "Tabla vacía: " << (ht.isEmpty() ? "Sí" : "No") << std::endl;
    std::cout << "Número de elementos: " << ht.getSize() << std::endl;
}

void separator(const std::string& title) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}