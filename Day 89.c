#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int mid) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return 0;

        if (pages + arr[i] > mid) {
            students++;
            pages = arr[i];

            if (students > m)
                return 0;
        } else {
            pages += arr[i];
        }
    }

    return 1;
}

// Function to find minimum pages
int allocateBooks(int arr[], int n, int m) {
    if (m > n)
        return -1;

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1; // increase limit
        }
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int ans = allocateBooks(arr, n, m);
    printf("%d\n", ans);

    return 0;
}
