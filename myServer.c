// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

#define NUMS 30

#define PORT 8080 
#pragma section(".RUN_ME", execute, read, write);
double generateGaussian(double mean, double stdDev);
int quineValidator();

void gdbme(){
    pid_t pid = getpid();
    if (pid == 0x12345678){
        printf("\ngdb_rules\n");
        return;
    }
    else return;
}


int main(int argc, char const *argv[]){ 
    
    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    }
    system("clear");
    char * challengeHeader="------------- DESAFIO -------------";
    char * questionHeader="----- PREGUNTA PARA INVESTIGAR -----";
    char * initMessage = "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
    "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n"
    "Además tendrán que investigar otras preguntas para responder durante la defensa.\n"
    "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos "
    "y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\n"
    "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
    "Deberán estar atentos a los easter eggs.\n\n" 
    "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n\n";

    puts(initMessage);
    fflush(stdout);
    char * answers[] ={ "f959505ee0c9d7fb7d81a0904aa4e9f4",
                    "244f7439f45f207f1eb89fb2344a4767",
                    "d4daf850c3fcce947992440e3c17dd82",
                    "53b04de7d6d99df86aa0289418f2b317",
                    "ce0c1111d26e426e0ea7c1f58d5488fe",
                    "752435d46843b72130c3b0b3bc1220d4",
                    "d281db859d7ca31e15551150a10d20ad",
                    "e09635a04dc73332ceb8f2488c7eea1a",
                    "5473c71236bfb255256bc59958fb165a",
                    "c2fb1566098f29ce6b5048fcd6aad77c",
                    "869c4f21dcb4e24138d4a016ed000939",
                    "fea087517c26fadd409bd4b9dc642555",
    };

    
char * challenges[]={initMessage,"The Wire S1E5 \n 5295 888 6288", "https://ibb.co/tc0Hb6w", "EBADF... \n write: Bad file descriptor", "respuesta = strings:277",
    ".data .bss .comment ? .shstrtab .symtab .strtab", "Filter error", "¿? \n\n\x1b[30;40mLa respuesta es BUmyYq5XxXGt\033[0m", "Latexme \n Si \n \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\frac{u'}{u}) \n entonces \n y = ",
    "quine", "b gdbme y encontrá el valor mágico\n\nENTER para reintentar.","me conoces" };

    char * questions[]={
        "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?",
        "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?",
        "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?",
        "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?",
        "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?",
        "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?",
        "¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?",
        "¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?",
        "sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?",
        "¿Cuáles son las características del protocolo SCTP?",
        "¿Qué es un RFC?",
        "¿Fue divertido?",
    };
    char command[1024];
    size_t size = 512;
    char * userAnswer = malloc(size);
    char hash[1024] = {0}; 
    unsigned int len; 
    unsigned int index = 0;
    char answer3[]={'L','a',' ','r','e','s','p','u','e','s','t','a',' ','e','s',' ','f','k','3','w','f','L','C','m','3','Q','v','S'};
    char answer6[]={'L','a',' ','r','e','s','p','u','e','s','t','a',' ','e','s',' ','K','5','n','2','U','F','f','p','F','M','U','N',};
    char answer9[]={'L','a',' ','r','e','s','p','u','e','s','t','a',' ','e','s',' ','c','h','i','n','_','c','h','u','_','l','a','n','_','c','h','a','\n','\n',};

    FILE * client = fdopen(new_socket,"r");

    while(index<=12){
        system("clear");
         printf("%s\n%s\n",challengeHeader,challenges[index]);
        switch (index){
            case 3:
                write(14,answer3,29);
                break;  
            case 6:
                printf("\n%s",answer6);
                fflush(stdout);
                fprintf(stderr,"\r");
                for(int i = 0; i < 50;i++)fprintf(stderr,"%c",rand()%90 + 32);
                fflush(stderr);
                printf("\n\n\n");
                break;
            case 9:

                if(quineValidator() != 0){
                    printf("%s",answer9);
                }else{
                    printf("ENTER para reintentar.\n");
                }

                break;
            case 11:
                for(int i=0; i<NUMS ; i++){
                    printf("%f ", generateGaussian(0,1));
                }
                printf("\n");
                break;

            default:
                break;
        }


        printf("%s\n%s\n",questionHeader,questions[index]);
        len = getline(&userAnswer,&size,client);
        userAnswer[len-1]=0; 
        sprintf(command,"echo -n %s | md5sum | sed 's/  -//g'",userAnswer);
        FILE * proc = popen(command,"r");
        len = fread(hash, sizeof(char), 1024, proc);    
        hash[len-1]=0;
        pclose(proc);
        if(strcmp(hash,answers[index]) == 0){
            index++;
        }else{
            printf("Respuesta Incorrecta: %s \n", userAnswer);
            sleep(3);
        }

        switch(index){
            case 10:
                gdbme();
                break;
        }
    }




    return 0; 
} 