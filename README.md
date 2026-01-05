# Simple Shell

Un clone minimaliste du shell UNIX écrit en C.

## Description
Ce programme est un interpréteur de commandes simple. Il peut exécuter des commandes en mode interactif et non-interactif.

## Compilation
Pour compiler le programme, utilisez la commande suivante :
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Utilisation
**Mode Interactif :**
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.h
($) exit
