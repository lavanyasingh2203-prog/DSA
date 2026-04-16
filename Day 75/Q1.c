#include <stdio.h>

#define MAX 1000

int longestZeroSumSubarray(int arr[], int n) {
    int prefixSum = 0, maxLen = 0;

    // HashMap using arrays (simple implementation)
    int hash[2 * MAX + 1];  // to handle negative sums
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -2;  // -2 means not visited

    int offset = MAX; // shift for negative index

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: if seen before
        if (hash[prefixSum + offset] != -2) {
            int prevIndex = hash[prefixSum + offset];
            if (i - prevIndex > maxLen) {
                maxLen = i - prevIndex;
            }
        } else {
            // store first occurrence
            hash[prefixSum + offset] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("Length of longest subarray with sum 0 = %d\n", result);

    return 0;
}