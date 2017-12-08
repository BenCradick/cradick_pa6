/*
// Ben Cradick
// cs2750 PA6
//
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    typedef enum {false, true} bool;
    int i = 0;
    //sets pid_t to 0 and gives it a nicer name
    pid_t pid;
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

    int pr_limit = atoi(argv[1]);
    int pr_count = 0;
    int max_buf = 60;

    char stream[max_buf];
    int status;


    while(fgets(stream, max_buf, stdin) != NULL)
    {
        char streamPart[2][max_buf];
        int count = 0;
        bool first = true;
        for(int i = 0; i < sizeof(stream); i++){
            if(first && isdigit(stream[i])){
                first = false;
                count = 0;
                while(isdigit(stream[i])){
                    streamPart[1][count] = stream[i];
                    printf("%c", streamPart[1][count] );
                    count++;
                    i++;
                }
                printf("\n");
                count = 0;
            }
            else if(!first && isdigit(stream[i])){
                while(isdigit(stream[i])){
                    streamPart[2][count] = stream[i];
                    printf("%c\n", streamPart[2][count]);
                    count++;
                    i++;
                }
                printf("\n");
            }
            else{
                streamPart[0][count] = stream[i];
                count++;
            }
        }
        if(pr_count == pr_limit){
            wait(&status);
            pr_count--;
        }

        pid = fork();
        pr_count++;
        if(pid < 0){
            printf("fork() returned -1 unable to create fork");
            break;
        }
        else if(pid > 0){
            break;
        }
        execl(streamPart[0],streamPart[1], streamPart[2],(char *)NULL);
    }


    fprintf(stderr, "pr_count:%d process ID:%d parent ID:%d child ID:%d\n", pr_count, getpid(), getppid(), pid);

}