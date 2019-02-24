/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    check_key(my_game_t *game)
{
    ((game->win->event).key.code == sfKeyUp) ? game->map->center_y -= 10 : 0;
    ((game->win->event).key.code == sfKeyDown) ? game->map->center_y += 10 : 0;
    ((game->win->event).key.code == sfKeyRight) ? game->map->center_x += 10 : 0;
    ((game->win->event).key.code == sfKeyLeft) ? game->map->center_x -= 10 : 0;
    ((game->win->event).key.code == sfKeyJ) ? game->map->roll =
        (game->map->roll + 1 < 360) ? (game->map->roll + 1) : 0 : 0;
    ((game->win->event).key.code == sfKeyU) ? game->map->roll =
        (game->map->roll - 1 > 0) ? (game->map->roll - 1) : 360 : 0;
    ((game->win->event).key.code == sfKeyK) ? game->map->yaw =
        (game->map->yaw + 1 < 360) ? (game->map->yaw + 1) : 0 : 0;
    ((game->win->event).key.code == sfKeyI) ? game->map->yaw =
        (game->map->yaw - 1 > 0) ? (game->map->yaw - 1) : 360 : 0;
    ((game->win->event).key.code == sfKeyL) ? game->map->pitch =
        (game->map->pitch + 1 < 360) ? (game->map->pitch + 1) : 0 : 0;
    ((game->win->event).key.code == sfKeyO) ? game->map->pitch =
        (game->map->pitch - 1 > 0) ? (game->map->pitch - 1) : 360 : 0;
    if ((game->win->event).key.code == sfKeyE)
        (game->map->zoom - 1 > 4) ? game->map->zoom -= 1 : 0;
    ((game->win->event).key.code == sfKeyQ) ? game->map->zoom += 1 : 0;
}

void    check(my_game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win->window, &(game->win->event))) {
        if (((game->win->event).type == sfEvtClosed) ||
                ((game->win->event).key.code == sfKeyEscape)) {
            sfRenderWindow_close(game->win->window);
        }
        (sfEvtKeyPressed) ? game->map->update = 1 : 0;
        check_key(game);
    }
}
