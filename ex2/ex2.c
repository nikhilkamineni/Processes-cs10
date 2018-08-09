// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   FILE *file = fopen("text.txt", "a+");

   int child_p = fork();

   if (child_p < 0) {
       printf("Fork failed!");
       exit(1);
   }
   else if (child_p == 0) {
        // code for child process here
        printf("This is the CHILD process (PID: %d)\n", (int) getpid());
        char *child_msg = "CHILD is writing to the file\n";
        fwrite(child_msg, strlen(child_msg), 1, file);
   }
   else {
       // code for parent process here
        printf("This is the PARENT process (PID: %d)\n", (int) getpid());
        char *parent_msg = "PARENT is writing to the file\n";
        fwrite(parent_msg, strlen(parent_msg), 1, file);
   }
    
    fclose(file);
    return 0;
}
