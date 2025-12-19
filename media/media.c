
#include "media.h"


s_client *creationClient(short age, char *nom)
{
    s_client *client = malloc(sizeof(s_client));
    if (client == NULL) return NULL;

    client->age = age;

    client->nom = malloc(strlen(nom) + 1);
    if (client->nom == NULL) {
        free(client);
        return NULL;
    }

    strcpy(client->nom, nom);
    client->empreinter= NULL;
    client->nb_empr = 0;
    return client;
}

s_media *creationMedia(short nb_exemplaire, char *titre,char* auteur, TYPE type){
    
    s_media *media = malloc(sizeof(s_media));
    if(media == NULL) return NULL;

    media->nb_exemplaire = nb_exemplaire;
    media->type = type;

    media->auteur = (char*)malloc(strlen(auteur) +1);
    if(media->auteur == NULL) {
        free(media);
        return NULL;
    }
    strcpy(media->auteur,auteur);

    media->titre = (char*)malloc(strlen(titre) +1);
    if(media->titre == NULL) {
        free(media->auteur);
        free(media);
        return NULL;
    }
    strcpy(media->titre,titre);

    return media;
}



void affichageClient(s_client *client){
    printf("\nClient: \n\t\tNom: %s\n\t\tAge : %d", client->nom,client->age);
    
    if (client->empreinter != NULL) {
    printf("\n\t\tA empreinte : %s",client->empreinter->titre);
    printf("\n\t\tLe client possede : %d %s",client->nb_empr, etatToString(client->empreinter->type));
    }

    else printf("\n\t\tAucun media emprunte");
    
    
    
}
void affichageMedia(s_media *media){
    printf("\nMedia : \n\t\tTitre: %s\n\t\tAuteur : %s\n\t\tNombre d'exemplaire %d\n\t\tType : %s", media->titre, media->auteur, media->nb_exemplaire, etatToString(media->type));
}

void empreinterMedia(s_client *client, s_media *media, short nb){
    
    if(nb <= media->nb_exemplaire){
        client->empreinter = media;
        client->nb_empr = nb;
        media->nb_exemplaire -= nb;
    }
    else printf("nombre trop eleve");
    
}

void rendreMedia(s_client *client, s_media *media, short nb){
    if(client->empreinter != media){
        printf("Ce media n'est pas emprunte par ce client\n");
        return;
    }
    
    if(nb > client->nb_empr){
        printf("Nombre trop eleve (possede: %d)\n", client->nb_empr);
        return;
    }
    
    client->nb_empr -= nb;
    media->nb_exemplaire += nb;
    
    if(client->nb_empr == 0){
        client->empreinter = NULL;
    }
}

const char *etatToString(TYPE t)
{
    switch (t) {
        case LIVRE: return "LIVRE";
        case MUSIQUE:  return "MUSIQUE";
        case JEU: return "JEU";
        case FILM: return "FILM";
        default:   return "INCONNU";
    }
}

