#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Types */
typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define Word char
#define Byte unsigned char

/* RNG */
void rng_init(void);
int random_int(int min, int max);

/* Memory */
void *balloc(size_t size);
void *bcalloc(size_t count, size_t size);
void *brealloc(void *ptr, size_t size);
void bfree(void *ptr);

/* I/O */
char *ReadStringFromUser(size_t cap);
void swap_int(int *a, int *b);

/* Helpers */
int sizeofbyte(int howmanybytes);

/* Macros */
#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(x, lo, hi) (MIN(MAX((x), (lo)), (hi)))
#define balloc_array(type, count) ((type *)balloc((count) * sizeof(type)))