# Binary Search

Binary search is an extremely useful algorithm for finding a value (or its index) in a sorted array, with time complexity `O(log N)`.

## How does it work?

### Initial definitions

* `v` — a sorted array of values
* `n` — the size of `v`

```c
// A sorted array of 4 integers
int n = 4;
int v[n] = {1, 3, 5, 6};

// A sorted array of 7 characters
int n = 7;
char v[n] = {'2', 'B', 'F', 'P', 'a', 'h', 'z'};
```

### Choosing the search boundaries

We start by defining two indexes that delimit the search range:

* `low` — always points to a position that is **too small** to contain the target.
* `high` — always points to a position that is **too large** to contain the target.

At the beginning of the algorithm, we assume the `target` might be anywhere in the array, so we initialize:

* `low = 0`
  (if the target exists, the first element must be *at least* a candidate or smaller than it)
* `high = n - 1`
  (similarly, the last element is the upper bound of our search space)

### The midpoint

We then compute:

* `mid` — the index halfway between `low` and `high`.

For arrays with an even number of elements, the midpoint depends on whether we round up or down. This detail matters in some problems because it changes which half of the array we discard first.

### The iterative process

Binary search works by **repeatedly shrinking** the interval from `low` to `high`.
At each step, we:

1. Compute the middle index `mid`.
2. Look at the value `v[mid]`.
3. Decide whether we should keep the **left half** or the **right half** of the current interval.

A useful way to think about it is:

> At every moment, the **current search interval** is `[low, high]`.
> The target, if it exists, must be inside this interval.

So each comparison must **shrink** this interval, never expand it.

---

### Step 1 — compute `mid`

The classic formula is:

```c
mid = (low + high) / 2;
```

In practice, to avoid overflow in some languages, people often use:

```c
mid = low + (high - low) / 2;
```

In both cases, `mid` is the index roughly in the middle of `low` and `high`.
For example:

* If `low = 0` and `high = 7`, then `mid = 3`.
* If `low = 2` and `high = 5`, then `mid = 3`.

ASCII sketch:

```text
Indexes:  0   1   2   3   4   5   6   7
          ^                       ^
         low                     high
                  ^ 
                  mid
```

---

### Step 2 — compare `v[mid]` with `target`

We have three cases:

1. `v[mid] == target`
2. `v[mid] > target`
3. `v[mid] < target`

Let’s see what happens in each case and how that affects `low` and `high`.

---

### Case 1: `v[mid] == target`

This is the easy case: we found what we were looking for.

```c
if (v[mid] == target) {
    return mid;
}
```

In the case our target is `7`:

```text
v = [  1   3   5   7   9   11  ]
       0   1   2   3   4    5   (indexes)
       ^           ^        ^
       |           |        |
       low         mid      high

v[mid] == target ✔  → we can return mid
```

---

### Case 2: `v[mid] > target` → shrink to the left

If `v[mid]` is **bigger** than `target`, then everything **to the right of `mid`** is also bigger (because the array is sorted).
So the target, if it exists, must be **on the left side**.

We do:

```c
if (v[mid] > target) {
    high = mid - 1;
}
```

Suppose `target = 4`:

```text
v = [  1   3   5   7   9   11  ]
       0   1   2   3   4    5
       ^           ^        ^
       |           |        |
       low         mid      high

Since v[mid] = 7 > 4, the target cannot be at mid or to the right of mid.

New high = mid - 1

v = [  1   3   5   7   9   11  ]
       0   1   2   3   4    5
       ^       ^        
       |       |        
       low     high

Active search interval is now [0, 2].
```

---

### Case 3: `v[mid] < target` → shrink to the right

If `v[mid]` is **smaller** than `target`, then everything **to the left of `mid`** is also smaller.
So the target, if it exists, must be **on the right side**.

We do:

```c
if (v[mid] < target) {
    low = mid + 1;
}
```

Suppose `target = 9`:
```text
v = [  1   3   5   7   9   11  ]
       0   1   2   3   4    5
       ^       ^            ^
       |       |            |
       low     mid          high

Since v[mid] = 5 < 9, the target cannot be at mid or to the left of mid.

New low = mid + 1

v = [  1   3   5   7   9   11  ]
       0   1   2   3   4    5
                   ^        ^        
                   |        |        
                   low      high

Active search interval is now [3, 5].
```

---

### Visual walk-through of a full search

Let’s put everything together.
Array:

```text
v = [  1   3   5   7   9   11  ]
       0   1   2   3   4    5  (indexes)
target = 9
```

#### Iteration 1

```text
low = 0, high = 5
mid = (0 + 5) / 2 = 2

Indexes:  0   1   2   3   4   5
v:       [1] [3] [5] [7] [9] [11]
          ^       ^           ^
         low     mid         high

v[mid] = 5 < 9  → move low to mid + 1
low = 3, high = 5
```

#### Iteration 2

```text
low = 3, high = 5
mid = (3 + 5) / 2 = 4

Indexes:  3   4   5
v:       [7] [9] [11]
          ^   ^    ^
         low mid  high

v[mid] = 9 == 9 → found it! return 4
```

Note how at each step:

* The **search interval shrinks** (`[0,5]` → `[3,5]` → found).
* We never look again at parts of the array that were already discarded.

---

### Why does the loop stop?

The usual loop condition is:

```c
while (low <= high) {
    ...
}
```

The loop stops when `low > high`.
This means the search interval is **empty**: there are no indexes left where the target could be.

* If we found the target earlier, we already returned.
* If we exit the loop without returning, we know the target is **not** in the array.
