/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: osenden
 *
 * Created on 10 octobre 2019, 15:33
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFMAX 255
/*
 * 
 */
int main(int argc, char** argv) {
    
    int nbOctets;
    int descTubePereFils[2];
    int descTubeFilsPere[2];
    const char chaine[] = "Salut fiston !";
    const char chaineReponse[] = "Salut papa !";
    char buffer[BUFFMAX];
    pid_t pid;
    memset(buffer, '\0', BUFFMAX);
    
    if(pipe(descTubePereFils) == 0)
    {
        if(pipe(descTubeFilsPere) == 0)
        {
            pid = fork(); // duplication du processus
            if (pid == -1) // oups un probleme
            {
                fprintf(stderr, "Pb de fork !");
                exit(EXIT_FAILURE);
            }else{ // fork ok
                if(pid > 0) // je suis le processus pere
                {
                    nbOctets= write(descTubePereFils[1], chaine, strlen(chaine));
                    printf("Message Pere->Fils : %d Octets écrits. \n", nbOctets);
                
                    nbOctets = read(descTubeFilsPere[0], buffer, BUFFMAX);
                    printf("Message Fils->Pere : Octets lus = %d | %s\n", nbOctets, buffer);
                
                    exit(EXIT_SUCCESS);
                }else{ // et je suis dans le processus fils
                    nbOctets = read(descTubePereFils[0], buffer, BUFFMAX);
                    printf("Message Pere->Fils : Octets lus = %d | %s\n", nbOctets, buffer);
                
                    nbOctets= write(descTubeFilsPere[1], chaineReponse, strlen(chaineReponse));
                    printf("Message Fils->Pere : %d Octets écrits. \n", nbOctets);
                }
            }
        }
    }
    
    exit(EXIT_SUCCESS);
}

