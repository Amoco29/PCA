#include <stdio.h>

/* ========== DÉCORTICATION LIGNE PAR LIGNE ========== */

void ligne_k1_expliquee() {
    printf("========== LIGNE k1 <<=... ==========\n\n");
    
    int i, j, k1;
    i = 3; j = 2; k1 = 3;
    
    printf("Valeurs initiales : i=%d, j=%d, k1=%d\n\n", i, j, k1);
    
    // LA LIGNE MYSTÈRE :
    // k1 <<= i == 3 ? (i++, 2*j+1) : j;
    
    printf("Expression : k1 <<= i == 3 ? (i++, 2*j+1) : j;\n\n");
    
    printf("ÉTAPE 1 : Évaluer la condition du ternaire\n");
    printf("  i == 3 ? --> %d == 3 --> VRAI\n\n", i);
    
    printf("ÉTAPE 2 : Comme VRAI, exécuter la partie THEN : (i++, 2*j+1)\n");
    printf("  C'est un opérateur virgule (comma operator)\n");
    printf("  Ordre : d'abord i++, puis 2*j+1\n\n");
    
    printf("  2.a) i++ (post-incrémentation)\n");
    printf("       - Utilise la valeur ACTUELLE de i (3)\n");
    printf("       - PUIS incrémente i après\n");
    printf("       - i passe de %d à ", i);
    i++;
    printf("%d\n\n", i);
    
    printf("  2.b) 2*j+1\n");
    printf("       - 2 * %d + 1 = %d\n", j, 2*j+1);
    printf("       - L'opérateur virgule retourne la DERNIÈRE expression\n");
    printf("       - Donc le résultat du ternaire = 5\n\n");
    
    int resultat_ternaire = 5;
    
    printf("ÉTAPE 3 : Appliquer l'opérateur <<=\n");
    printf("  k1 <<= 5 signifie : k1 = k1 << 5\n");
    printf("  k1 << 5 = décalage à gauche de 5 bits\n\n");
    
    printf("  En binaire :\n");
    printf("  k1 = 3 = 0b00000011\n");
    printf("  k1 << 5 = décaler de 5 positions à gauche\n");
    printf("  k1 << 5 = 0b01100000 = 96\n\n");
    
    k1 = 3;
    k1 <<= resultat_ternaire;
    
    printf("RÉSULTAT FINAL :\n");
    printf("  i = %d (incrémenté de 3 à 4)\n", i);
    printf("  j = %d (inchangé)\n", j);
    printf("  k1 = %d\n\n", k1);
}

void ligne_k2_expliquee() {
    printf("========== LIGNE k2 = i==4 && i-- || ++j ==========\n\n");
    
    int i, j, k2;
    i = 4; j = 2;  // i vaut 4 après la ligne k1
    
    printf("Valeurs avant : i=%d, j=%d\n\n", i, j);
    
    // LA LIGNE MYSTÈRE :
    // k2 = i==4 && i-- || ++j;
    
    printf("Expression : k2 = i==4 && i-- || ++j;\n\n");
    
    printf("RAPPEL : Priorité des opérateurs\n");
    printf("  1. == (égalité)\n");
    printf("  2. && (ET logique) - évaluation court-circuitée\n");
    printf("  3. || (OU logique) - évaluation court-circuitée\n\n");
    
    printf("ÉTAPE 1 : Évaluer i==4\n");
    printf("  %d == 4 --> VRAI (1)\n\n", i);
    
    printf("ÉTAPE 2 : Comme i==4 est VRAI, évaluer le && (i==4 && i--)\n");
    printf("  Il faut maintenant évaluer i--\n");
    printf("  i-- (post-décrémentation) :\n");
    printf("    - Utilise la valeur ACTUELLE : i = %d --> retourne 4\n", i);
    printf("    - PUIS décrémente : i devient ", i);
    i--;
    printf("%d\n", i);
    printf("    - En logique : 4 (non-zéro) = VRAI\n\n");
    
    printf("  i==4 && i-- --> VRAI && VRAI --> VRAI\n\n");
    
    printf("ÉTAPE 3 : Évaluer le || (OU logique)\n");
    printf("  (i==4 && i--) || ++j\n");
    printf("  VRAI || ++j\n\n");
    
    printf("  COURT-CIRCUIT ! Comme la partie gauche est VRAI,\n");
    printf("  la partie droite (++j) n'est PAS évaluée !\n");
    printf("  j reste %d\n\n", j);
    
    printf("ÉTAPE 4 : Assigner à k2\n");
    printf("  k2 = VRAI = 1\n\n");
    
    k2 = 1;
    
    printf("RÉSULTAT FINAL :\n");
    printf("  i = %d (décrémenté de 4 à 3)\n", i);
    printf("  j = %d (inchangé car ++j pas évalué)\n", j);
    printf("  k2 = %d\n\n", k2);
}

