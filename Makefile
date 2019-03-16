SDL_LIB = -L./lib -lSDL2main -lSDL2 -lSDL2_image
SDL_INCLUDE = -I./include

CC = gcc
CFLAGS = -Wall -g -std=c11 -I./include
LDFLAGS = -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

ALL = main
all: $(ALL)
main : main.o Fichier.o Edition.o Selection.o Transformations.o
	$(CC) -o main main.o Fichier.o Edition.o Selection.o Transformations.o $(LDFLAGS)
main.o : main.c main.h Fichier.h Edition.h Selection.h Transformations.h
	$(CC) -o main.o -c main.c $(CFLAGS)
Fichier.o : Fichier.c Fichier.h
	$(CC) -o Fichier.o -c Fichier.c $(CFLAGS)
Edition.o : Edition.c Edition.h
Selection.o : Selection.c Selection.h
Transformations.o : Transformations.c Transformations.h

cleanall:	
	rm -rf *~ $(ALL)
