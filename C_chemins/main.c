#include <stdio.h>
#include <stdlib.h>
#include "chemins.h"

static void init_cache (long cache [MAX_TAILLE][MAX_TAILLE]) {
    int i;
    int j;
    i = 0;

    while (i < MAX_TAILLE) {
        j = 0;
        while (j < MAX_TAILLE) {
            cache[i][j] = -1;
            j++;
    }
    i++;
    }
}

int main(int argc, char **argv)
{
    char grille[MAX_TAILLE][MAX_TAILLE];
    long cache[MAX_TAILLE][MAX_TAILLE];
    int lignes;
    int colonnes;
    long nb;
    long appels_naif;

    if (argc != 2) {
        fprintf(stderr, "Usage : %s <fichier_grille>\n", argv[0]);
        return (1);
    }
    if (parse_grille(argv[1], grille, &lignes, &colonnes) == -1) {
        fprintf(stderr, "Erreur : impossible de charger la grille \"%s\"" "(fichier introuvable ou format invalide)\n", argv[1]);
        return (1);
    }

    printf("Grille chargee  : %d lignes x %d colonnes\n", lignes, colonnes);
    compteurs_appels = 0;
    nb = compter_chemins(grille, lignes, colonnes, 0, 0);
    appels_naif = compteurs_appels;
    if (nb == 0)
        printf("Aucun chemin possible : la case d'arrivee est inaccessible.\n");
    else
        printf("Nombre de chemins possibles : %ld\n", nb);

    init_cache(cache);
    compteurs_appels = 0;
    compter_chemins_memoi(grille, lignes, colonnes, 0, 0, cache);
    printf("[Bonus] Appels  recursifs sans memoisation : %ld\n", appels_naif);
    printf("[Bonus] Appels  recursifs avec memoisation : %ld\n", compteurs_appels);
    return 0;
}
