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
    while (sfRenderWindow_isOpen(game->win->window)) {
        //printf("%f\n", a);
        if (game->map->update == 1) {
            //printf("%d, %d, %d\n\n", roll[3], roll[4], roll[5]);
            game->map->update = 0;
            clear_buff(game->win->framebuff);
            transform_move(game);
            rotation(game->map);
            game->map->roll += game->map->roll_fg;
            game->map->yaw += game->map->yaw_fg;
            game->map->pitch += game->map->pitch_fg;
            if (game->map->roll >= 360)
                game->map->roll -= 360;
            if (game->map->roll < 0)
                game->map->roll += 360;
            if (game->map->yaw >= 360)
                game->map->yaw -= 360;
            if (game->map->yaw < 0)
                game->map->yaw += 360;
            if (game->map->pitch >= 360)
                game->map->pitch -= 360;
            if (game->map->pitch < 0)
                game->map->pitch += 360;
            game->map->roll_fg = 0;
            game->map->yaw_fg = 0;
            game->map->pitch_fg = 0;
            game->map->move_point_x = 0;
            game->map->move_point_y = 0;
            to_2d(game);
            display(game);
            clear_z_buff(game->win->z_buff);
        }
        a++;
        if (a >= 360)
            a = 0;
        update(game);
        check(game);
    }
    return (0);
}
