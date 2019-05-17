CC = gcc
CFLAGS = -Wall -g -std=c11 -I./include
LDFLAGS = -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lm -lreadline
SDL_LIB = -L./lib -lSDL2main -lSDL2 -lSDL2_image -lm -lreadline
SDL_INCLUDE = -I./include
OBJS = main.o cimp.o Auxiliaires.o Fichier.o Edition.o Selection.o Couleurs.o Dessin.o Transformations.o

ALL = main
all: $(ALL)

main : 	$(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS) 



main.o : main.h cimp.h

cimp.o : cimp.h Auxiliaires.h Fichier.h Edition.h Selection.h  Transformations.h Couleurs.h Dessin.h Transformations.h

Auxiliaires.o : Auxiliaires.h 

Couleurs.o : Couleurs.h

Fichier.o : Fichier.h 

Dessin.o : Dessin.h
	
Selection.o : Selection.h Dessin.h 

Edition.o : Edition.h Selection.h

Transformations.o : Transformations.h 


cleanall:	
	rm -rf *~ $(ALL)
