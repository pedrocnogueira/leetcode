# 69. Sqrt(x)

**Difficulty:** Easy 

## Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

  ### Example 1

    **Input:** `nums = [3,0,1]`  
    **Output:** `2`  
    **Explanation:** `n = 3` since there are 3 numbers, so all numbers are in the range `[0,3]`. 2 is the missing number in the range since it does not appear in `nums`.

  ### Example 2

    **Input:** `nums = [0,1]`  
    **Output:** `2`  
    **Explanation:** `n = 2` since there are 2 numbers, so all numbers are in the range `[0,2]`. 2 is the missing number in the range since it does not appear in `nums`.

  ### Example 3

    **Input:** `nums = [9,6,4,2,3,5,7,0,1]`  
    **Output:** `8`  
    **Explanation:** `n = 9` since there are 9 numbers, so all numbers are in the range `[0,9]`. 8 is the missing number in the range since it does not appear in `nums`.

# My Solution

Although this exercise is listed on the Binary Search Playlist, we can solve it without binary search in a more efficient way.

My solution uses the arithmetic progression formula for the sum of numbers from `0` to `n`:

`expectedSum = n * (n + 1) / 2`

If we subtract every value in the array from this expected sum, the remaining value is exactly the missing number.

In code, I initialize `sum` with `numsSize * (numsSize + 1) / 2`, then iterate once through `nums`, doing `sum -= nums[i]`. At the end, `sum` is the answer.

### Complexity Analysis

- **Time Complexity:** `O(n)` because we scan the array once.
- **Space Complexity:** `O(1)` because we only use a few variables.

### Why this is more efficient than Binary Search

A binary-search-based solution for this problem requires sorting first if the array is not already sorted. Sorting costs `O(n log n)`, and then binary search adds `O(log n)`, resulting in `O(n log n)` overall.

This sum-based approach avoids sorting entirely and solves the problem in linear time, `O(n)`, with constant extra space, making it faster for larger inputs.

