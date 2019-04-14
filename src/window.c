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

void increment_variables(my_game_t *game)
{
    game->map->roll += game->map->roll_fg;
    game->map->yaw += game->map->yaw_fg;
    game->map->pitch += game->map->pitch_fg;
    (game->map->roll >= 360) ? game->map->roll -= 360 : 0;
    (game->map->roll < 0) ? game->map->roll += 360 : 0;
    (game->map->yaw >= 360) ? game->map->yaw -= 360 : 0;
    (game->map->yaw < 0) ? game->map->yaw += 360 : 0;
    (game->map->pitch >= 360) ? game->map->pitch -= 360 : 0;
    (game->map->pitch < 0) ? game->map->pitch += 360 : 0;
    game->map->roll_fg = 0;
    game->map->yaw_fg = 0;
    game->map->pitch_fg = 0;
    game->map->move_point_x = 0;
    game->map->move_point_y = 0;
    game->map->move_point_z = 0;
    game->map->enlargement = 1;
}

void    update_obj(my_game_t *game)
{
    game->map->update = 0;
    clear_z_buff(game->win->z_buff);
    clear_t_buff(game->win->t_buff);
    clear_buff(game->win->framebuff);
    transform_move(game, game->select_obj);
    transform_lower(game, game->select_obj);
    rotation(game->map, game->select_obj);
    increment_variables(game);
    to_2d(game);
    display(game);
}

int     window(char *str)
{
    my_game_t    *game = NULL;

    if (!(game = set_game(str)))
        return (84);
    while (sfRenderWindow_isOpen(game->win->window)) {
        if (game->obj && game->map->update == 1)
            update_obj(game);
        update(game);
        check(game);
    }
    return (0);
}
