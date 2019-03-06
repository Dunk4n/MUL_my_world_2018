/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include <stdlib.h>
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
    ((game->win->event).key.code == sfKeyJ) ? game->map->roll_fg = 1: 0;
    ((game->win->event).key.code == sfKeyU) ? game->map->roll_fg = -1 : 0;
    ((game->win->event).key.code == sfKeyK) ? game->map->yaw_fg = 1 : 0;
    ((game->win->event).key.code == sfKeyI) ? game->map->yaw_fg = -1 : 0;
    ((game->win->event).key.code == sfKeyL) ? game->map->pitch_fg = 1 : 0;
    ((game->win->event).key.code == sfKeyO) ? game->map->pitch_fg = -1 : 0;
    ((game->win->event).key.code == sfKeyE) ? game->map->zoom -= 0.5 : 0;
    ((game->win->event).key.code == sfKeyQ) ? game->map->zoom += 0.5 : 0;
}

void    check(my_game_t *game)
{
    int rnd = 0;
    sfColor col[5] = {sfRed, sfGreen, sfBlue, sfYellow, sfMagenta};

    while (sfRenderWindow_pollEvent(game->win->window, &(game->win->event))) {
        if (((game->win->event).type == sfEvtClosed) ||
                ((game->win->event).key.code == sfKeyEscape)) {
            sfRenderWindow_close(game->win->window);
        }
        (sfEvtKeyPressed) ? game->map->update = 1 : 0;
        if ((game->win->event).type == sfEvtMouseWheelScrolled) {
            game->map->update = 1;
            game->map->zoom += 0.5;
        }
        if (game->win->event.type == sfEvtMouseButtonPressed &&
game->win->t_buff[WM * game->win->event.mouseButton.y +
game->win->event.mouseButton.x] != NULL) {
            rnd = rand() % 5;
            game->win->t_buff[WM * game->win->event.mouseButton.y +
game->win->event.mouseButton.x]->color = col[rnd];
            ((triangle_t*)(game->win->t_buff[WM * game->win->event.mouseButton.y
+ game->win->event.mouseButton.x]->square_part))->color = col[rnd];
        }
        check_key(game);
        game->map->center_x += game->map->move_point_x;
        game->map->center_y += game->map->move_point_y;
    }
}
