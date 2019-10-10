/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: osenden
 *
 * Created on 10 octobre 2019, 15:12
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
    int descTube[2];
    const char chaine[] = "Salut fiston !";
    char buffer[BUFFMAX];
    pid_t pid;
    memset(buffer, '\0', BUFFMAX);
    
    if(pipe(descTube) == 0)
    {
        pid = fork(); // duplication du processus
        if (pid == -1) // oups un probleme
        {
            fprintf(stderr, "Pb de fork !");
            exit(EXIT_FAILURE);
        }else{ // fork ok
            if(pid > 0) // je suis le processus pere
            {
                nbOctets= write(descTube[1], chaine, strlen(chaine));
                printf("%d Octets écrits. \n", nbOctets);
                exit(EXIT_SUCCESS);
            }else{ // et je suis dans le processus fils
                nbOctets = read(descTube[0], buffer, BUFFMAX);
                printf("Octets lus : %d: %s\n", nbOctets, buffer);
            }
        }
    }
    
    exit(EXIT_SUCCESS);
}

