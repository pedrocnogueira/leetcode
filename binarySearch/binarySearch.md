# Binary Search

This is an extremily useful algorithm to find a value (or it's index) in a sorted array in `O(log N)` complexity.

## How it works?

Initial definitions:
- `v` - is a sorted array of values
- `n` - is size of `v`

``` C
// A sorted array of 4 integers
int n = 4;
int v[n] = {1, 3, 5, 6};

// A sorted array of 7 characters
int n = 7;
char v[n] = {'2', 'B', 'F', 'P', 'a', 'h', 'z'}
```

We start by defining 2 indexes:
- `low` - it's value is always smaller than the `target`
- `high` - it's value is always bigger than the `target`

In the begining of the algorithm, we assume that the `target` exists somewhere in the array, so:
- `low = 0` (because, if it exists in the array, then the first entry of the array should be smaller than the `target`) 
- `high = n - 1` (because, if it exists in the array, then the last entry of the array should be bigger than the `target`)

Then, our last index is:
- `mid` - it's the index in the middle of `high` and `low`

This `mid` can be a problem when we have an array with an even number of entries, so we have to bear in mind if our mid will choose the value of `high + low / 2` rounded up or down, because in some of the problems we'll see in this playlist, this convention can change the solution.

Finally, we go into the actual algorithm: a loop that, at each iteration, finds where the mid is and checks whether the value in its position is `== (equal to)`, `> (bigger than)` or `< (smaller than)` our `target`.

Based on the result of this check, we should act accordingly:
- If `v[mid] == target`, then we found what we were looking for!
- If `v[mid] == 