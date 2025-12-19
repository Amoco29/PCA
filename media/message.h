#ifndef MESSAGE_H
#define MESSAGE_H

#include <errno.h>
#include <string.h>
#include <stdlib.h>



#define NB_MAX_MESS     50

typedef struct {
    char *texte;
    char auteur[30];
    int id;
} s_message;

typedef struct {
    s_message* messages[NB_MAX_MESS];
    int nb_mess;
} s_salon;

s_message* creerMessage(char *texte, char *auteur);
int ajouterMessage(s_salon *salon, s_message* message);
int retirerMessage(s_salon *salon , int id);
void nettoyerSalon(s_salon *salon);


#endif