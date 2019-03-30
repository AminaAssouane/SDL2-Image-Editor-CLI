#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fcntl.h"
#include <unistd.h>
#include <readline/readline.h>
#include "cimp.h"



// liste de pointeur de fonction

int (*addr_cmd[]) (int,char *[]) = {
    
};



// liste des commandes de l'éditeur

char *cmd_interne[] = {

};


//renvoie la taille de la ligne de commande
int args_length(char *args[]) {
    int i = 0;
    for (i = 0; args[i] != NULL; i++) {}
    return i;
}


void init_cimp()
{
    printf("\n\n\n                     **********************************\n");
    printf("\n\n\n                 Bienvenue sur votre editeur d'image CIMP     \n\n\n");
    printf("\n\n                     **********************************\n\n");

    printf("\n"); 
    

}

void prompt(void) {
    char *line;
    char **args;
    init_cimp();
    
    do {
       
        // on recupere la ligne de commande
        line = readline("<cimp>: ");
        
        //on effectue une copie de cette ligne
        char *cop = malloc(sizeof(char)*(strlen(line)+1));
        strcpy(cop,line);
        
        args = split_line(line);
        free(line);
        free(args);
    } while(1);
}

// split_line la ligne de commande pour obtenir les arguments
char **split_line(char *line) {
    int pos = 0;
    char **tab;
    char *s;
    
    // alloue un tableau qui contiendra les arguments
    if ((tab = malloc(sizeof(char*) * SIZE_CMD)) == NULL)
        exit(1);

    s = strtok(line, SEPARATEUR);
    while (s != NULL) {
        tab[pos++] = s;
        s = strtok(NULL, SEPARATEUR);
    }

    tab[pos] = NULL;
    return tab;
}


int execArgs(char *args[]) {
    pid_t pid;
    pid=fork();

    if (pid==0)
    {
        if (execvp(args[0], args) < 0) 
        { 
            fprintf(stderr, "cimp: command not found: %s\n", args[0]);
            exit(1);
        } 
        
    } 
    else if (pid < 0) 
    {
        perror("fork failed");
        exit(1);
    }
    else {
        int status;
 
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            exit(1);
        }
 
        if (WIFEXITED(status)) {// si le processus fils s'est terminé normalement
            if(WEXITSTATUS(status)==1)// renvoie la valeur de sortie du fils
                return 1;
            else
                return 0;
        }
    }
    
    return 1;
}


// execution des commandes
int exec_cmd(char *args[]) {
    if (args[0] == NULL) { return 1; }

    else{   
        int size = sizeof(cmd_interne) / sizeof(char *);
        for (int i = 0; i < size; i++) {
            if (strcmp(args[0], cmd_interne[i]) == 0)
                return (*addr_cmd[i])(args_length(args), args);
        }
        return execArgs(args);
    }
}



int main(int argc, char *argv[]) {

    //execution de la boucle d'interraction de  l'éditeur
    prompt();

    return 0;
}