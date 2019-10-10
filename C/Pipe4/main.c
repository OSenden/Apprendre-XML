/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: osenden
 *
 * Created on 10 octobre 2019, 16:42
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    pid_t pid;

    pid = fork(); // duplication du processus
        if (pid == -1) // oups un probleme
        {
            fprintf(stderr, "Pb de fork !");
            exit(EXIT_FAILURE);
            
        }else{ // fork ok
            
            if(pid > 0) //p1
            {
                pid = fork;
            }else{        
                
                if(pid > 0) //p2
                {
                    
                }else{ //3
                    
                    
                }
            }
           
        }
    
    return (EXIT_SUCCESS);
}

