/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    check_key(my_game_t *game)
{
    ((game->win->event).key.code == sfKeyUp) ? game->map->move_point_y
+= 0.1 : 0;
    ((game->win->event).key.code == sfKeyDown) ? game->map->move_point_y
-= 0.1 : 0;
    ((game->win->event).key.code == sfKeyRight) ? game->map->move_point_x
+= 0.1 : 0;
    ((game->win->event).key.code == sfKeyLeft) ? game->map->move_point_x
-= 0.1 : 0;
    ((game->win->event).key.code == sfKeyJ) ? game->map->roll = 1 : 0;
    ((game->win->event).key.code == sfKeyU) ? game->map->roll = -1 : 0;
    ((game->win->event).key.code == sfKeyK) ? game->map->yaw = 1 : 0;
    ((game->win->event).key.code == sfKeyI) ? game->map->yaw = -1 : 0;
    ((game->win->event).key.code == sfKeyL) ? game->map->pitch = 1 : 0;
    ((game->win->event).key.code == sfKeyO) ? game->map->pitch = -1 : 0;
    ((game->win->event).key.code == sfKeyE) ? game->map->zoom -= 0.5 : 0;
    ((game->win->event).key.code == sfKeyQ) ? game->map->zoom += 0.5 : 0;
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
