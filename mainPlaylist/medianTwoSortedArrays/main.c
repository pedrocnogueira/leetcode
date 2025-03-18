#include <stdio.h>
#include <stdlib.h>

int findPredecessor(int *arr, int n, int target){
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] < target) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return (result == -1) ? -1 : arr[result];
}

void insertAndShiftRight(int* arr, int size, int index, int n) {
    int buffer = arr[index];
    arr[index] = n;

    for (int i = index + 1; i < size; i++) {
        int buffer2 = arr[i];
        arr[i] = buffer;
        buffer = buffer2;
    }
}

int cmpFunction(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int combinedSize = nums1Size + nums2Size;
    int *merged = malloc(sizeof(int) * combinedSize);

    // Copy nums1
    for (int i = 0; i < nums1Size; i++)
    {
        merged[i] = nums1[i];
    }
    // Copy nums2
    for (int i = 0; i < nums2Size; i++)
    {
        merged[nums1Size + i] = nums2[i];
    }

    // Sort merged
    qsort(merged, combinedSize, sizeof(int), cmpFunction);

    // Find median
    double median;
    if (combinedSize % 2 == 1)
    {
        median = (double)merged[combinedSize / 2];
    }
    else
    {
        median = (merged[combinedSize / 2 - 1] + merged[combinedSize / 2]) / 2.0;
    }
}

int main(void) {
    // Example 1:
    int nums1_1[] = {1, 3};
    int nums2_1[] = {2};
    double median1 = findMedianSortedArrays(nums1_1, 2, nums2_1, 1);
    printf("Median for Example 1: %f\n", median1);

    // Example 2:
    int nums1_2[] = {1, 2};
    int nums2_2[] = {3, 4};
    double median2 = findMedianSortedArrays(nums1_2, 2, nums2_2, 2);
    printf("Median for Example 2: %f\n", median2);

    return 0;
}
