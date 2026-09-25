#include <stdio.h>
#include <stdlib.h>

#include <math.h>

void takeInput(int size, int **matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter the value at %d, %d: ", i, j);
            scanf("%d", matrix[i] + j);
            // matrix[i][j] = *(matrix[i] + j)
            // matrix[i][j] will point out to the integer in the matrix itself
            // matrix[i] + j will point to the pointer in the 2d array.
        };
    };
};

void printMatrix(int size, int **matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        };
        printf("\n");
    };
};

int** cofactor(int size, int **matrix, int target) {
    int **cofactorMatrix = malloc((size-1)*sizeof(int*));
    int *data = malloc((size - 1)*(size - 1)*sizeof(int));
    int counter = 0;
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == target) continue;
            else {
                data[counter] = matrix[i][j];
                counter++;
            };
        };
    };

    for (int i = 0; i < size; i++) {
        cofactorMatrix[i] = data + i*size;
    };

    return cofactorMatrix;
};

void freeMatrix(int **matrix) {
    free(matrix[0]);
    free(matrix);
};

int determinant(int size, int **matrix) {
    int overallValue = 0;
    int *reference = matrix[0];
    int **firstCofactor = cofactor(size, matrix, 0);
    int **secondCofactor = cofactor(size, matrix, 1);
    int **thirdCofactor = cofactor(size, matrix, 2);

    printMatrix(size - 1, firstCofactor);
    printf("\n");
    printMatrix(size - 1, secondCofactor);
    printf("\n");
    printMatrix(size - 1, thirdCofactor);
    printf("\n");

    freeMatrix(firstCofactor);
    freeMatrix(secondCofactor);
    freeMatrix(thirdCofactor);

    return overallValue;
};

