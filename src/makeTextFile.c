/**
 * @author: Anthony Palumbo
 * date: 12-27-2016
 * description: Generates a text file with random numbers.
 */

#include <stdio.h>
#define NUM_OF_INTEGERS 50000
#define MAX_VAL 1000

/**
 * Main function that is run.
 * @return: 0 on exit success
 */
int main(void) {
    FILE *pFile = fopen("input/test.txt", "a");
    int ctr, num;

    // Generates the random numbers and adds them to the file.
    for(ctr = 0; ctr < NUM_OF_INTEGERS - 1; ctr++) {
        num = rand() % MAX_VAL;
        fprintf(pFile, "%d\n", num);
    }

    // Adds the last number without a newline character.
    num = rand() % MAX_VAL;
    fprintf(pFile, "%d", num);

    fclose(pFile);

    return 0;
}
