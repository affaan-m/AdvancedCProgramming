#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int array1[] = {10,20,30,40,50,60,70,80,90,100};
int array2[] = { 38, 27, 87, 63, 59, 223, 132, 1, 19, 7 };


int add(int a, int b) {	return a + b;	}
int sub(int a, int b) {	return a - b;	}
int mult(int a, int b){	return a * b;	}
int div(int a, int b) {	return a / b;	}

/// Array of pointers to functions
int (*fpArr[])(int,int) = { &add,&sub,&mult,&div };

// performs the given operation on elements of the arrays
int* performOp(int *a, int *b, int size, int (*f)(int,int));

// displays the elements of an array
void display(int *x, int size);

// main method
int main( ){
  
  int choice = 0;

  // size of the array                      
  unsigned int size = 0;		
  
  int *result = NULL;

  // set size to minimum size of the two arrays
  size = sizeof(array1);			
  
  if (sizeof(array2) < size)
	size = sizeof(array2);

  size = size / sizeof(int);

  while(choice != 5)
  {
	printf("\n\nWhich operation do you want to perform? \n");
	printf("1.Add \n");
	printf("2.Subtract \n");
	printf("3.Multiply \n");
	printf("4.Divide \n");
	printf("5.None ... \n");
	printf("Enter choice: ");
	scanf("%d", &choice);

	if(choice == 5) break;
	if(choice < 1 || choice > 5) continue;

	int j = choice - 1;

	result = performOp(array1,array2,size,fpArr[j]);		

	printf("\n\nThe Results are ...\n");
	display(result,size);
	
	if(result!=NULL)  
	   free(result);

  }
  
  return 0;
}



// performs the given operation on all elements of the arrays A and B 
int* performOp(int *a, int *b, int size, int (*f)(int,int))
{
    int *c = malloc(sizeof(int) * size);

    for(int i=0; i < size; i++ ) {
	 c[i] = (*f)(a[i],b[i]);
    }

    return c;
}


// function for displaying the results stored in array x
void display(int *x, int size)
{

  if(x == NULL)  return;

  for(int i=0; i < size; i++ ) {
    printf("%d   ", x[i]);
  }

  printf("\n");
}