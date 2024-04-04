
#include <stdio.h>

double multiplyByTwos(double input) { 
    double twice = input * 2.0;
    return twice;
}

int main4(int argc, char *argv[]) {
    int age = 20;
    double salary = 92533.63;
    double myList[3] = {1.2, 2.3, 3.4};

    printf("double your salary is %.3f\n", multiplyByTwos(salary));

    return 0;
}