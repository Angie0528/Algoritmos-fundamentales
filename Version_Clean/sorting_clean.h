#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <string>

void bubbleSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr, int left, int right);
void quickSort(std::vector<int>& arr, int low, int high);

void merge(std::vector<int>& arr, int left, int mid, int right);
int partition(std::vector<int>& arr, int low, int high);

void printArray(const std::vector<int>& arr, const std::string& label = "");
std::vector<int> generateRandomArray(int size, int minVal = 1, int maxVal = 100);

#endif

