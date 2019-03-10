/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
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
    ((game->win->event).key.code == sfKeyJ) ? game->map->roll_fg = 2 : 0;
    ((game->win->event).key.code == sfKeyU) ? game->map->roll_fg = -2 : 0;
    ((game->win->event).key.code == sfKeyK) ? game->map->yaw_fg = 2 : 0;
    ((game->win->event).key.code == sfKeyI) ? game->map->yaw_fg = -2 : 0;
    ((game->win->event).key.code == sfKeyL) ? game->map->pitch_fg = 2 : 0;
    ((game->win->event).key.code == sfKeyO) ? game->map->pitch_fg = -2 : 0;
    ((game->win->event).key.code == sfKeyE) ? game->map->zoom -= 0.05 : 0;
    ((game->win->event).key.code == sfKeyQ) ? game->map->zoom += 0.05 : 0;
}

sfVector3f      *get_nearest_point(my_game_t *game, triangle_t *tri)
{
    int i = 0;
    int j = 0;
    double tmp;
    double res = pow(game->win->event.mouseButton.y -
((triangle_t*)(tri->square_part))->point_2d[0]->y, 2) +
pow(game->win->event.mouseButton.x -
((triangle_t*)(tri->square_part))->point_2d[0]->x, 2);

    while (i < 3) {
        tmp = pow(game->win->event.mouseButton.y - tri->point_2d[i]->y, 2) +
            pow(game->win->event.mouseButton.x - tri->point_2d[i]->x, 2);
        if (tmp < res) {
            j = i + 1;
            res = tmp;
        }
        i++;
    }
    if (j == 0)
        return (((triangle_t*)(tri->square_part))->point_3d[0]);
    return (tri->point_3d[j - 1]);
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
            if (game->win->t_buff[WM * game->win->event.mouseButton.y
+ game->win->event.mouseButton.x]->square_part)
            ((triangle_t*)(game->win->t_buff[WM * game->win->event.mouseButton.y
+ game->win->event.mouseButton.x]->square_part))->color = col[rnd];
        }
        check_key(game);
        game->map->center_x += game->map->move_point_x;
        game->map->center_y += game->map->move_point_y;
    }
}
