// Store 'n' number (integer or real) in an array. Conduct a linear search for a given number and report success or failure in the form of a suitable message.

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;   
        }
    }
    return -1;  
}

int main() {
    int arr[100], n, i, key, result;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter number to search: ");
    scanf("%d", &key);

    // Function call
    result = linearSearch(arr, n, key);

    // Output result
    if(result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found in the array\n");

    return 0;
}


   