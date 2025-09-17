#include "sorting_clean.h"
#include <iostream>
#include <vector>
#include <chrono>

void testSortingAlgorithm(const std::string& algorithmName, 
                         void (*sortFunction)(std::vector<int>&),
                         std::vector<int> arr) {
    std::cout << "\n=== " << algorithmName << " ===" << std::endl;
    
    printArray(arr, "Antes");
    
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(arr);
    auto end = std::chrono::high_resolution_clock::now();
    
    printArray(arr, "Despues");
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tiempo: " << duration.count() << " microsegundos" << std::endl;
}

void testMergeSort(const std::string& algorithmName, std::vector<int> arr) {
    std::cout << "\n=== " << algorithmName << " ===" << std::endl;
    
    printArray(arr, "Antes");
    
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    
    printArray(arr, "Despues");
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tiempo: " << duration.count() << " microsegundos" << std::endl;
}

void testQuickSort(const std::string& algorithmName, std::vector<int> arr) {
    std::cout << "\n=== " << algorithmName << " ===" << std::endl;
    
    printArray(arr, "Antes");
    
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    
    printArray(arr, "Despues");
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Tiempo: " << duration.count() << " microsegundos" << std::endl;
}

int main() {
    std::cout << "PRUEBAS DE ALGORITMOS DE ORDENAMIENTO" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    std::vector<int> originalArray = generateRandomArray(12, 1, 100);
    
    std::cout << "\nVector original generado aleatoriamente:" << std::endl;
    printArray(originalArray);
    
    testSortingAlgorithm("Bubble Sort", bubbleSort, originalArray);
    testSortingAlgorithm("Selection Sort", selectionSort, originalArray);
    testSortingAlgorithm("Insertion Sort", insertionSort, originalArray);
    testMergeSort("Merge Sort", originalArray);
    testQuickSort("Quick Sort", originalArray);
    
    std::cout << "\n=== VERIFICACION DE RESULTADOS ===" << std::endl;
    
    std::vector<int> bubble = originalArray, selection = originalArray;
    std::vector<int> insertion = originalArray, merge = originalArray, quick = originalArray;
    
    bubbleSort(bubble);
    selectionSort(selection);
    insertionSort(insertion);
    mergeSort(merge, 0, merge.size() - 1);
    quickSort(quick, 0, quick.size() - 1);
    
    bool allEqual = (bubble == selection) && (selection == insertion) && 
                   (insertion == merge) && (merge == quick);
    
    if (allEqual) {
        std::cout << "✓ Todos los algoritmos produjeron el mismo resultado ordenado" << std::endl;
        printArray(bubble, "Resultado final");
    } else {
        std::cout << "✗ Error: Los algoritmos produjeron resultados diferentes" << std::endl;
    }
    
    std::cout << "\n=== CASOS ESPECIALES ===" << std::endl;
    
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::cout << "\nArreglo ya ordenado:" << std::endl;
    testSortingAlgorithm("Bubble Sort (optimizado)", bubbleSort, sorted);
    
    std::vector<int> reversed = {5, 4, 3, 2, 1};
    std::cout << "\nArreglo ordenado inversamente:" << std::endl;
    testSortingAlgorithm("Quick Sort", [](std::vector<int>& arr) {
        quickSort(arr, 0, arr.size() - 1);
    }, reversed);
    
    std::vector<int> duplicates = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    std::cout << "\nArreglo con elementos duplicados:" << std::endl;
    testMergeSort("Merge Sort", duplicates);
    
    std::cout << "\n=====================================" << std::endl;
    std::cout << "PRUEBAS COMPLETADAS" << std::endl;
    
    return 0;
}

