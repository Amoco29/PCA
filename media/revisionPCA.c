#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "media.h"
#include "message.h"

#define Q           2
#define POINTEUR    0
#define MASTERMIND  0
#define EXPRESSION  0
#define MEDIA       1

#define LIGNE "#################################"

#define TAILLE_TABLEAU  4
#define NB_COULEUR  5

void my_puts(char chaine[]);
char* minVersMaj(char chaine[]);
int comparaisonTab(char *tab1, char *tab2);
void affichageTab(char *tab, int taille);
void saisieUtil(char *tab);
void my_puts(char chaine[]){
    char *p;
    for(p = chaine; *p != '\0'; p++){
        putchar(*p);
    }
    
}
char* minVersMaj(char chaine[]){
    char *resultat = malloc(strlen(chaine) + 1);
    char *p;
    int i = 0;
    for(p = chaine; *p != '\0'; p++){
        resultat[i++] = toupper(*p);
    }
    resultat[i] = '\0';
    return resultat;
}
int comparaisonTab(char *tab1, char *tab2){
    for(int i = 0; i < TAILLE_TABLEAU; i++){
        if(tab1[i] != tab2[i]){
            return 0;
        }
    }
    return 1;
}
void affichageTab(char *tab, int taille){
    printf("[ ");
    for(int i = 0; i < taille; i++){

        printf("%c, ", *(tab+i));
    }
    printf("]\n");
}
void saisieUtil(char *tab){
    scanf(" %c%c%c%c", tab, tab+1, tab+2, tab+3);
}


int main(){
    #if Q != 0
    const char chaine[] = "BONjour";
    char *p;
    #endif
    /**
     * Convertir une chaine de caractere en majuscules 
     */
    #if Q == 1
    for(p = chaine; *p != '\0'; p++){
        char c = toupper(*p);
        printf("%c",c);
    }
    printf("\n");
    #endif
    /**
     * ecrire une chaine avec putchar()
     */
    #if Q == 2

    for(p = chaine; *p != '\0'; p++){
        putchar(*p);
    }
    #endif
    #if Q == 3
    char copie[]="";
    my_puts(strcpy(copie,chaine));
    #endif
    #if Q == 4
    char nouvelleChaine[] = minVersMaj(chaine);
    #endif 
    #if POINTEUR == 1
    char lettre = 'A';
    char *c = &lettre;
    printf("Information sur ma variable : \n\n");
    printf("\t\t Type   : char\n");
    printf("\t\t Taille : %d\n", sizeof(*c));
    printf("\t\t Valeur : %c\n", *c);
    printf("\t\tAdresse : %p\n", c);

    char tab[5] = {'C','O','D','E','R'};

    for (int i = 0; i <sizeof(tab); i++){
        printf("tab[%d] = %c -> %p \n", i, *(tab + i), (tab +i));
    }
    
    int i = 2;
    int t[5];

    int *p_int= &t[0];

    *(p_int+i)=i++;

    printf("valeur de p : %d adresse de pointer %p\n",*p_int,p_int);
    for(int j = 0;j<=5; j++)
        printf("%d ,",*(t+j));
    printf("\ni = %d adresse de i :%p", i,&i);
    #endif
    #if MASTERMIND == 1

    char couleur_possible[NB_COULEUR] = {'R','V','J','B','O'};
    char code_secret[TAILLE_TABLEAU] = {'V','R','B','J'};
    const int nb_max_essai = 3;
    int nb_essai= 0;
    char saisi_utilisateur[TAILLE_TABLEAU];
    int jeu_en_cours = 0;
    char c;
    printf("Appuyez sur 'n' pour lancer le jeu\n");
    scanf("%c", &c);
    if(c == 'n') jeu_en_cours = 1;

    affichageTab(couleur_possible,NB_COULEUR);
    while(jeu_en_cours){
        saisieUtil(saisi_utilisateur);
        nb_essai++;
        affichageTab(saisi_utilisateur,TAILLE_TABLEAU);

        // cas de sortie: trouvé + nombre d'essai max atteint
        if((comparaisonTab(code_secret,saisi_utilisateur)) == 1){
            printf("Vous avez trouve !\n");
            jeu_en_cours = 0;
        }
        if(nb_essai == nb_max_essai){
            printf("Nombre d'essai max atteint, vous avez perdu...\n");
            jeu_en_cours = 0;
        }

    }
    
    #endif
    #if EXPRESSION == 1

    int i,j,k1,k2;
    i=3;j=2;k1=3;
    k1 <<= i == 3 ? (i++, 2*j+1) : j;
    k2 = i==4 && i-- ||  ++j;

    printf("i :%d\n",i);    //3
    printf("j :%d\n",j);    //2
    printf("k1 :%d\n",k1);  //96
    printf("k2 :%d\n",k2);  //1

    


    #endif

    #if MEDIA == 1

    printf("\n\n%s DEBUT %s", LIGNE,LIGNE);

    s_client *Liam = creationClient(13,"Liam");
    s_media *Ippon = creationMedia(5,"Ippon","Le Japonais",LIVRE);

    printf("\n\n%s Apres creation %s", LIGNE,LIGNE);

    affichageClient(Liam);
    affichageMedia(Ippon);

    empreinterMedia(Liam, Ippon,5);

    printf("\n\n%s Apres empreint %s", LIGNE,LIGNE);

    affichageClient(Liam);
    affichageMedia(Ippon);

    rendreMedia(Liam,Ippon,5);

    printf("\n\n%s Apres retour %s", LIGNE,LIGNE);

    affichageClient(Liam);
    affichageMedia(Ippon);

    #endif

    printf("\n");
    return 0;
}

