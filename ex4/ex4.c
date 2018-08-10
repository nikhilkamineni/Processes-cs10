// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int child_p = fork();

    if (child_p < 0) {
        printf("Fork failed!");
        exit(1);
    }
    else if (child_p == 0) {
        char* args[3];
        args[0] = "/bin/ls";
        args[1] = "-la";
        args[2] = NULL;
        execvp(args[0], args);
    }
    else {
        wait(&child_p);
        printf("Parent process here!\n");
    }

    return 0;
}
