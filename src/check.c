/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    check(my_game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win->window, &(game->win->event))) {
        if ((game->win->event).type == sfEvtClosed) {
            sfRenderWindow_close(game->win->window);
            return ;
        }
        if ((game->win->event).key.code == sfKeyEscape) {
            sfRenderWindow_close(game->win->window);
            return ;
        }
        if ((game->win->event).key.code == sfKeyW) {
            game->map->center_x -= 10;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyS) {
            game->map->center_x += 10;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyD) {
            game->map->center_y += 10;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyA) {
            game->map->center_y -= 10;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyJ) {
            game->map->roll = (game->map->roll + 1 < 360) ?
(game->map->roll + 1) : 0;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyU) {
            game->map->roll = (game->map->roll - 1 > 0) ?
(game->map->roll - 1) : 360;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyK) {
            game->map->yaw = (game->map->yaw + 1 < 360) ?
(game->map->yaw + 1) : 0;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyI) {
            game->map->yaw = (game->map->yaw - 1 > 0) ?
(game->map->yaw - 1) : 360;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyL) {
            game->map->pitch = (game->map->pitch + 1 < 360) ?
(game->map->pitch + 1) : 0;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyO) {
            game->map->pitch = (game->map->pitch - 1 > 0) ?
(game->map->pitch - 1) : 360;
            game->map->update = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyE) {
            if (game->map->zoom - 1 > 4) {
                game->map->zoom -= 1;
                game->map->update = 1;
            }
            return ;
        }
        if ((game->win->event).key.code == sfKeyQ) {
            game->map->zoom += 1;
            game->map->update = 1;
            return ;
        }
    }
}
