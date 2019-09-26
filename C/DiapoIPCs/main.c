/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: nderouelle
 *
 * Created on 24 septembre 2019, 11:15
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int retour;
    retour=system("uname -a");
    if(retour==-1){
        printf("pb avec l'appel de la fct system");
        exit(0);
    }
    
    
    
    return (EXIT_SUCCESS);
}

