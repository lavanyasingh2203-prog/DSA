#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int low = 0, high = x;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Avoid overflow using division
        if (mid == x / mid) {
            return mid;
        }
        else if (mid < x / mid) {
            ans = mid;        // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d", mySqrt(x));

    return 0;
}