// Create an array 'a1' with 'n' elements. Insert an element in 'i'th posotion of 'a1' and also delete an element from 'j'th position of 'a1'.

#include <stdio.h>

int main() {
    int a1[100], n, i, j, element, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a1[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    for (i = n; i >= pos; i--) {
        a1[i] = a1[i - 1];
    }
    a1[pos - 1] = element;
    n++;

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a1[i]);
    }

    printf("\nEnter position to delete (1 to %d): ", n);
    scanf("%d", &j);

    for (i = j - 1; i < n - 1; i++) {
        a1[i] = a1[i + 1];
    }
    n--;

    printf("Array after deletion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a1[i]);
    }

    return 0;
}
