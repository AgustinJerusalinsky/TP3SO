#include <stdio.h>
#include <unistd.h>

 FILE * result;

int returnError(){
    pclose(result);
    fflush(stdout);
    fflush(stderr);
    return 0;
}

int quineValidator(){
    char buffer[4096];
    int len;
    result = popen("gcc quine.c -o quine","r");
    if(result == -1) return returnError();

    if(access("quine",F_OK) !=0 ) return returnError();    
    printf("\nGenial! ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

    result = popen("./quine | diff quine.c -","r");
    if(result == -1) return returnError();

    len = fread(buffer, sizeof(char), 1024, result); 
    if(len !=0) printf("\ndiff encontró diferencias\n"); 
    pclose(result);
    fflush(stdout);
    fflush(stderr);
    return len==0;

}