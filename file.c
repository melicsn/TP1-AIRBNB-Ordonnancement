#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "file.h"



/* Retourne une nouvelle Liste, une liste vide */
File newFile(void)
{
	return NULL;
}

/*__________________________________________________________________________*/

/* Verifie si une file est vide, Vraie si elle est vide, faux sinon */
BOOL isEmptyFile(File fi){ 
    if(fi == NULL){
        return TRUE; // File vide
    }
    else{
        return FALSE; // File pas vide, au moins une valeur
    }
}

/*__________________________________________________________________________*/


/* Affiche une Liste*/
void printFile(File fi)
{

    printf("\nVoici la file :\n\n");
	if(isEmptyFile(fi))
	{
		printf("Rien a afficher, la file est vide.\n");
		return;
	}

	while(fi != NULL)
	{
		printf("[nom : %s | duree : %d | priorite : %d]  ->  ", fi->value.nom, fi->value.duree, fi->value.priorite);
		fi = fi->next;
	}

	printf("\n");
}


/*__________________________________________________________________________*/


/*Trouver le minimum dans une file */ 
int minimum (ordonnanceur x, File fi){
    if(isEmptyFile(fi)){
        exit(-1); // Si la file est vide, pas de valeur a retourner 
    }

    FileElement * tmp = fi; // Variable temporaire 
    
    int min = tmp->value.duree;
    while (tmp != NULL){ // Tant qu'on n'est pas a la fin de la file
        if(min > tmp->value.duree){
            min = tmp->value.duree;
        }
        tmp = tmp->next; // Permet d'aller a l'element suivant
        //printf("La duree min dans fonction boucle : %d\n", min);
    }  
    
    printf("\nLa duree minimum dans la file est : %d\n", min);
    
    return min;
  
}

/*__________________________________________________________________________*/


/* Ajoute en fin de file, enfile */
File ajout_activite(ordonnanceur x, File fi)
{
	FileElement *element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
    element->next = NULL;

	if(isEmptyFile(fi)){
		return element;
	}
		
	FileElement *temp  = fi;

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = element;

	return fi;
}


/*__________________________________________________________________________*/


/* Supprime la tete de la file et l'execute */
File popFile(File fi)
{
	FileElement *element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}
	
	printf("\n\nOn affiche le processus qui est defile :\n");
    printf("[nom : %s | duree : %d | priorite : %d]  ->  ", fi->value.nom, fi->value.duree, fi->value.priorite);
    printf("\n\n"); 

	if(isEmptyFile(fi)){
		return newFile();
	}

	element = fi->next;

	free(fi);
	fi = NULL;

	return element;
}


/*__________________________________________________________________________*/


/* Supprime tous les elements d'une file */
File run(File fi)
{
	if(isEmptyFile(fi))
		return newFile();

	while(fi != NULL){
		fi = popFile(fi);
	}

	return fi;
}


/*__________________________________________________________________________*/


/* On trie la liste selon la duree d'executuion rentree pour chaque processus. 
Si la duree est plus elevee que la plus petite duree de la liste,
il va a la fin de la file. Sinon, si la duree d'execution est la plus petite, on execute le processus. */
File step(ordonnanceur x, File fi){

    if(isEmptyFile(fi)){ // Si la file est vide, on le dit et on ne fait rien
        printf("File vide\n");
    }
    
    int min = 0; // On initialise le minimum
    

    FileElement * tmp = fi; // Variable temporaire dans laquelle on met le premier element

        
    while(!isEmptyFile(tmp)){

		printf("\n________________________________________\n");
        
        min = minimum(x, tmp); // Fonction qui calcul le minimum   
        // On recalcul le minimum de la liste a chaque boucle car, 
        // quand le premier element a la duree minimum, il est supprime

        if(tmp->value.duree == min){ // Si la duree d'execution de la tete de file est le minimum
            tmp = popFile(tmp); // On execute et supprime l'element
        }
        else{
            tmp = ajout_activite(tmp->value, tmp); // Sinon on enfile le premier element
            printf("\nLe premier element n'ayant pas la duree minimum, celui-ci est enfile a la fin"); 
            printf("\n");
			tmp = popFile(tmp); // On execute et supprime l'element  
        }
        
		printf("\n\n");
        printFile(tmp);
        
		printf("\n________________________________________\n");
    }
    return tmp;
    free(tmp);
}
