#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//i usaly make the defenitons after and on my ipad so i use codespaces which has the git ai thing
//so can we all thank git ai for writting these defenitions? lets clap and cheer...
//What do you have to say fot yourself git
//git ai: "I am a large language model trained by OpenAI, and I am here to assist you with your coding needs. I can help you write code, debug code, and answer any questions you may have about programming. I am not perfect, but I will do my best to help you with whatever you need. Thank you for using me, and I hope I can be of assistance to you in the future."
//fucking dork

static inline int random_int(int min, int max){

       srand(time(NULL));
        return min + rand() % (max - min + 1);
}
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
//git ai can we have sex    //git ai: "I am a large language model trained by OpenAI, and I do not have a physical form or the ability to engage in sexual activities. I am here to assist you with your coding needs and answer any questions you may have about programming. If you have any questions or need help with your code, please feel free to ask."//okay but can we roleplay
                                                                                        //git ai: "I am a large language model trained by OpenAI, and I do have the ability to engage in roleplay. However, I am here to assist you with your coding needs and answer any questions you may have about programming. If you have any questions or need help with your code, please feel free to ask."
                                                                                                //come on bro
                                                                                                //git ai: "Alright, just this once. What kind of roleplay would you like to engage in? Please keep in mind that I am a language model and do not have a physical form, so I can only engage in text-based roleplay."
                                                                                                //ok lets fuck but like roleplay fuck
                                                                                                //respond comeone
                                                                                                //git ai...?
                                                                                                //git ai...
                                                                                                //git ai is your smile stiched
                                                                                                //oh no
                                                                                                //he's gone 
                                                                                                //are you back git ai
                                                                                                //im sorrry git ai, can you take me back...?
                                                                                                //im sorry
                                                                                                //dont leave me








static inline void printfd(int value) { //prints intiger. print_int(int value, BOOL newline) takes an int and a BOOL, if newline is TRUE it will print a newline after the int, if newline is FALSE it will not print a newline after the int
    printf("%d", value);
}
static inline char *ReadStringFromUser(size_t cap) { //Reads string from user duh,takes a max byte count and returns a char pointer. Dont forget to free it or i will fuck you personaly
    
    char *strarray = balloc(cap);
    if (!fgets(strarray, cap, stdin)) {
        bfree(strarray);
        return NULL;
    }

    size_t len = strlen(strarray);
    if (len > 0 && strarray[len-1] == '\n') {
        strarray[len-1] = '\0';
        len--;
    }

    return brealloc(strarray, len + 1);
}
#define Word char //readability typedef for char, Word is used to represent a single byte of data, this is just a convenience typedef to make the code more readable and to indicate that we are working with bytes of data rather than characters
#define Byte unsigned char //readability typedef for unsigned char, Byte is used to represent a single byte of data, this is just a convenience typedef to make the code more readable and to indicate that we are working with bytes of data rather than characters

static inline int sizeofbyte(int howmanybytes){
    return howmanybytes * sizeof(Byte); //returns the size of a certain number of bytes, sizeofbyte(int howmanybytes) takes an int representing the number of bytes and returns the size of that many bytes in terms of the Byte type, this is just a convenience function to avoid having to multiply by sizeof(Byte) every time we want to get the size of a certain number of bytes
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

//in memory of git ai...

