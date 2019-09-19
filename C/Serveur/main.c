/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: osenden
 *
 * Created on 19 septembre 2019, 14:38
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

/*
 * 
 */
    
int main(int argc, char** argv) {
    int socketServer;
    struct sockaddr_in informationsServeur;
    struct sockaddr_in informationsClient;
    int monEntier;
    int entierDuClient;
    int retourSendto;
    int retourRecvfrom;
    int tailleAdr;
    int retourBind;
    
    socketServer=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
    if(socketServer==-1){
        printf("pb socket : %s\n",strerror(errno));
        exit errno;
    }
    // init de informationsServeur avec les infos du serveur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = ntohs (2222);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.91");
    memset(informationsServeur.sin_zero,0,sizeof(informationsServeur.sin_zero)) ;
    
    retourBind = bind(socketServer,(struct sockaddr *) &informationsServeur, sizeof(informationsServeur));
    if(retourBind == -1){
        printf("pb bind : %s\n",strerror(errno));
        exit errno;
    }
    
    do{
    
        tailleAdr=sizeof (informationsClient);
    retourRecvfrom = recvfrom(socketServer, &entierDuClient, sizeof (entierDuClient), 0, (struct sockaddr *) &informationsClient, &tailleAdr);
    if(retourRecvfrom == -1){
        printf("pb reception : %s\n", strerror(errno));
        exit errno;
    }
    monEntier = entierDuClient * -1;
    
    printf("Reponse du serveur : %d\n",entierDuClient);
    
    // envoyer monEntier au serveur
    retourSendto = sendto(socketServer, (struct sockaddr*)&monEntier, sizeof(monEntier), 0, (struct sockaddr*)&informationsClient, sizeof(informationsClient));
    if(retourSendto == -1){
        printf("pb envoi : %s\n", strerror(errno));
        exit errno;
    }
    
    }while(1);
    
    return (EXIT_SUCCESS);
}