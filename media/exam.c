#include <stdio.h>
#include <stdlib.h>
#include "message.h"


#define Q               3


int main(){
    #if Q == 1
    int i = 10;
    int j = 0;
    void *p;
    p=&i;
    j= *(int*)p;
    printf("%d", j);
    #endif
    #if Q == 2
    char *chaine = "A22";
    char *p = chaine;  // Utiliser char* directement, pas void*
    int tab[100][26];
    int colonne;
    int ligne;
    
    // Étape 1 : Lire la lettre
    if (*p >= 'A' && *p <= 'Z') {
        colonne = *p - 'A';
        p++;  // Avancer le pointeur !
    }
    
    // Étape 2 : Lire le nombre (convertir la chaîne en int)
    ligne = atoi(p) - 1;
    
    printf("Chaine '%s' -> tab[%d][%d]\n", chaine, ligne, colonne);

    #endif
    #if Q == 3

    s_message *msg1 = creerMessage("Bonjour Pierre", "Alice");
    s_message *msg2 = creerMessage("Salut Alice", "Pierre");

    s_salon salon;
    salon.nb_mess = 0;

    ajouterMessage(&salon, msg1);
    ajouterMessage(&salon, msg2);


    printf("Messages dans le salon avant retrait :\n");

    for(int i = 0; i < salon.nb_mess; i++){
        printf("ID: %d, Auteur: %s, Texte: %s\n", salon.messages[i]->id, salon.messages[i]->auteur, salon.messages[i]->texte);
    }

    retirerMessage(&salon,0);
    nettoyerSalon(&salon);

    printf("\nMessages dans le salon après retrait et nettoyage :\n");
    
    for(int i = 0; i < salon.nb_mess; i++){
        if(salon.messages[i] != NULL){
            printf("ID: %d, Auteur: %s, Texte: %s\n", salon.messages[i]->id, salon.messages[i]->auteur, salon.messages[i]->texte);
        }
    }

    


    #endif
    return 0;
}