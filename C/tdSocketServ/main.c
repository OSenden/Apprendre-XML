/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: nderouelle
 *
 * Created on 10 septembre 2019, 11:36
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

typedef struct{
    unsigned char jour;
    unsigned char mois;
    unsigned short int annee;
    char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;
    
int main(int argc, char** argv) {
    int socketServer;
    struct sockaddr_in informationsServeur;
    int monEntier;
    int entierDuClient;
    int retourSendto;
    int retourRecvfrom;
    int tailleAdr;
    
    socketServer=socket(PF_INET,SOCK_DGRAM,IPPROTO_TCP);
    if(socketServer==-1){
        printf("pb socket : %s\n",strerror(errno));
        exit errno;
    }
    // init de informationsServeur avec les infos du serveur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = ntohs (55555);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.134");
    memset(informationsServeur.sin_zero,0,sizeof(informationsServeur.sin_zero)) ;
    
    tailleAdr=sizeof(informationsServeur);
    // recevoir l'entier en provenance du serveur
    retourRecvfrom = recvfrom(socketServer,
            (struct sockaddr*)&entierDuClient,
            sizeof(monEntier),
            0,
            (struct sockaddr*)&informationsServeur,
            sizeof(informationsServeur));
    if(retourRecvfrom){
        
    }
    printf("Reponse du serveur : %d\n",entierDuClient);
    
    monEntier=12;
    // envoyer monEntier au serveur
    retourSendto = sendto(socketServer,
            (struct sockaddr*)&monEntier,
            sizeof(monEntier),
            0,
            (struct sockaddr*)&informationsServeur,
            sizeof(informationsServeur));
    if(retourSendto){
        
    }
    
    return (EXIT_SUCCESS);
}