/* ========== EXÉCUTION COMPLÈTE ========== */

void execution_complete() {
    printf("========================================\n");
    printf("EXÉCUTION COMPLÈTE DU CODE\n");
    printf("========================================\n\n");
    
    int i, j, k1, k2;
    i = 3; j = 2; k1 = 3;
    
    printf("ÉTAT INITIAL :\n");
    printf("  i=%d, j=%d, k1=%d\n\n", i, j, k1);
    
    // LIGNE 1 : k1 <<= i == 3 ? (i++, 2*j+1) : j;
    printf("LIGNE 1 : k1 <<= i == 3 ? (i++, 2*j+1) : j;\n");
    printf("  1. i == 3 ? --> VRAI\n");
    printf("  2. Évaluer (i++, 2*j+1)\n");
    printf("     - i++ : i devient 4, mais retourne 3\n");
    printf("     - 2*%d+1 = %d\n", j, 2*j+1);
    printf("     - Opérateur virgule retourne 5\n");
    printf("  3. k1 <<= 5 --> k1 = 3 << 5 = 96\n");
    
    k1 <<= i == 3 ? (i++, 2*j+1) : j;
    
    printf("  APRÈS : i=%d, j=%d, k1=%d\n\n", i, j, k1);
    
    // LIGNE 2 : k2 = i==4 && i-- || ++j;
    printf("LIGNE 2 : k2 = i==4 && i-- || ++j;\n");
    printf("  1. i==4 --> VRAI (i vaut 4)\n");
    printf("  2. i-- --> retourne 4 (VRAI), puis i devient 3\n");
    printf("  3. VRAI && VRAI --> VRAI\n");
    printf("  4. VRAI || ++j --> VRAI (++j pas évalué, court-circuit)\n");
    printf("  5. k2 = 1\n");
    
    k2 = i==4 && i-- || ++j;
    
    printf("  APRÈS : i=%d, j=%d, k2=%d\n\n", i, j, k2);
    
    printf("RÉSULTATS FINAUX :\n");
    printf("  i  = %d\n", i);
    printf("  j  = %d\n", j);
    printf("  k1 = %d\n", k1);
    printf("  k2 = %d\n\n", k2);
}

/* ========== TABLE DE PRIORITÉ DES OPÉRATEURS ========== */

void table_priorite() {
    printf("========================================\n");
    printf("TABLE DE PRIORITÉ DES OPÉRATEURS (du plus au moins prioritaire)\n");
    printf("========================================\n\n");
    
    printf("1.  ()                     Parenthèses\n");
    printf("2.  ++ --                  Incrémentation/Décrémentation (postfixe)\n");
    printf("3.  ++ -- (préfixe)        Incrémentation/Décrémentation (préfixe)\n");
    printf("4.  * / %%                  Multiplication, Division, Modulo\n");
    printf("5.  + -                    Addition, Soustraction\n");
    printf("6.  << >>                  Décalage binaire\n");
    printf("7.  < <= > >=              Comparaisons\n");
    printf("8.  == !=                  Égalité, Inégalité\n");
    printf("9.  &&                     ET logique (court-circuit)\n");
    printf("10. ||                     OU logique (court-circuit)\n");
    printf("11. ? :                    Opérateur ternaire\n");
    printf("12. = += -= <<= etc.       Assignation\n");
    printf("13. ,                      Opérateur virgule\n\n");
}

