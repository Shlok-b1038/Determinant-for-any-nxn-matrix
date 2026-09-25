#include "input.h"

int main() {
    int size;
    printf("Enter the size of the square matrix (nxn): ");
    scanf("%d", &size);
    int **matrix = malloc((size)*sizeof(int*));
    int *data = malloc((size)*(size)*sizeof(int));

    for (int i = 0; i < size; i++) {
        matrix[i] = data + i*size;
    };

    takeInput(size, matrix);
    printMatrix(size, matrix);

    printf("%ll\n", determinant(size, matrix));

    return 0;
};
