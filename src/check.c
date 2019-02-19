/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    check(my_game_t *game, int *roll)
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
            roll[1] -= 10;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyS) {
            roll[1] += 10;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyD) {
            roll[2] += 10;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyA) {
            roll[2] -= 10;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyJ) {
            roll[3] = (roll[3] + 1) % 360;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyK) {
            roll[4] = (roll[4] + 1) % 360;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyL) {
            roll[5] = (roll[5] + 1) % 360;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyE) {
            roll[6] -= 1;
            roll[0] = 1;
            return ;
        }
        if ((game->win->event).key.code == sfKeyQ) {
            roll[6] += 1;
            roll[0] = 1;
            return ;
        }
    }
}
