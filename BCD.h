#pragma once
#include <stdlib.h>
#include <stdio.h>



typedef int BOOL; //Boolean type, can be TRUE or FALSE
#define TRUE 1
#define FALSE 0

static inline void *balloc(size_t size) { //Malloc with error checking, if malloc fails it will print an error message and exit the program
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "balloc: out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

static inline void *bcalloc(size_t count, size_t size) { //Calloc with error checking, if calloc fails it will print an error message and exit the program
    void *ptr = calloc(count, size);
    if (!ptr) {
        fprintf(stderr, "bcalloc: out of memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

static inline void *brealloc(void *ptr, size_t size) { //realloc with error checking, if realloc fails it will print an error message and exit the program, if size is 0 it will free the memory and return NULL, if ptr is NULL it will behave like malloc is it too obvuis im copy pasting things? ok...
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = realloc(ptr, size);

    if (!new_ptr) {
        fprintf(stderr, "brealloc: out of memory\n");
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}

static inline void bfree(void *ptr) { //unnecessary wrapper for free, but it is here for consistency with the other memory allocation functions
    free(ptr);
}


static inline void printfd(int value, BOOL newline) { //prints intiger. print_int(int value, BOOL newline) takes an int and a BOOL, if newline is TRUE it will print a newline after the int, if newline is FALSE it will not print a newline after the int
    printf("%d", value);
    if (newline) {
        printf("\n");
    }
}




static inline void swap_int(int *a, int *b) { //swaps two intigers, swap_int(int *a, int *b) takes two int pointers and swaps the values they point to
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0])) //Macro to get the length of an array, ARRAY_LEN(arr) takes an array and returns the number of elements in the array, it does this by dividing the size of the entire array by the size of a single element, this only works for statically allocated arrays and not for dynamically allocated arrays
#define MIN(a, b) ((a) < (b) ? (a) : (b)) //Clamps 2 numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))//sets a number to a minimum or maximum value, MAX(a, b) takes two values and returns the greater of the two, this is useful for clamping a value to a minimum or maximum value
#define CLAMP(x, lo, hi) (MIN(MAX((x), (lo)), (hi))) //Clamps a number to a minimum and maximum value, CLAMP(x, lo, hi) takes a value and a minimum and maximum value and returns the value clamped to the minimum and maximum value, this is useful for clamping a value to a minimum and maximum value
#define balloc_array(type, count) ((type *)balloc((count) * sizeof(type))) //Macro to allocate an array of a certain type and count, balloc_array(type, count) takes a type and a count and returns a pointer to an array of the specified type and count, this is just a convenience macro to avoid having to cast the result of balloc every time you want to allocate an array



