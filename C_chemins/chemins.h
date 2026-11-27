#ifndef CHEMINS_H
#define CHEMINS_H

#include <stdio.h>

#define MAX_TAILLE 12

extern long compteurs_appels;

int parse_grille (const char *chemin, char grille[MAX_TAILLE][MAX_TAILLE], int *lignes, int *colonnes);
long compter_chemins (char grille[MAX_TAILLE][MAX_TAILLE], int lignes, int colonnes, int ligne, int col);
long compter_chemins_memoi (char grille[MAX_TAILLE][MAX_TAILLE], int lignes, int colonnes, int ligne, int col, long cache[MAX_TAILLE][MAX_TAILLE]);

#endif // CHEMINS_H
