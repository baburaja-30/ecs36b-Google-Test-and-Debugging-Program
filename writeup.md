# Google Test And Debugging Writeup

## Things I Thought To Test
1. For the get_sorted() function
* Sorted array should have different memory address from the original
* Each term in the sorted array should be smaller than the next term
* If original array is already sorted return the copied array without modification
* If array in reverse order, it should reverse the copied array and return it
* Should put duplicate values next to each other in the copied array
* Original array should remain the same after calling get_sorted()

2. For the make_sorted() function
* Each term in the sorted array should be smaller than the next term
* If array is already sorted return that array
* If array in reverse order, it should make it sorted in place
* Should put duplicate values next to each other in the array

3. For the copy_array() function
* Copied array should have different memory address than the original array
* Values of the copied array should be same as the original
* Copied array stays the same even after the original is modified

4. For the min_index_array() function
* If val is the smallest at the end of the array, should return last index
* If val is smallest at the start of the array, should return the first index
* If val is smallest somewhere in between it should return that index
* If there are multiple min values it should return the index of the first occurance
* After finding the min value, the array should not change

5. For the swap() function
* Values of a and b be should be swapped
* If value is swapped with itself should return the original value

6. For the parse_args() function
* Should convert cmd line arguments from strings to int
* Should allocate space for the array
* Should store ints into an array
* If no cmd line arguments then ar_out should be NULL

...

## Bugs

### Bug 1

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix 

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 2

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 3

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```