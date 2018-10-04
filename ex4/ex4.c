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
    int rc = fork();
    
    
    if (rc == 0) {    // child process satisfies this branch
       char * ls_args[] = { "/bin/ls" , "-l", NULL}; 
        printf("hello\n");
    
    execvp(   ls_args[0],     ls_args);
    }
    else {
        wait(NULL);
        
        printf("goodbye \n");

    }   

    return 0;
}
