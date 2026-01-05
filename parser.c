#include "shell.h"

/**
 * split_line - Découpe une chaîne en tableau de mots
 * @line: La chaîne à découper
 * Return: Un tableau de chaînes (terminé par NULL)
 */
char **split_line(char *line)
{
    int bufsize = 64; /* Taille arbitraire de départ */
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }

    /* On utilise les séparateurs classiques : espace, tabulation, retour ligne */
    token = strtok(line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL; /* Marquer la fin du tableau */
    return (tokens);
}
