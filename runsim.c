/*
// Ben Cradick
// cs2750 PA6
//
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]){

    int i = 0;
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

    return 0;
}