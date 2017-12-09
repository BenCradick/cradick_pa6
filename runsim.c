/*
// Ben Cradick
// cs2750 PA6
 //December 7th 2017
//
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
void checkExitStatus(int status);

int main(int argc, char* argv[]){


    int childpid, i = 0;
    //sets pid_t to 0 and gives it a nicer name
    pid_t pid = 0;
    //checks appropriate number of arguments are made.
    if(argc != 2)
    {
        printf("Please include a single numerical argument\n");
        return 0;
    }

    //checks to see if argument is a positive integer
    while(argv[1][i] != '\0'){
        if(!isdigit(argv[1][i])){
            printf("Please enter an integer argument to the command line.\n");
            return 0;
        }
        i++;
    }
    //sets bounds for bytes limits
    int pr_limit = atoi(argv[1]);
    int pr_count = 0;
    int max_buf = 256;

    char stream[max_buf];
    char executable[max_buf];
    int status;

    //main loop
    while(fgets(stream, max_buf, stdin) != NULL)
    {



        childpid = fork();
        if(childpid != 0){
            pr_count++;
        }
        else{
            strcpy("./", executable);
            strcat(executable,strtok(stream, " "));

            char* arg1 = strtok(NULL, " ");
            char* arg2 = strtok(NULL, " ");

            execl(executable, executable, arg1, arg2,(char *)NULL);
            checkExitStatus(status);
        }
        if(pr_count >= pr_limit && childpid != 0)
        {
            pid = waitpid(-1, &status, WNOHANG);
            pr_count--;
            if(pid == -1){
                exit(EXIT_FAILURE);
            }

            checkExitStatus(status);
        }


    }
    pid = waitpid(-1, &status, WUNTRACED | WCONTINUED);
    checkExitStatus(status);

    exit(0);
    return 0;
}

void checkExitStatus(status){
    if (WIFEXITED(status)) {
        printf("Exit Status %d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status)) {
        printf("Exit Status %d\n", WTERMSIG(status));
    }
    else if (WIFSTOPPED(status)) {
        printf("Exit Status %d\n", WSTOPSIG(status));
    }
    else{
        return;
    }
}