// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <string.h> 
#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0; 
    struct sockaddr_in serv_addr; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    // //send(sock , hello , strlen(hello) , 0 ); 
    // printf("Hello message sent\n");
    // sleep(2);
    // send(sock , entendido , strlen(entendido) , 0 ); 
    // valread = read( sock , buffer, 1024); 
    // printf("%s\n",buffer );
    size_t size = 1024;
    int n;
    char * input = malloc(size);






    // char * answers[]= {"entendido\n","itba\n","M4GFKZ289aku\n","fk3wfLCm3QvS\n","too_easy\n",".RUN_ME\n","K5n2UFfpFMUN\n","BUmyYq5XxXGt\n","u^v\n","chin_chu_lan_cha\n","gdb_rules\n","normal\n",0};
    // char ** ans = answers;
    // int top = 0;
    // while(*ans!=0 && top < 1){
    //     send(sock , *ans , strlen(*ans) , 0 );
    //     ans++;
    //     top++;
    // } 
    while(1){
        n=getline(&input,&size,stdin);  
        send(sock , input , n , 0 ); 
    } 
    return 0; 
} 
