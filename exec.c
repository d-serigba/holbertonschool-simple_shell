#include "shell.h"

/**
 * new_process - Crée un processus enfant et lance la commande
 * @args: Tableau d'arguments (ex: {"/bin/ls", "-l", NULL})
 * Return: 1 pour continuer la boucle
 */
int new_process(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        /* Enfant */
        if (execve(args[0], args, environ) == -1)
        {
            perror("./hsh"); /* Affiche l'erreur si commande introuvable */
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        /* Erreur de fork */
        perror("fork");
    }
    else
    {
        /* Parent */
        wait(&status);
    }
    return (1);
}

/**
 * execute_args - Vérifie si c'est un builtin ou lance un process
 * @args: Tableau d'arguments
 * Return: 1 pour continuer, 0 pour quitter
 */
int execute_args(char **args)
{
    /* Ici on pourra ajouter "exit" et "env" plus tard */
    /* Pour l'instant, on lance tout comme un programme */
    return (new_process(args));
}
