/*
** EPITECH PROJECT, 2018
** src/z_buff
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "world.h"

void    clear_z_buff(double *z_buff)
{
    int i = 0;

    while (i < WM * HM) {
        z_buff[i] = -42;
        i++;
    }
}

void    clear_t_buff(triangle_t **t_buff)
{
    int i = 0;

    while (i < WM * HM) {
        t_buff[i] = NULL;
        i++;
    }
}
