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
    (sfKeyboard_isKeyPressed(sfKeyUp)) ? game->map->move_point_y += 0.1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyDown)) ? game->map->move_point_y -= 0.1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyRight)) ? game->map->move_point_x += 0.1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyLeft)) ? game->map->move_point_x -= 0.1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyJ)) ? game->map->roll_fg = 4 : 0;
    (sfKeyboard_isKeyPressed(sfKeyU)) ? game->map->roll_fg = -4 : 0;
    (sfKeyboard_isKeyPressed(sfKeyK)) ? game->map->yaw_fg = 4 : 0;
    (sfKeyboard_isKeyPressed(sfKeyI)) ? game->map->yaw_fg = -4 : 0;
    (sfKeyboard_isKeyPressed(sfKeyL)) ? game->map->pitch_fg = 4 : 0;
    (sfKeyboard_isKeyPressed(sfKeyO)) ? game->map->pitch_fg = -4 : 0;
    (sfKeyboard_isKeyPressed(sfKeyE)) ? game->map->zoom -= 0.05 : 0;
    (sfKeyboard_isKeyPressed(sfKeyQ)) ? game->map->zoom += 0.05 : 0;
    (sfKeyboard_isKeyPressed(sfKeyZ)) ? game->map->enlargement = 1.01 : 1;
    (sfKeyboard_isKeyPressed(sfKeyX)) ? game->map->enlargement = 0.99 : 1;
    //((game->win->event).key.code == sfKeyPageUp) ? 1 : 0;
    //((game->win->event).key.code == sfKeyPageDown) ? -1 : 0;
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
    while (sfRenderWindow_pollEvent(game->win->window, &(game->win->event))) {
        if (((game->win->event).type == sfEvtClosed) ||
sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->win->window);
        ((game->win->event).type == sfEvtKeyPressed) ? game->map->update = 1 : 0;
        if ((game->win->event).type == sfEvtMouseWheelScrolled) {
            game->map->update = 1;
            if (game->win->event.mouseWheelScroll.delta < 0)
                game->map->zoom += 0.5;
            else
                game->map->zoom -= 0.5;
        }
        if (game->win->event.type == sfEvtMouseButtonPressed)
            check_button(game);
        /*if (game->win->event.type == sfEvtMouseButtonPressed &&
game->win->t_buff[WM * game->win->event.mouseButton.y +
game->win->event.mouseButton.x] != NULL) {
            rnd = rand() % 10;
            game->win->t_buff[WM * game->win->event.mouseButton.y +
game->win->event.mouseButton.x]->texture = rnd;
            if (game->win->t_buff[WM * game->win->event.mouseButton.y
+ game->win->event.mouseButton.x]->square_part)
            ((triangle_t*)(game->win->t_buff[WM * game->win->event.mouseButton.y
+ game->win->event.mouseButton.x]->square_part))->texture = rnd;
        }
        */
        check_key(game);
        game->map->center_x += game->map->move_point_x;
        game->map->center_y += game->map->move_point_y;
    }
}
