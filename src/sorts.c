/**
 * @author: Anthony Palumbo
 * date: 12-27-2016
 * description: source file for sorting algorithms
 */

#include <stdio.h>
#include "../include/Sorting.h"

/**
 * Prints the array given.
 * @param pData: a pointer to the Array
 * @param size: the size of the array
 * @param type: string that is printed along with the array
 */
void printArray(int *pData, int size, char *type) {
    printf("%s Array:\n", type);
    int ctr;
    for (ctr = 0; ctr < size; ctr ++) {
        printf("%d\n", pData[ctr]);
    }
}

/**
 * Uses the insertion sort algorithm to sort an array.
 * @param pData: a pointer to the unsorted array
 * @param size: the size of the array
 */
void insertionSort(int *pData, int size) {
    int i, j, k;
    for (i = 1; i <= size; i++) {
        j = i;
        while (j > 0 && pData[j] < pData[j - 1]) {
            k = pData[j];
            pData[j] = pData[j - 1];
            pData[j - 1] = k;
            j--;
        }
    }
}

/**
 * Uses the merge sort algorithm to sort an array.
 * @param pData: a pointer to the unsorted array
 * @param pDataB: a pointer to an empty array used during sorting
 * @param low: the start index
 * @param high: the end index
 */
void mergeSort(int *pData, int *pDataB, int low, int high) {
    int mid, l1, l2, i;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(pData, pDataB, low, mid);
        mergeSort(pData, pDataB, mid+1, high);
        for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
            if (pData[l1] <= pData[l2]) {
                pDataB[i] = pData[l1++];
            } else {
                pDataB[i] = pData[l2++];
            }
        }

        while (l1 <= mid) {
            pDataB[i++] = pData[l1++];
        }

        while (l2 <= high) {
            pDataB[i++] = pData[l2++];
        }

        for (i = low; i <= high; i++) {
            pData[i] = pDataB[i];
        }
    } else {
        return;
    }
}

/**
 * Helper function for quick sort.
 * @param x: memory address of the first integer
 * @param y: memory address of the second integer
 */
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Helper function for quick sort.
 * @param i: the minimum index
 * @param j: the maximum index
 * @return: the pivot index
 */
int choosePivot(int i, int j) {
    return (i + j) / 2;
}

/**
 * Uses the quick sort algorithm to sort an array.
 * @param pData: a pointer to the array
 * @param m: the minimum index
 * @param n: the maximum index
 */
void quickSort(int *pData, int m, int n) {
    int key, i, j, k;
    if (m < n) {
        k = choosePivot(m, n);
        swap(&pData[m], &pData[k]);
        key = pData[m];
        i = m + 1;
        j = n;
        while (i <= j) {
            while (i <= n && pData[i] <= key) {
                i++;
            }
            while (j >= m && pData[j] > key) {
                j--;
            }
            if (i < j) {
                swap(&pData[i], &pData[j]);
            }
        }
        swap(&pData[m], &pData[j]);
        quickSort(pData, m, j - 1);
        quickSort(pData, j + 1, n);
    }
}

/**
 * Helper function for heap sort.
 * @param pData: a pointer to the array
 * @param size: the size of the array
 */
void makeHeap(int *pData, int size) {
    int k, i, j, item;

    for (k = 1; k < size; k++) {
        item = pData[k];
        i = k;
        j = (i - 1) / 2;
        while (i > 0 && item > pData[j]) {
            pData[i] = pData[j];
            i = j;
            j = (i - 1) / 2;
        }
        pData[i] = item;
    }
}

/**
 * Helper function for heap sort.
 * @param pData: a pointer to the array
 * @param size: the size of the array
 */
void adjust(int *pData, int size) {
    int i, j, item;
    j = 0;
    item = pData[j];
    i = 2 * j + 1;
    while (i <= size - 1) {
        if (i + 1 <= size - 1) {
            if (pData[i] < pData[i + 1]) {
                i++;
            }
        }
        if (item < pData[i]) {
            pData[j] = pData[i];
            j = i;
            i = 2 * j + 1;
        } else {
            break;
        }
    }
    pData[j] = item;
}

/**
 * Uses the heap sort algorithm to sort an array.
 * @param pData: a pointer to the array
 * @param size: the size of the array
 */
void heapSort(int *pData, int size) {
    int i, t;
    makeHeap(pData, size);
    for (i = size - 1; i > 0; i--) {
        t = pData[0];
        pData[0] = pData[i];
        pData[i] = t;
        adjust(pData, i);
    }
}

/**
 * Uses the selection sort algorithm to sort an array.
 * @param pData: a pointer to the array
 * @param size: the size of the array
 */
void selectionSort(int *pData, int size) {
    int i, j, min, temp;
    for (i = 0; i < size; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (pData[j] < pData[min]) {
                min = j;
            }
        }
        temp = pData[i];
        pData[i] = pData[min];
        pData[min] = temp;
    }
}

/**
 * Uses the bubble sort algorithm to sort an array.
 * @param pData: a pointer to the array
 * @param size: the size of the array
 */
void bubbleSort(int *pData, int size) {
    int i, j, temp;
    for (i = size - 1; i >= 0; i--) {
        for (j = 1; j <= i; j++) {
            if (pData[j - 1] > pData[j]) {
                temp = pData[j - 1];
                pData[j - 1] = pData[j];
                pData[j] = temp;
            }
        }
    }
}
