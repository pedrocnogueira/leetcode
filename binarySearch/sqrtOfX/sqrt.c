#include <stdio.h>

int mySqrt(int x) {
    int low = 0;
    int high = x;
    int mid;

    while (low <= high) {
        mid = low + (high - low)/2;
        long long mid2 = (long long)mid * mid;
        if (mid2 == x) {
            return mid;
        }

        if (mid2 < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}

int main(void) {
    int tests[] = {
        0,
        1,
        4,
        8,
        15,
        16,
        2147395600, // (46340^2) - highest square < 2^31-1
        2147483647  // 2^31 - 1, highest allowed value
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < num_tests; i++) {
        int x = tests[i];
        int res = mySqrt(x);
        printf("mySqrt(%d) = %d\n", x, res);
    }
    return 0;
}
