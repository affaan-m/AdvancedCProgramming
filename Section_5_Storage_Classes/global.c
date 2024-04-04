// a global double variable, only accessible inside this file
static double y = 15;

// a global float variable that is accessible with the entire program
float z = 15;

int main() {

    // an int variable with block scope and temporary storage
    auto int x = 10;

    // a float local variable with permanent storage
    static float a = 10;

    // a register int variable
    register int b = 10;
    return 1;
}

// a function that is only accessible with this file
static void myFunction(void) {}
