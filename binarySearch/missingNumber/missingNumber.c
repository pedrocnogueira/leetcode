#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    int sum = numsSize*(numsSize+1) / 2;
    for (int i = 0; i < numsSize; i++) {
        sum -= nums[i];
    }
    return sum;
}

int main(void) {

    int e1[3] = {3, 0, 1};
    int e2[2] = {0, 1};
    int e3[9] = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    printf("Missing in e1: %d\n", missingNumber(e1, 3));
    printf("Missing in e2: %d\n", missingNumber(e2, 2));
    printf("Missing in e3: %d\n", missingNumber(e3, 9));

    return 0;

}