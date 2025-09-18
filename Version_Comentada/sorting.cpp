#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>

// Bubble Sort - O(n²)
// Compara elementos adyacentes e intercambia si estan desordenados
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // Optimizacion: detecta si ya esta ordenado
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // Compara elementos adyacentes
                std::swap(arr[j], arr[j + 1]);  // Intercambia si estan desordenados
                swapped = true;
            }
        }
        
        if (!swapped) break;  // Si no hubo intercambios, ya esta ordenado
    }
}

// Selection Sort - O(n²)
// Encuentra el minimo y lo coloca en la posicion correcta
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Asume que el primer elemento es el minimo
        
        // Busca el elemento minimo en el resto del arreglo
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Actualiza el indice del minimo
            }
        }
        
        // Intercambia el minimo encontrado con el primer elemento
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

// Insertion Sort - O(n²)
// Inserta cada elemento en su posicion correcta en la sublista ordenada
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Elemento a insertar
        int j = i - 1;
        
        // Mueve elementos mayores que la key a una posicion adelante
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;  // Inserta la key en su posicion correcta
    }
}

// Funciones utilitarias
void printArray(const std::vector<int>& arr, const std::string& label) {
    if (!label.empty()) {
        std::cout << label << ": ";
    }
    
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}


// Merge Sort - O(n log n)
// Divide y venceras: divide el arreglo y luego fusiona
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Evita overflow
        
        // Divide: ordena recursivamente ambas mitades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Y Venceras jaja: fusiona las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Funcion auxiliar para fusionar dos subarreglos ordenados
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Tamaño del subarreglo izquierdo
    int n2 = right - mid;     // Tamaño del subarreglo derecho
    
    // Crear arreglos temporales
    std::vector<int> leftArr(n1), rightArr(n2);
    
    // Copia los datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Fusiona los arreglos temporales de vuelta al arreglo original
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copia elementos restantes del subarreglo izquierdo
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copia elementos restantes del subarreglo derecho
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Quick Sort - O(n log n) promedio, O(n²) peor caso
// Selecciona un pivote y particiona el arreglo
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Particion: encuentra la posicion correcta del pivote
        int pi = partition(arr, low, high);
        
        // Ordena recursivamente los elementos antes y despues del pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Funcion auxiliar para particionar el arreglo
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Elegir el ultimo elemento como pivote
    int i = low - 1;        // Indice del elemento menor
    
    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    // Coloca el pivote en su posicion correcta
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

