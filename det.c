#include "input.h"

int main() {
    int size;
    printf("Enter the size of the square matrix (nxn): ");
    scanf("%d", &size);

    int **matrix = malloc(size*sizeof(int*));
    int *row = malloc(size*size*sizeof(int));
    
    for (int i = 0; i < size; i++) {
        matrix[i] = row + i*size;
    };

    getInput(size, matrix);
    printMatrix(size, matrix);
    // printf("cofactor matrix is\n");
    determinant(size, matrix);
    
    free(matrix);
    free(row);

    return 0;
};
