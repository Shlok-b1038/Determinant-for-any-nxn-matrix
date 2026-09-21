#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getInput(int size, int **matrix) { 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value;
            printf("Enter the value at %d, %d: ", i, j);
            scanf("%d", &value);
            matrix[i][j] = value;
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

int simpleSolver(int *cofactor) {
    int det = (cofactor[0]*cofactor[3]) - (cofactor[1]*cofactor[2]);

    return det;
};

void **cofactor(int size, int **matrix, int target) {
    // int **c_matrix = malloc(size*sizeof(int*));
    int *data = malloc((size - 1)*(size - 1)*sizeof(int));
    int counter = 0;
    for (int i =1; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == target) continue;
            else {
                data[counter] = matrix[i][j];
                // printf("%d at %d \n", matrix[i][j], counter);
                counter++;
            };
        };
    };

    for (int i = 0; i < (size - 1)*(size - 1); i++) {
        printf("%d ", data[i]);
    };
    printf("\n");

    free(data);
};

void determinant(int size, int **matrix) {
    // int *reference = matrix[0];
    // cofactor(size, matrix, 0);
    for (int i = 0; i < size; i++) {
        cofactor(size, matrix, i);
    };
};
