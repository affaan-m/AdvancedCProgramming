#include <stdio.h>

int sum (int num) {
    static int z = 0;
    z += num;
    return z;
}

int main() {
    printf("%d ",sum(25));
    printf("%d ",sum(15));
    printf("%d ",sum(30));
    return 0;
}
