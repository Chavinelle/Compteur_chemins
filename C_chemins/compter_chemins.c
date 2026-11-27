#include "chemins.h"

long compteurs_appels = 0;

long compter_chemins (char grille[MAX_TAILLE][MAX_TAILLE], int lignes, int colonnes, int ligne, int col) {
    compteurs_appels++;
    if (ligne >= lignes || col >= colonnes)
        return(0);
    if (grille[ligne][col] == '#')
        return(0);
    if (ligne == lignes - 1 && col == colonnes - 1)
        return(1);
    return (compter_chemins(grille, lignes, colonnes, ligne, col+1) + compter_chemins(grille, lignes, colonnes, ligne+1, col));
}

long compter_chemins_memoi (char grille[MAX_TAILLE][MAX_TAILLE], int lignes, int colonnes, int ligne, int col, long cache[MAX_TAILLE][MAX_TAILLE]) {
    compteurs_appels++;
    if (ligne >= lignes || col >= colonnes)
        return(0);
    if (grille[ligne][col] == '#')
        return(0);
    if (ligne == lignes - 1 && col == colonnes - 1)
        return(1);
    if (cache[ligne][col] != -1)
        return(cache[ligne][col]);
    cache[ligne][col] = compter_chemins_memoi(grille, lignes, colonnes, ligne, col+1, cache) + compter_chemins_memoi(grille, lignes, colonnes, ligne+1, col, cache);
    return(cache[ligne][col]);

}
