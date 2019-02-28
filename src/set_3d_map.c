/*
** EPITECH PROJECT, 2018
** set_3d_map
** File description:
** no, real programmers use cat
*/

#include <stdlib.h>
#include "world.h"

void    set_white_map(map_t **map)
{
    int i = 0;
    int j = 0;

    (*map)->map_3d = malloc(sizeof(sfVector3f) *
(*map)->tab_size_x * (*map)->tab_size_y);
    while (i < (*map)->tab_size_x) {
        j = 0;
        while (j < (*map)->tab_size_y) {
            (*map)->map_3d[i * (*map)->tab_size_x + j].x = ((double)(i) -
(double)((*map)->tab_size_x) / 2.0) + (((*map)->tab_size_x % 2) ? 0 : 0.5) / (*map)->zoom;
            (*map)->map_3d[i * (*map)->tab_size_x + j].y = ((double)(j) -
(double)((*map)->tab_size_y) / 2.0) + (((*map)->tab_size_y % 2) ? 0 : 0.5) / (*map)->zoom;
            if (i != 0 && j != 0 && i + 1 != (*map)->tab_size_x && j + 1 != (*map)->tab_size_y)
                (*map)->map_3d[i * (*map)->tab_size_x + j].z = (double)(-(rand() % 5)) / 6.0;
            else
                (*map)->map_3d[i * (*map)->tab_size_x + j].z = 0;
            j++;
        }
        i++;
    }
}

void    set_3d_map(map_t **map, char *str)
{
    if (!str) {
        set_white_map(map);
        return ;
    }
}
