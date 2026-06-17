// Find the sum of rows and columns of a matrix of given order (row x columns).

#include <stdio.h>

int main() {
    int matrix[10][10], row, col;
    int rowSum[10] = {0}, colSum[10] = {0};
    int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
        {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    printf("Sum of each row:\n");
    for (i = 0; i < row; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }

    printf("Sum of each column:\n");
    for (j = 0; j < col; j++) {
        printf("Column %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}