/**
 * @author: Anthony Palumbo
 * date: 12-27-2016
 * description: header file for sorting algorithms
 */

#ifndef SORTING_H
#define SORTING_H

void printArray(int *pData, int size, char *type);
void insertionSort(int *pData, int size);
void mergeSort(int *pData, int *pDataB, int low, int high);
void quickSort(int *pData, int m, int n);
void heapSort(int *pData, int size);
void selectionSort(int *pData, int size);
void bubbleSort(int *pData, int size);

#endif
