/*
** EPITECH PROJECT, 2018
** display_2d_map
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "math.h"

void    display_2d_map(my_framebuff_t *buff, sfVector2f **map_2d)
{
    sfVector2f pos[2];
    int i = 0;
    int j = 0;

    while (i < TAB_SIZE) {
        j = 0;
        while (j < TAB_SIZE && (j + 1 < TAB_SIZE || i + 1 < TAB_SIZE)) {
            pos[0] = map_2d[i][j];
            if (j + 1 < TAB_SIZE) {
                pos[1] = map_2d[i][j + 1];
                draw_line(buff, pos, 1, sfWhite);
            }
            if (i + 1 < TAB_SIZE) {
                pos[1] = map_2d[i + 1][j];
                draw_line(buff, pos, 1, sfWhite);
            }
            j++;
        }
        i++;
    }
}
