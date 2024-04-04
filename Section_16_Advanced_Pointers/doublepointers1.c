#include <stdio.h>

int main()
{
     int num=123;

     //A normal pointer singlePointer
     int *singlePointer = NULL;

     //This pointer doublePointer is a double pointer
     int **doublePointer = NULL;

     //Assigning the address of variable num to the single pointer
     singlePointer = &num;

     //Assigning the address of pointer singlePointer to the doublePointer
     doublePointer = &singlePointer;


/* Possible ways to find value of variable num*/
     printf("\n Value of num is: %d", num);
     printf("\n Value of num using singlePointer is: %d", *singlePointer);
     printf("\n Value of num using doublePointer is: %d", **doublePointer);

     /*Possible ways to find address of num*/
     printf("\n Address of num is: %p", &num);
     printf("\n Address of num using singlePointer is: %p", singlePointer);
     printf("\n Address of num using doublePointer is: %p", *doublePointer);

     /*Find value of pointer*/
     printf("\n Value of Pointer singlePointer is: %p", singlePointer);
     printf("\n Value of Pointer singlePointer using doublePointer is: %p", *doublePointer);

     /*Ways to find address of pointer*/
     printf("\n Address of Pointer singlePointer is:%p",&singlePointer);
     printf("\n Address of Pointer singlePointer using doublePointer is:%p",doublePointer);

     /*Double pointer value and address*/
     printf("\n Value of Pointer doublePointer is:%p",doublePointer);
     printf("\n Address of Pointer doublePointer is:%p",&doublePointer);

     return 0;
}
