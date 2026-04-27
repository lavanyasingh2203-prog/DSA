#include <stdio.h>

int integerSquareRoot(int n) {
    int low = 0, high = n, mid;
    int ans = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (mid * mid == n) {
            return mid;
        }
        else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSquareRoot(n));

    return 0;
}