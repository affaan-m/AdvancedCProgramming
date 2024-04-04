#include <stdio.h>

// Variable Length Array (VLA) is an array whose size is determined at runtime.

int main(void) {
    int i, sum=0, size=0;

    printf("Enter the size of the array:\n");

    scanf("%d", &size);

    int arr[size];

    printf("Enter %d element in the array:\n ", size); 

    for (i=0; i<size; i++)
        scanf("%d", &arr[i]);
    
    for (i=0; i<size; i++) {

        sum += arr[i];

    }

    printf("The sum of all elements in the array is: %d\n", sum);
}