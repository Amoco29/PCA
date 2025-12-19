    #include"message.h"

    s_message* creerMessage(char * texte, char * auteur){
        static int compteurID = 0;

        s_message *message = (s_message*)malloc(sizeof(s_message));
        if(message==NULL) return NULL;

        message->texte=(char*)malloc(strlen(texte)+1);
        
        
        if(strlen(auteur) > 30){
            free(message->texte);
            free (message);
            return NULL;
        }
        strcpy(message->texte, texte);
        strcpy(message->auteur, auteur);
        message->auteur[30] = '\0';  // Sécurité
        message->id = compteurID++;

        return message;
    }

    int ajouterMessage(s_salon *salon, s_message* message){
        if(salon->nb_mess == NB_MAX_MESS) return -1;
        salon->messages[salon->nb_mess] = message;
        salon->nb_mess++;
        return 0;
    }
    int retirerMessage(s_salon *salon, int id){
        for(int i = 0; i <= salon->nb_mess; i ++){
            if (salon->messages[i] != NULL && salon->messages[i]->id == id) {
            // Libérer la mémoire
            free(salon->messages[i]->texte);
            free(salon->messages[i]);
            

            salon->messages[i] = NULL;           
            return 0;
        }
            
        }
        return -1;
    }
    void nettoyerSalon(s_salon *salon){
        int indexEcriture = 0;
    
    // Compacter le tableau en supprimant les NULL
    for (int i = 0; i < salon->nb_mess; i++) {
        if (salon->messages[i] != NULL) {
            salon->messages[indexEcriture] = salon->messages[i];
            indexEcriture++;
        }
    }
    
    // Mettre les cases restantes à NULL
    for (int i = indexEcriture; i < salon->nb_mess; i++) {
        salon->messages[i] = NULL;
    }
    
    // Mettre à jour le nombre de messages
    salon->nb_mess = indexEcriture;
    }