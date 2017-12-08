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

    int i = 0;
    //sets pid_t to 0 and gives it a nicer name
    pid_t = childpid = 0;
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
    FILE *fp = fopen(stdin, "r");
    char stream[MAX_BUF];
    if(fp == NULL)
    {
        printf("Could not read input file");
        return;
    }
    while(!feof(fp))
    {
        if(pr_count == pr_limit){
            wait();
        }
        fgets(stream, MAX_BUF, fp);

    }




}