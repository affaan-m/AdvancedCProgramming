#include <stdio.h>
#include <stdlib.h> // malloc
#include <math.h> // sqrt
#include <complex.h> // complex

int main(void) {
    double complex z1 = I * I; // Imaginary unit squared
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

    double complex z2 = pow(I, 2); // Imaginary unit squared
    printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));

    double PI = acos(-1);
    double complex z3 = exp(I * PI); // Euler's formula
    printf("exp(I * PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));

    double complex z4 = 1+2*I, z5 = 1-2*I; // conjugate
    printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4*z5), cimag(z4*z5));

    return 0;

}