/* ========== CONCEPTS CLÉS ========== */

void concepts_cles() {
    printf("========================================\n");
    printf("CONCEPTS CLÉS À RETENIR\n");
    printf("========================================\n\n");
    
    printf("1. POST vs PRÉ INCRÉMENTATION\n");
    printf("   i++ : utilise la valeur ACTUELLE, puis incrémente\n");
    printf("   ++i : incrémente D'ABORD, puis utilise la nouvelle valeur\n\n");
    
    int x = 5;
    printf("   Exemple : x=%d\n", x);
    printf("   printf(\"%%d\", x++) affiche %d, x devient %d\n", x, x+1);
    x = 5;
    printf("   printf(\"%%d\", ++x) affiche %d, x devient %d\n\n", x+1, x+1);
    
    printf("2. OPÉRATEUR VIRGULE (,)\n");
    printf("   Évalue toutes les expressions de gauche à droite\n");
    printf("   Retourne la valeur de la DERNIÈRE expression\n");
    printf("   Exemple : (a=1, b=2, c=3) retourne 3\n\n");
    
    printf("3. COURT-CIRCUIT (&&, ||)\n");
    printf("   && : si gauche est FAUX, droite n'est PAS évaluée\n");
    printf("   || : si gauche est VRAI, droite n'est PAS évaluée\n\n");
    
    printf("4. DÉCALAGE BINAIRE (<<, >>)\n");
    printf("   x << n : décale x de n bits à gauche (= multiplier par 2^n)\n");
    printf("   x >> n : décale x de n bits à droite (= diviser par 2^n)\n");
    printf("   Exemple : 3 << 5 = 3 * 2^5 = 3 * 32 = 96\n\n");
    
    printf("5. OPÉRATEUR TERNAIRE (? :)\n");
    printf("   condition ? valeur_si_vrai : valeur_si_faux\n");
    printf("   Évalue la condition, puis UNE SEULE des deux branches\n\n");
}

/* ========== PROGRAMME PRINCIPAL ========== */

int main() {
    // Table de priorité
    table_priorite();
    
    // Ligne k1 expliquée
    ligne_k1_expliquee();
    
    // Ligne k2 expliquée  
    ligne_k2_expliquee();
    
    // Exécution complète
    execution_complete();
    
    // Concepts clés
    concepts_cles();
    
    return 0;
}

/* ========== RÉSUMÉ ULTRA-RAPIDE ========== */

/*
LIGNE 1 : k1 <<= i == 3 ? (i++, 2*j+1) : j;

Ordre :
1. i == 3 --> VRAI
2. (i++, 2*j+1) --> i devient 4, retourne 5
3. k1 <<= 5 --> k1 = 3 << 5 = 96

Résultat : i=4, j=2, k1=96


LIGNE 2 : k2 = i==4 && i-- || ++j;

Ordre :
1. i==4 --> VRAI
2. i-- --> retourne 4 (VRAI), i devient 3
3. VRAI && VRAI --> VRAI
4. VRAI || ++j --> VRAI (++j ignoré par court-circuit)
5. k2 = 1

Résultat : i=3, j=2, k2=1


ASTUCE POUR L'EXAMEN :
- Dessiner un tableau avec les valeurs à chaque étape
- Attention au court-circuit (&&, ||)
- i++ utilise la valeur AVANT, ++i utilise la valeur APRÈS
- L'opérateur virgule retourne la DERNIÈRE valeur
*/