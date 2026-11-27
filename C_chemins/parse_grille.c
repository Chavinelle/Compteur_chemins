#include "chemins.h"

static int longueur_ligne (char *buf) {
    int i;
    i  = 0;
    while (buf[i] != '\0' && buf[i] != '\n' && buf[i] != '\r')
        i++;
    buf[i] = '\0';
    return(i);

}

static int caracteres_valides (char *buf) {
    int i;
    i  = 0;
    while (buf[i] != '\0') {
        if (buf[i] != '.' && buf[i] != '#')
            return(0);
        i++;
    }

    return(1);

}

static int erreur (FILE *f, const char *raison) {
    fclose(f);
    fprintf(stderr, "Detail : %s\n", raison);
    return(-1);
}

int parse_grille (const char *chemin, char grille[MAX_TAILLE][MAX_TAILLE], int *lignes, int *colonnes) {
    FILE *f;
    char buf[MAX_TAILLE + 3];
    int len;
    int col;
    int fin;

    f = fopen(chemin, "r");
    if (f==NULL)
        return(-1);
    *lignes = 0;
    *colonnes = 0;
    fin = 0;

    while (fgets(buf, sizeof(buf), f) != NULL) {
        len = longueur_ligne(buf);
        if (len == 0) {
            fin = 1;
            continue;
        }

        if (fin)
            return (erreur(f, "ligne vide au milieu de la grille"));
        if (len > MAX_TAILLE || *lignes >= MAX_TAILLE)
            return (erreur(f, "grille trop grande (max 12 x 12)"));
        if (!caracteres_valides(buf))
            return (erreur(f, "Caractere interdit (seuls '.' et '#')"));
        if (*lignes == 0)
            *colonnes = len;
        else if (len != *colonnes)
            return (erreur(f, "lignes de longueur differentes"));
        col = 0;
        while (col < len) {
            grille[*lignes][col] = buf[col];
            col++;
        }
        (*lignes)++;
    }
    if (*lignes == 0)
        return (erreur(f, "fichier vide"));
    if (grille[0][0] == '#')
        return (erreur(f, "la case de depart est un obstacle"));
    if (grille[*lignes - 1][*colonnes - 1] == '#')
        return (erreur(f, "la case d'arrivee est un obstacle"));
    fclose(f);
    return(0);
}
