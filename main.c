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

    for(int i = 0; i < nbProcessus; i++){ // On rentre les processus 

        printf("\n\nCompleter les champs suivants :\n");

        printf("\n\tNom de l'ordonnanceur : ");
        scanf("%s", x.nom);
        printf("\n\tNOM : %s", x.nom);

        printf("\n\tDuree de l'ordonnanceur : ");
        scanf("%d", &x.duree);
		printf("\n\tNOM : %s", x.nom);
		printf("\n\tDuree de l'ordonnanceur: %d", x.duree);

        printf("\n\tPriorite de l'ordonnanceur : ");
        scanf("%d", &x.priorite);

        while (x.priorite != 1 && x.priorite != 2 && x.priorite != 3 && x.priorite != 4 && x.priorite != 5){ 
        // Il faut que la priorite soit comprise entre 1 et 5 compris, tant que ce n'est pas le cas, on redemande de rentrer la priorite
            printf("\nLa priorite de l'ordonnanceur doit etre de 1,2,3,4 ou 5");
            printf("\n\tPriorite de l'ordonnanceur : ");
            scanf("%d", &x.priorite);
        }

		printf("\n\tNOM : %s", x.nom);
		printf("\n\tDuree de l'ordonnanceur : %d", x.duree);
		printf("\n\tPriorite : %d\n", x.priorite);

		printf("\n");

        fi = ajout_activite(x, fi); // Question a : on ajoute les processus
    }


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