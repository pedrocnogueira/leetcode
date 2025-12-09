# 69. Sqrt(x)

## Description

Given a non-negative integer `x`, return _the square root of `x` rounded down to the nearest integer_. The returned integer should be **non-negative** as well.

You **must not use** any built-in exponent function or operator.

- For example, do not use `pow(x, 0.5)` in c++ or `x ** 0.5` in python.
 
 ### Example 1

    **Input:** `x = 4`  
    **Output:** `2`  
    **Explanation:** The square root of 4 is 2, so we return 2.
### Example 2

    **Input:** `x = 8`  
    **Output:** `2`  
    **Explanation:** The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

### Constraints

- <code>0 &lt;= x &lt;= 2<sup>31</sup> - 1</code>

# My solution

My approach is to think of the sequence of non-negative squares as a sorted array where the element at index `i` is `i * i` (i²).  

We never actually build this array in memory, but we can pretend it exists and run a binary search over the indices `i` from `0` to `x`. For a given `mid`, we compute `mid * mid` and compare it to `x`:

- If `mid * mid == x`, then `mid` is the exact square root, so we return it.
- If `mid * mid < x`, the real square root must be larger, so we move the lower bound up.
- If `mid * mid > x`, the real square root must be smaller, so we move the upper bound down.

When the binary search loop stops, we have `low > high`.  
What does that mean in terms of the numbers we tested?

- Every value **below or equal to `high`** is too small or just right, i.e., its square is `<= x`.
- Every value **greater or equal to `low`** is too big, i.e., its square is `> x`.

During the search, `low` only moves **up** when `mid * mid < x` (we need a larger number),  
and `high` only moves **down** when `mid * mid > x` (we need a smaller number).

Because the numbers are increasing and `low` passes just beyond the true square root,  
`high` ends up being the last integer whose square is still `<= x`.  

That is exactly the definition of `⌊√x⌋`, so returning `high` gives us the square root of `x` rounded down.


