SDL_LIB = -L./lib -lSDL2main -lSDL2 -lSDL2_image -lm -lreadline
SDL_INCLUDE = -I./include

CC = gcc
CFLAGS = -Wall -g -std=c11 -I./include
LDFLAGS = -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lm -lreadline

ALL = main
all: $(ALL)

main : 	main.o cimp.o Auxiliaires.o Fichier.o Edition.o Selection.o Transformations.o interfaceFichier.o interfaceSelection.o
	$(CC) -o main main.o cimp.o Auxiliaires.o Fichier.o Edition.o Selection.o Transformations.o interfaceFichier.o interfaceSelection.o $(LDFLAGS)

main.o : main.c main.h cimp.h
	$(CC) -o main.o -c main.c $(CFLAGS)

cimp.o : cimp.c cimp.h Auxiliaires.h Fichier.h Edition.h Selection.h Transformations.h interfaceFichier.h interfaceSelection.h
	$(CC) -o cimp.o -c cimp.c $(CFLAGS)

Auxiliaires.o : Auxiliaires.c Auxiliaires.h Fichier.h
	$(CC) -o Auxiliaires.o -c Auxiliaires.c $(CFLAGS)

Fichier.o : Fichier.c Fichier.h interfaceFichier.h
	$(CC) -o Fichier.o -c Fichier.c $(CFLAGS)
interfaceFichier.o : interfaceFichier.c interfaceFichier.h
	$(CC) -o interfaceFichier.o -c interfaceFichier.c $(CFLAGS)

Selection.o : Selection.c Selection.h interfaceSelection.h
	$(CC) -o Selection.o -c Selection.c $(CFLAGS)
interfaceSelection.o : interfaceSelection.c interfaceSelection.h
	$(CC) -o interfaceSelection.o -c interfaceSelection.c $(CFLAGS)

Edition.o : Edition.c Edition.h

Transformations.o : Transformations.c Transformations.h

cleanall:	
	rm -rf *~ $(ALL)
