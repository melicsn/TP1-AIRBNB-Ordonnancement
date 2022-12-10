CFLAGS = -Wall -ansi -pedantic
CC = gcc
LIBS = -lm
EXEC = prog
SRC = $(wildcard *.c) $(wildcard *.h)
OBJ = $(SRC:.c=.o)
ARCHIVE = Archive.zip
ALL = $(EXEC) $(SRC)
REPO = src doc bin 

all : $(EXEC) run

%.o : %.c
	$(CC) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean : 
	rm *o

run :
	./$(EXEC)

doc : 
	doxygen -g
	doxygen Doxyfile
	mkdir doc
	mv html/ latex Doxyfile* doc/

preprendu : 
	mkdir rendu

bin :
	mkdir rendu/bin
	mv $(EXEC) rendu/bin/

source :
	mkdir rendu/src
	mv $(SRC) rendu/src

rendu : $(EXEC) clean doc preprendu source bin
	mv doc rendu
	cp Makefile readme rendu
	zip $(ARCHIVE) rendu

unrendu :
	mv rendu/bin/* rendu/src/* .
	rm -r rendu
	rm $(ARCHIVE)
	
test :
	./bin/$(EXEC)	

#ajouter une commande zip 

#Variables spéciales 

# $@ nom cible
# $< nom première dépendence
# $^ liste dépendences
# $? liste dépendances plus récentes que la cible
# $* nom fichier sans son extension
