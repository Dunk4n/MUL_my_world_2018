/*
** EPITECH PROJECT, 2018
** my_strdupcat
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char    *my_strdupcat(char *dest, char const *src)
{
    char *res = NULL;
    int i = 0;
    int j = 0;

    if (!dest || !src)
        return (NULL);
    if (!(res = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1))))
        return (NULL);
    while (dest[i]) {
        res[i] = dest[i];
        i++;
    }
    while (src[j]) {
        res[i + j] = src[j];
        j++;
    }
    res[i + j] = '\0';
    return (res);
}
