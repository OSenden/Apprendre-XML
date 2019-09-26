/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: osenden
 *
 * Created on 26 septembre 2019, 15:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
/*
 * 
 */

typedef struct{
    unsigned char jour;
    unsigned char mois;
    unsigned short int annee;
    char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;
    
int main(int argc, char** argv) {
    int socketServeur;
    struct sockaddr_in informationsServeur;
    struct sockaddr_in informationsClient;
    char monMessage[2048];
    char messageDuClient[2048];
    int retourBind;
    int retourListen;
    int socketClient;
    int retourWrite;
    int retourRead;
    int tailleAdr;
    char html[2048];
    
    strcpy (html,"<html><h1>TEST</h1></html>");
    strcpy (monMessage,"HTTP/1.1 200 OK\nContent-Length: ");
    strcat(monMessage,"\nContent-Type: text/html\n\n");
    strcat(monMessage,"<html><h1>TEST</h1></html>");
    
    socketServeur=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(socketServeur==-1){
        printf("pb socket : %s\n",strerror(errno));
        exit errno;
    }

    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = ntohs (8888);
    informationsServeur.sin_addr.s_addr = htonl("172.18.58.91");
    
    memset(informationsServeur.sin_zero,0,sizeof(informationsServeur.sin_zero));
    
    retourBind = bind(socketServeur,(struct sockaddr*) &informationsServeur, sizeof(informationsServeur));
    if(retourBind==-1){
        printf("pb bind : %s\n",strerror(errno));
        exit errno;
    }
    
    retourListen = listen(socketServeur,5);
    if(retourListen==-1){
        printf("pb écoute : %s\n",strerror(errno));
        exit errno;
    }
    
    do{
        tailleAdr = sizeof(informationsClient);
        socketClient = accept(socketServeur,(struct sockaddr*)&informationsClient, &tailleAdr);
        if(socketClient==-1){
            printf("pb confirmation : %s\n",strerror(errno));
            exit errno;
        }
        
        printf("Connexion entrante...");
        memset(messageDuClient,0,2048);
        retourRead = read(socketClient,messageDuClient,2048);
        if(retourRead==-1){
            printf("pb lecture : %s\n",strerror(errno));
            exit errno;
        }
        
        printf("%s\n", messageDuClient);
        printf("Message: %s",monMessage);
        
        retourWrite = write(socketClient,monMessage,strlen(monMessage));
        if(retourWrite==-1){
            printf("pb écriture : %s\n",strerror(errno));
            exit errno;
        }
    }while(1);
    close(socketServeur);
    return (EXIT_SUCCESS);
}


