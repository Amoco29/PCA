#ifndef MEDIA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_TAB  20

typedef enum Type{
    LIVRE,
    MUSIQUE,
    JEU,
    FILM,
}TYPE;

typedef struct Media
{
    short nb_exemplaire;
    char *titre;
    char *auteur;
    TYPE type;

}s_media;

typedef struct Client
{
    short age;
    char* nom; 
    s_media *empreinter;
    int nb_empr;

}s_client;




//constructeur
s_client *creationClient(short age, char *nom);
s_media *creationMedia(short nb_exemplaire, char *titre,char *auteur, TYPE type);

//methode
void empreinterMedia(s_client *client, s_media *media, short nb);
void rendreMedia(s_client *client, s_media *media, short nb);

//utils
void affichageClient(s_client *client);
void affichageMedia(s_media *media);
const char *etatToString(TYPE t);

//TODO
void libererClient(s_client *client);
void libererMedia(s_media *media);

s_media *rechercherMediaParTitre(s_media **tableau, int taille, char *titre);
s_client *rechercherClientParNom(s_client **tableau, int taille, char *nom);

int mediaDisponible(s_media *media, short nb);
int clientPeutEmprunter(s_client *client);

void ajouterExemplaires(s_media *media, short nb);
void retirerExemplaires(s_media *media, short nb);




#endif