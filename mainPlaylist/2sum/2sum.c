#include <stdio.h>
#include <stdlib.h>

int hash(int x, int target)
{
    return target - x;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int max = target * 2;
    int *table = (int *)malloc(sizeof(int) * max);

    for (int i = 0; i < (max); i++)
    {
        table[i] = max;
    }

    int *result = (int *)malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++)
    {

        int currentNum = nums[i];

        if (table[currentNum] != max)
        {
            result[0] = i;
            result[1] = table[currentNum];
            break;
        }

        int newIndex = hash(currentNum, target);
        table[newIndex] = i;
    }

    free(table);

    return result;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    int returnSize = 0;
    int *result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL && returnSize == 2)
    {
        printf("Indices found: [%d, %d]\n", result[0], result[1]);
    }
    else
    {
        printf("No valid indices found.\n");
    }

    // Free memory if dynamically allocated in twoSum
    free(result);

    return 0;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    int returnSize = 0;
    int *result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL && returnSize == 2)
    {
        printf("Indices found: [%d, %d]\n", result[0], result[1]);
    }
    else
    {
        printf("No valid indices found.\n");
    }

    // Free memory if dynamically allocated in twoSum
    free(result);

    return 0;
}