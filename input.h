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

void determinant(int size, int **matrix) {
    int *reference = matrix[0];
    int realValue = 0;
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", reference[i]);
    // };
    int *row = malloc((size - 1)*(size - 1)*sizeof(int));

    for (int k = 0; k < size; k++) {
        int counter = 0;
        for (int i = 1; i  < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j == k) continue;
                else {
                    row[counter] = matrix[i][j];
                    counter++;
                };
            }; 
        };
        int detValue = pow(-1, k)*reference[k]*simpleSolver(row);
        realValue += detValue;
    };

    printf("Determinant is %d\n", realValue);
};
