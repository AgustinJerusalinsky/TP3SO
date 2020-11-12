#include<stdio.h>
#include <stdlib.h>
#include <strings.h>


int main2(){
    size_t size = 1024;
    int n;
    char * input = malloc(size);
    char output[1024*4];
    int offset = 0;
    while(1){
        n=getline(&input,&size,stdin);  
        input[n-1]=0;
        n--;
        offset = sprintf(output,"char buffer[%d]; \n",n);
        for(int i=0;i<n;i++){
            offset += sprintf(output+offset,"buffer[%d]='%c';\n",i,input[i]);
        }
        printf("%s\n",output);
    } 
}


int main(){
    size_t size = 1024;
    int n;
    char * input = malloc(size);
    char * head = "char buffer[]={";
    char output[1024*4];
    int offset = 0;
    while(1){
        n=getline(&input,&size,stdin);  
        input[n-1]=0;
        n--;
        offset = sprintf(output,"%s",head);
        for(int i=0;i<n;i++){
            offset += sprintf(output+offset,"'%c',",input[i]);
        }
        offset += sprintf(output+offset,"};");
        printf("%s\n",output);
    } 
    free(input);
}