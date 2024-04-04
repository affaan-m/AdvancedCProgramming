#include <stdio.h>

/*

 int main() {

    auto int x; // local variable

    int m; // m in scope of main

    scanf("%d", &m);
    {
        int i; //both m and i in scope

        int n = 5; // n in scope

        for (i = m; i < n; i++) {
            printf("%d\n", i);
        
        }
    }

    return 0;
}

int func_name() {

    auto int y; // local variable

    return y;
}

 char *myFunction() {

    char x[] = "apple";

    return x;
 }




int i = 5; // global variable

char text[255][25]; // global variable

void foo(void);

int main(void) {

    printf("%i ", i);
    foo();
    printf("%i\n", i);

    return 0;
}

int count = 5;

extern void write_extern();

int main() 
{
    count = 5;
    write_extern();
    return 1;
}

*/

/* int fun() { 
    static int count = 0;
    int localvar = 0;

    printf("automatic=%d, static=%d\n", localvar, count);

    count++;
    localvar++;
    return count;
}

int main() 
{
for (int i = 0; i < 5; i++)
{
    fun();
}
    return 1;
}

*/

int main() {

    register int x; // register variable (counter)

    for (x = 0; x < 5; x++) {
        printf("%d\n", x);
    }
    return 1; 
}