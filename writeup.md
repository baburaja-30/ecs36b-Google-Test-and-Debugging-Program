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

Line 33 in `sorting.cpp`

```c
int* copy = ar;
return copy;
```

### How the bug was located

The compiler gave an error stating `unused parameter 'len'` which indicated that `len` was never being used

### Description

The function was not actually making a copy of the array. Instead it was just making `copy` point to the same memory location as `ar`. Additionally, no new memory was being allocated.

### Fix

Allocated new memory using `malloc` and copied each element from the original array into the new one using a loop.

```c
int* copy = (int*)malloc(sizeof(int) * len);
for (int i = 0; i < len; i++) {
    copy[i] = ar[i];
}
return copy;
```

### Bug 2

### Location

Line 28 in `formatting.cpp`

```c
void parse_args(int argc, char** argv, int* ar_out, int* len_out)
ar_out = (int*)malloc(*len_out);
sscanf(argv[i], "%d", ar_out[i]);
```

### How the bug was located

The compiler gave an error on line 36 stating `format specifies type 'int *' but the argument has type 'int'` which pointed to the `sscanf` call. 

### Description

There were four bugs in `parse_args`:
1. `ar_out` was `int*` instead of `int**`. This meant that the function couldn't actually modify the pointer
2. `malloc` was not allocating enough space
3. `sscanf` was passing `ar_out[i]` (a value) instead of an address
4. The loop started at `argv[0]` which is the program name, not the first argument

### Fix

Changed `ar_out` to `int**`, fixed malloc to use `sizeof(int)`, fixed sscanf to use `&(*ar_out)[i-1]`, fixed loop to start at `i=1`, and added NULL handling for no arguments.

```c
*len_out = argc - 1;
if (argc > 1) {
  *ar_out = (int*)malloc(sizeof(int) * *len_out);
  for(int i = 1; i <= *len_out; ++i){
    sscanf(argv[i], "%d", &(*ar_out)[i-1]);
  }
} else {
  *ar_out = nullptr;
}
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