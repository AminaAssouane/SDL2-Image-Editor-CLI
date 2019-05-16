#ifndef CIMP_H
#define CIMP_H


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "fcntl.h"
#include <unistd.h>
#include <readline/readline.h>
#include <strings.h>
#include <assert.h>

#include "Auxiliaires.h"
#include "Fichier.h"
#include "Edition.h"
#include "Selection.h"
#include "Transformations.h"
#include "Types.h"

#define SEPARATEUR " \n\r\a\t"
#define SIZE_CMD 200
#define MAX_WIN 100


void init_cimp();
void cimp();
char **split_line(char *);
int args_length(char *[]);
int parse();


#endif
