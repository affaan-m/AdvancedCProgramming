#include <stdio.h>

extern int count;

extern void display(void) {
     printf("%d\n",count+1);
}
