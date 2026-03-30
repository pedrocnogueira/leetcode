# 278. First Bad Version

**Difficulty:** Easy

## Description

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check.

Since each version is developed based on the previous version, all versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version)` which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

  ### Example 1

    **Input:** `n = 5, bad = 4`  
    **Output:** `4`  
    **Explanation:**  
    `isBadVersion(3) -> false`  
    `isBadVersion(5) -> true`  
    `isBadVersion(4) -> true`  
    Then `4` is the first bad version.

  ### Example 2

    **Input:** `n = 1, bad = 1`  
    **Output:** `1`

### Constraints

- `1 <= bad <= n <= 2^31 - 1`

# My solution

This is a classic binary search over the version range `[1, n]`.

I keep two pointers:

- `low` starts at `1`
- `high` starts at `n`

For each iteration, I test a middle version `mid`:

- If `isBadVersion(mid)` is `true`, then `mid` can still be the first bad version, so I move `high` to `mid - 1` and keep searching on the left side.
- If `isBadVersion(mid)` is `false`, then the first bad version must be after `mid`, so I move `low` to `mid + 1`.

The loop stops when `low > high`. At that point, `low` is positioned exactly at the first bad version, so I return `low`.

This minimizes API calls because each check cuts the search space roughly in half.

### Complexity Analysis

- **Time Complexity:** `O(log n)` because binary search halves the range each iteration.
- **Space Complexity:** `O(1)` because only a few integer variables are used.
