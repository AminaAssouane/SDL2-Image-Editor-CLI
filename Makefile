CC = gcc
CFLAGS = -Wall -g $(shell sdl2-config --cflags)
LDFLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_gfx -lm -lreadline -export-dynamic $(shell sdl2-config --libs)
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

Fichier.o : Fichier.h

Edition.o : Edition.h Selection.h

Selection.o : Selection.h Dessin.h 

Couleurs.o : Couleurs.h

Dessin.o : Dessin.h

Transformations.o : Transformations.h 


cleanall:	
	rm -rf *~ $(ALL)
