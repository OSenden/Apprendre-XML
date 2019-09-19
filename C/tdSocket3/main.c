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
    int socketClient;
    struct sockaddr_in informationsServeur;
    datePerso maDate;
    datePerso dateDuServeur;
    int retourSendto;
    int retourRecvfrom;
    
    socketClient=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
    if(socketClient==-1){
        printf("pb socket : %s\n",strerror(errno));
        exit errno;
    }
    // init de informationsServeur avec les infos du serveur
    // IP, port, type
    informationsServeur.sin_family = AF_INET;
    informationsServeur.sin_port = htons (4444);
    informationsServeur.sin_addr.s_addr = inet_addr("172.18.58.93");
    memset(informationsServeur.sin_zero,0,sizeof(informationsServeur.sin_zero)) ;
    
    strcpy(maDate.jourDeLaSemaine,"mardi");
    maDate.jour=17;
    maDate.mois=9;
    maDate.annee=2019;
    // envoyer monEntier au serveur
    retourSendto = sendto(socketClient,
            &maDate,
            sizeof(maDate),
            0,
            &informationsServeur,
            sizeof(informationsServeur));
    if(retourSendto){
        
    }
    
    // recevoir l'entier en provenance du serveur
    retourRecvfrom = recvfrom(socketClient,
            &dateDuServeur,
            sizeof(maDate),
            0,
            &informationsServeur,
            sizeof(informationsServeur));
    if(retourRecvfrom){
        
    }
    printf("Reponse du serveur : %s %d/%d/%d \n",dateDuServeur.jourDeLaSemaine, dateDuServeur.jour,dateDuServeur.mois,dateDuServeur.annee);
    
    return (EXIT_SUCCESS);
}

