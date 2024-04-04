#include <stdio.h>

int main() {
    int num, position, newNum, bitStatus;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to set */
    printf("Enter nth bit to check and set (0-31): ");
    scanf("%d", &position);

    /* Right shift num, position times and perform bitwise AND with 1 */
    bitStatus = (num >> position) & 1;
    printf("The %d bit is set to %d\n", position, bitStatus);

    /* Left shift 1, n times and perform bitwise OR with num */
    newNum = (1 << position) | num;
    printf("\nBit set successfully.\n\n");

    printf("Number before setting %d bit: %d (in decimal)\n", position, num);
    printf("Number after setting %d bit: %d (in decimal)\n", position, newNum);

    return 0;
}