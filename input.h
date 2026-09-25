#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 0; i < size - 1; i++) {
        cofactorMatrix[i] = data + i*(size - 1);
    };

    return cofactorMatrix;
};

void freeMatrix(int **matrix) {
    free(matrix[0]);
    free(matrix);
};

int resolveMatrix(int **matrix) {
    return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
};

long long int determinant(int size, int **matrix) {
    long long int overallValue = 0;
    
    if (size == 2) {
        return resolveMatrix(matrix);
    }
    else {
        int *reference = matrix[0];
        for (int i = 0; i < size; i++) {
            int sign = -1;
            if (i%2 == 0) sign = 1;
            int **cofactorMatrix = cofactor(size, matrix, i);
            int value = determinant(size - 1, cofactorMatrix);
            overallValue += value*reference[i]*sign;
            freeMatrix(cofactorMatrix);
        };
    };

    return overallValue;
};

