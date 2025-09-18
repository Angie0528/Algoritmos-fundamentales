#ifndef SORTING_H
#define SORTING_H

#include <vector>

// Algoritmo Bubble Sort
// Compara pares adyacentes e intercambia si estan en orden incorrecto
void bubbleSort(std::vector<int>& arr);

// Algoritmo Selection Sort
// Selecciona el elemento minimo y lo coloca en la posicion correcta
void selectionSort(std::vector<int>& arr);

// Algoritmo Insertion Sort
// Inserta cada elemento en la sublista ordenada
void insertionSort(std::vector<int>& arr);

// Algoritmo Merge Sort
// Implementa divide y venceras (division y fusion)
void mergeSort(std::vector<int>& arr, int left, int right);

// Algoritmo Quick Sort
// Selecciona pivote y particiona el arreglo
void quickSort(std::vector<int>& arr, int low, int high);

// Funciones auxiliares para algoritmos avanzados
void merge(std::vector<int>& arr, int left, int mid, int right);
int partition(std::vector<int>& arr, int low, int high);

// Funciones utilitarias
void printArray(const std::vector<int>& arr, const std::string& label = "");
std::vector<int> generateRandomArray(int size, int minVal = 1, int maxVal = 100);

#endif // SORTING_H

