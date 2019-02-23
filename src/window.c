/*
** EPITECH PROJECT, 2018
** window
** File description:
** well, real programmers use ed
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

int     window(char *str)
{
    my_game_t    *game = NULL;
    float a = 0;

    if (!(game = set_game(str)))
        return (84);

    display_2d_map(game);
    while (sfRenderWindow_isOpen(game->win->window)) {
        //printf("%f\n", a);
        if (game->map->update == 1) {
            //printf("%d, %d, %d\n\n", roll[3], roll[4], roll[5]);
            game->map->update = 0;
            clear_buff(game->win->framebuff);
            create_2d_map(game->map);
            display_2d_map(game);
        }
        a++;
        if (a >= 360)
            a = 0;
        update(game);
        check(game);
    }
    return (0);
}
