#ifndef FILE_H
#define FILE_H

/* Booleen Vrai/faux */
typedef enum{
    FALSE,
    TRUE
}BOOL;


/* Structure de l'ordonnanceur */
typedef struct ordonnanceur{
    char nom[20]; /* nom du processus */
    int duree; /* duree du processus */
    int priorite; /* priotite du processus */
}ordonnanceur;


/* Structure de la file */
typedef struct FileElement{
    ordonnanceur value; /* La valeur de la case contient le nom, la duree et la priorite */
    struct FileElement *next; /* Element suivant */
}FileElement, *File;


/*________________________________________________________________________________________________________*/
/* Pour voir a quoi servent les fonctions dessous, aller dans le fichier file.c */


File newFile(void);
BOOL isEmptyFile(File fi);
void printFile(File fi);
int minimum (ordonnanceur x, File fi);
File ajout_activite(ordonnanceur x, File fi);
File utilisateurRentreProcessus(ordonnanceur x, int nbProcessus, File fi);
File popFile(File fi);
File run(File fi);
File step(ordonnanceur x, File fi);

#endif