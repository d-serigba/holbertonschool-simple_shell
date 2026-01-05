#include "shell.h"

/**
 * main - Boucle principale du shell
 * Return: 0 en succès
 */
int main(void)
{
    char *line;
    char **args;
    int status = 1;

    while (status)
    {
        /* 1. Afficher le prompt seulement si on est en mode interactif */
        if (isatty(STDIN_FILENO))
            printf("($) ");

        /* 2. Lire la ligne */
        line = read_line();
        if (line == NULL) /* Cas du Ctrl+D */
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            return (0);
        }

        /* 3. Couper la ligne en mots */
        args = split_line(line);

        /* 4. Exécuter la commande (si elle n'est pas vide) */
        if (args[0] != NULL)
            status = execute_args(args);

        /* 5. Nettoyer la mémoire */
        free(line);
        free(args);
    }
    return (0);
}

/**
 * read_line - Lit une ligne depuis stdin
 * Return: La ligne lue
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}
