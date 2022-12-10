# Titre : 
Ordonnancement de processus
***

# Date & groupe : 
10/12/2022 - Projet de Ing1 GM1 
***

# Auteurs : 
Melisande Clisson & Lucie Charrier
***

# Compilation : 
make all
***

# Description : 

* Effectuer un ordonnancement grace a l'utilisation des files
* On va commencer par creer une structure permettant de modeliser un processus et un ordonnanceur.
* On ecrit les fonctions permettant de creer des files, les defiler, les enfiler (cf tiret suivant), les supprimer entierement, verifier si elles sont vides
* On cree ajout_activite() qui ajoute une activite passee en parametre a la file de processus de l'ordonnanceur. Cette fonction correspond a la fonction d'empilement d'une file.
* On cree la fonction step() qui effectue un tour d'ordonnancement et en meme temps trie les programmes selon la duree d'execution. Si la file est vide, on affiche une phrase mentionnant que la file est vide. Sinon, on verifie que la tete a le plus petit temps d'execution. Si ce n'est pas le cas, on le defile et on le re-enfile a la fin. Si c'est le cas on le defile puis on l'execute en affichant le nom, la duree d'execution et la priorite.
* On cree une fonction run() qui itere step jusqu'a obtenir une file de processus vide. 
