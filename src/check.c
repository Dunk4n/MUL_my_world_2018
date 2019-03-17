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

void    mouve_point(my_game_t *game)
{
    if (game->point_or_face_fg == 0 && game->select != NULL) {
        (sfKeyboard_isKeyPressed(sfKeyUp)) ? game->select->y += 0.1 : 0;
        (sfKeyboard_isKeyPressed(sfKeyDown)) ? game->select->y -= 0.1 : 0;
        (sfKeyboard_isKeyPressed(sfKeyRight)) ? game->select->x += 0.1 : 0;
        (sfKeyboard_isKeyPressed(sfKeyLeft)) ? game->select->x -= 0.1 : 0;
        ((game->win->event).key.code == sfKeyPageUp) ?
            game->select->z += 0.1 : 0;
        ((game->win->event).key.code == sfKeyPageDown) ?
            game->select->z -= 0.1 : 0;
        return ;
    }
    (sfKeyboard_isKeyPressed(sfKeyUp)) ? game->map->move_point_y += 0.1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyDown)) ? game->map->move_point_y -= 0.1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyRight)) ? game->map->move_point_x += 0.1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyLeft)) ? game->map->move_point_x -= 0.1 : 0;
    ((game->win->event).key.code == sfKeyPageUp) ?
game->map->move_point_z += 0.1 : 0;
    ((game->win->event).key.code == sfKeyPageDown) ?
game->map->move_point_z -= 0.1 : 0;
}

void    check_key(my_game_t *game)
{
    mouve_point(game);
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
}

void    check(my_game_t *game)
{
    while (sfRenderWindow_pollEvent(game->win->window, &(game->win->event))) {
        if (((game->win->event).type == sfEvtClosed) ||
sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->win->window);
        if (game->save_fg == 1) {
            get_name_file(game);
            return ;
        }
        (game->obj && (game->win->event).type == sfEvtKeyPressed) ?
game->map->update = 1 : 0;
        if (game->obj && (game->win->event).type == sfEvtMouseWheelScrolled) {
            game->map->update = 1;
            if (game->win->event.mouseWheelScroll.delta < 0)
                game->map->zoom += 5;
            else
                game->map->zoom -= 5;
        }
        if (game->win->event.type == sfEvtMouseButtonPressed)
            check_button(game);
        (game->obj) ? check_key(game) : 0;
    }
}
