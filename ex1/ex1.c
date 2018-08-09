// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int child_p = fork();
    int x = 100;

    if (child_p < 0) {
        printf("Fork failed\n");
        exit(1);
    }
    else if (child_p == 0) {
        printf("This is CHILD process (PID: %d)\n", (int) getpid());
        printf("Variable x in CHILD process is %d\n", x);
        x--;
        printf("Decremented var x in CHILD process. It's now %d\n", x);
    } else {
        printf("This is the PARENT process (PID: %d)\n", (int) getpid());
        printf("Variable x in PARENT process is %d\n", x);
        x--;
        printf("Decremented var x in PARENT process. It's now %d\n", x);
    }

    return 0;
}
