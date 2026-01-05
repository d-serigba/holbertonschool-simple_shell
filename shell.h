#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Variable globale pour l'environnement (donnée par le système) */
extern char **environ;

/* Prototypes */
char **split_line(char *line);
int execute_args(char **args);
int new_process(char **args);
char *read_line(void);

#endif
