#include <stdio.h>
#include <stdlib.h> // malloc

// Flexible Array Member (FAM) is a feature in C99 that allows a struct to have an array of unspecified size at the end of the struct.

struct flexArray { 
    int len;
    int arr[]; // Flexible Array Member (FAM)
    };
int main(void) {
    struct flexArray *fam = NULL; // Pointer to struct flexArray
    int flexSize = 0;

    printf("Enter the size of the array:\n");

    scanf("%d", &flexSize);

    size_t size = sizeof(struct flexArray);
    
    fam = malloc(size + (flexSize * sizeof(int))); // Allocate memory for the struct and the array

    fam->len = flexSize;
    fam->arr[0] = 52;
    fam->arr[1] = 21;

    printf("array is: %d:%d\n", fam->arr[0], fam->arr[1]);

    return 0;
}

