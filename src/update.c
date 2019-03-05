/*
** EPITECH PROJECT, 2018
** src/update
** File description:
** you're a bad developer
*/

#include "world.h"

void    clear_buff(my_framebuff_t *buff)
{
    int i = 0;

    while (i < WM * HM) {
        buff->pixels[i * 4] = 0;
        buff->pixels[i * 4 + 1] = 0;
        buff->pixels[i * 4 + 2] = 0;
        buff->pixels[i * 4 + 3] = 0;
        i++;
    }
}

void    update(my_game_t *game)
{
    sfRenderWindow_clear(game->win->window, sfBlack);
    sfTexture_updateFromPixels(game->win->texture, game->win->framebuff->pixels,
WM, HM, 0, 0);
    sfRenderWindow_drawSprite(game->win->window, game->win->sprite, NULL);
    sfRenderWindow_display(game->win->window);
}
