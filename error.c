//
// Created by denys on 9/11/17.
//

#include <stdio.h>
#include <stdlib.h>

void    error(char *message, int status)
{
    perror(message);
    exit(0);
}