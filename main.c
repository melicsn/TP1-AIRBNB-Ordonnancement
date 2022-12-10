/**
* \file TP1_AlgoProc
* \author Melisande Clisson & Lucie Charrier
* \brief DM1 Ordonnanceur
* \version 0.1
**/

#include "file.h"
#include <stdio.h>

int main(int argc,char* argv[]){

    printf("DEBUT\n\n");

	File fi = newFile();

    int nbProcessus = 0; // Initialisation du processus
    int min = 0;

    printf("Combien de processus voulez vous entrer pour l'ordonnanceur ? \n");
    scanf("%d", &nbProcessus); // L'utilisateur choisi combien de processus rentrer

    ordonnanceur x; // Declaration de x avec le type Ordonnanceur

    fi = utilisateurRentreProcessus(x, nbProcessus, fi);

    printf("\n\nAVANT TRIE :\n");
    printFile(fi);  

    
    printf("\n\nMaintenant, ON TRIE la file par ordre de duree selon calculs : \n\n");

    fi = step(x, fi); // question c
    //  d'apres la consigne, les programmes qui
    //  demandent du temps de calcul sont inseres en bout de file, et ceux qui seront defiles pour obtenir
    //  effectivement du temps processeur sont ceux qui attendent depuis le plus longtemps
    

    printFile(fi);

    // Vide la file = run() dans la consigne
    // La file est deja vide par rapport a la question c
    fi = run(fi); // question d
    printFile(fi);
    

    printf("\nFIN\n");

    return 0;
}