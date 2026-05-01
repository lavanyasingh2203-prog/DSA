#include <stdio.h>

// Check if possible within given time
int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return 0;

        if (time + arr[i] > mid) {
            painters++;
            time = arr[i];

            if (painters > k)
                return 0;
        } else {
            time += arr[i];
        }
    }

    return 1;
}

// Main function
int minTime(int arr[], int n, int k) {
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

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1; // increase time
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", minTime(arr, n, k));

    return 0;
}
