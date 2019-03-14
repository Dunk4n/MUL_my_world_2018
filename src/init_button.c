/*
** EPITECH PROJECT, 2018
** src/init_boutton
** File description:
** hello world?
*/

#include <stdlib.h>
#include "world.h"

const char      *img_button[11] = {"button/save.png", "button/load.png",
"button/select-point.png", "img/diamant.jpg", "button/arrow-turn-right.png",
"button/arrow-turn-left.png", "button/arrow-right.png",
"button/arrow-left.png", "button/arrow-up.png", "button/arrow-down.png",
"button/button-color.png"};
const int       pos[11][2] = {{10, 10}, {240, 10}, {1710, 10}, {1610, 970},
{10, 810}, {70, 810}, {10, 900}, {70, 900}, {10, 990}, {70, 990}, {1810, 970}};

void    display_button(my_game_t *game)
{
    int i = 0;

    while (i < 11) {
        sfRenderWindow_drawSprite(game->win->window, game->button[i].sp, NULL);
        i++;
    }
}

void    init_button(my_game_t *game)
{
    int i = 0;
    int width = 200;
    int height = 100;

    if (!(game->button = malloc(sizeof(button_t) * 11)))
        return ;
    while (i < 11) {
        game->button[i].tx = sfTexture_createFromFile(img_button[i], NULL);
        game->button[i].sp = sfSprite_create();
        sfSprite_setTexture(game->button[i].sp, game->button[i].tx, sfTrue);
        sfSprite_setPosition(game->button[i].sp,
(sfVector2f){pos[i][0], pos[i][1]});
        sfSprite_setTextureRect(game->button[i].sp,
(sfIntRect){0, 0, width, height});
        i++;
        (i >= 4) ? width = 50 : 0;
        (i >= 4) ? height = 80 : 0;
        (i == 10) ? width = 100 : 0;
        (i == 10) ? height = 100 : 0;
    }
}
