// Find the product of two matrices using pointers. 

#include <stdio.h>

int main() {
    int matrix1[10][10], matrix2[10][10], product[10][10];
    int row1, col1, row2, col2;
    int i, j, k;

    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Error! Column of first matrix must be equal to row of second.\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Initialize product matrix to zero
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            product[i][j] = 0;
        }
    }

    // Calculate product of two matrices
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            for (k = 0; k < col1; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Product of the two matrices:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}