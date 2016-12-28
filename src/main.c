/**
 * @author: Anthony Palumbo
 * date: 12-27-2016
 * description: main source file for sorting algorithms project
 */

#include <stdio.h>
#include <time.h>
#include "../include/Sorting.h"

#define MAXSIZE 100000

/**
 * Resets the new array to the original array.
 * @param pOriginal: a pointer to the original array
 * @param pNew: a pointer to the new array
 * @param size: the size of the array
 */
void resetArray(int *pOriginal, int *pNew, int size) {
    int ctr;
    for(ctr = 0; ctr < size; ctr++) {
        pNew[ctr] = pOriginal[ctr];
    }
}

/**
 * Main function that is run initially.
 * @return: 0 on exit success
 */
int main(void) {
    clock_t start, end;
    double totalTime;
    int ctr, count;
    FILE *pFile = fopen("input/test.txt", "r");
    if(pFile == NULL) {
        printf("Error reading file.\n");
    }
    int data[MAXSIZE];

    ctr = 0;
    int scan;

    // Reads in the numbers from the text file.
    while(!feof(pFile)) {
        scan = fscanf(pFile, "%d", &data[ctr]);
        ctr++;
    }

    // Copies the data to a fresh array that can be used for sorting.
    int cleanedData[ctr];
    for(count = 0; count < ctr; count++) {
        cleanedData[count] = data[count];
    }
    int *pOrig = data;
    int *pCleanData = cleanedData;

    // Runs bubble sort.
    start = clock();
    bubbleSort(pCleanData, ctr);
    end = clock();
    totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: \t%.10f seconds.\n", totalTime);
    resetArray(pOrig, pCleanData, ctr);

    // Runs insertion sort.
    start = clock();
    insertionSort(pCleanData, ctr);
    end = clock();
    totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: \t%.10f seconds.\n", totalTime);
    resetArray(pOrig, pCleanData, ctr);

    // Runs selection sort.
    start = clock();
    selectionSort(pCleanData, ctr);
    end = clock();
    totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Time: \t%.10f seconds.\n", totalTime);
    resetArray(pOrig, pCleanData, ctr);

    // Runs heap sort.
    start = clock();
    heapSort(pCleanData, ctr);
    end = clock();
    totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Heap Sort Time: \t%.10f seconds.\n", totalTime);
    resetArray(pOrig, pCleanData, ctr);

    // Runs merge sort.
    start = clock();
    int dataB[ctr];
    int *pDataB = dataB;
    mergeSort(pCleanData, pDataB, 0, ctr - 1);
    end = clock();
    totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Time: \t%.10f seconds.\n", totalTime);
    resetArray(pOrig, pCleanData, ctr);

    // Runs quick sort.
    start = clock();
    quickSort(pCleanData, 0, ctr);
    end = clock();
    totalTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: \t%.10f seconds.\n", totalTime);
    resetArray(pOrig, pCleanData, ctr);

    fclose(pFile);
    return 0;
}
