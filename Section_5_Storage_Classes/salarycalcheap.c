
#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo(double *input) {
    double *twice = malloc(sizeof(double));
    *twice = *input * 2.0;
    return twice;
}

int main3 (int argc, char *argv[]) { 
    int *age = malloc(sizeof(int));
    *age = 20;
    double *salary = malloc(sizeof(double));
    *salary = 92533.63;
    double *myList = malloc(3 * sizeof(double));
    myList[0] = 1.2;
    myList[1] = 2.3;
    myList[2] = 3.4;
    double *twiceSalary = multiplyByTwo(salary);

    printf("double your salary is %.3f\n", *twiceSalary);

    free(age);
    free(salary);
    free(myList);
    free(twiceSalary);
}
