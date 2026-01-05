#include "shell.h"
/**
* main - Boucle principale
* @ac: Compteur d arguments
* @av: Tableau d arguments
* Return: 0
*/
int main(int ac, char **av)
{
char *line;
char **args;
char *path;
int status = 1;
int i;
(void)ac;
while (status)
{
if (isatty(STDIN_FILENO))
printf("($) ");
line = read_line();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
printf("\n");
return (0);
}
args = split_line(line);
if (args[0] != NULL)
{
if (strcmp(args[0], "exit") == 0)
status = 0;
else if (strcmp(args[0], "env") == 0)
{
i = 0;
while (environ[i])
{
printf("%s\n", environ[i]);
i++;
}
}
else
{
path = find_path(args[0]);
if (path != NULL)
{
args[0] = path;
execute_args(args, av[0]);
free(path);
}
else
fprintf(stderr, "%s: 1: %s: not found\n", av[0], args[0]);
}
}
free(line);
free(args);
}
return (0);
}
/**
* read_line - Lit une ligne depuis stdin
* Return: La ligne
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
