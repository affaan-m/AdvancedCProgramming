/*

// Using a single pointer as an argument to a function, does not work

#include <stdio.h>
#include <malloc.h>

void allocateMemory( int * ptr) {
   ptr = (int *) malloc(sizeof(int)); // allocate some memory
}

int main(){
   int *ptr = NULL;

   allocateMemory(ptr);
   *ptr = 20;
   printf("%d\n", *ptr);

   // free up the memory
   free(ptr);
   return 0;
}

*/


#include <stdio.h>
#include <stdlib.h>

void allocateMemory( int ** ptr) {
   *ptr = (int *) malloc(sizeof(int)); // allocate some memory
}

int main(){
   int *ptr = NULL;

   allocateMemory(&ptr);
   *ptr = 20;

   printf("%d\n", *ptr);

   // free up the memory
   free(ptr);
   return 0;
}
   
