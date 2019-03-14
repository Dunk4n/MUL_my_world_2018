/*
** EPITECH PROJECT, 2018
** src/init_boutton
** File description:
** hello world?
*/

#include <stdlib.h>
#include "world.h"

const char      *img_button[13] = {"button/save.png", "button/load.png",
"button/select-point.png", "img/diamant.jpg", "button/arrow-turn-right.png",
"button/arrow-turn-left.png", "button/arrow-right.png",
"button/arrow-left.png", "button/arrow-up.png", "button/arrow-down.png",
"button/button-color.png", "button/plus.png", "button/minus.png"};
const int       pos[13][2] = {{10, 10}, {240, 10}, {1710, 10}, {1610, 970},
{10, 810}, {70, 810}, {10, 900}, {70, 900}, {10, 990}, {70, 990}, {1810, 970},
{10, 720}, {70, 720}};

void    display_button(my_game_t *game)
{
    for (int i = 0; i < 13; i++)
        sfRenderWindow_drawSprite(game->win->window, game->button[i].sp, NULL);
}

void    init_button(my_game_t *game)
{
    int i = 0;
    int width = 200;
    int height = 100;

    if (!(game->button = malloc(sizeof(button_t) * 13)))
        return ;
    while (i < 13) {
        game->button[i].tx = sfTexture_createFromFile(img_button[i], NULL);
        game->button[i].sp = sfSprite_create();
        sfSprite_setTexture(game->button[i].sp, game->button[i].tx, sfTrue);
        sfSprite_setPosition(game->button[i].sp,
                (sfVector2f){pos[i][0], pos[i][1]});
        sfSprite_setTextureRect(game->button[i].sp,
(sfIntRect){0, 0, width, height});
        game->button[i].rect = (sfIntRect){pos[i][0], pos[i][1], width, height};
        i++;
        (i >= 4) ? width = 50 : 0;
        (i >= 4) ? height = 80 : 0;
        (i == 10) ? width = 100 : 0;
        (i == 10) ? width = 100 : 0;
        (i >= 11) ? height = 50 : 0;
        (i >= 11) ? height = 50 : 0;
    }
}

void    check_button(my_game_t *game)
{
    int i = 0;

    while (i < 13) {
        if (game->win->event.mouseButton.y >= game->button[i].rect.top &&
game->win->event.mouseButton.y < game->button[i].rect.top +
game->button[i].rect.height && game->win->event.mouseButton.x >=
game->button[i].rect.left && game->win->event.mouseButton.x <
game->button[i].rect.left + game->button[i].rect.width) {
            printf("A %d\n", i);
            (i == 4) ? game->map->pitch_fg = -4 : 0;
            (i == 5) ? game->map->pitch_fg = 4 : 0;
            (i == 6) ? game->map->yaw_fg = -4 : 0;
            (i == 7) ? game->map->yaw_fg = 4 : 0;
            (i == 8) ? game->map->roll_fg = 4 : 0;
            (i == 9) ? game->map->roll_fg = -4 : 0;
            (i == 11) ? game->map->zoom -= 1 : 0;
            (i == 12) ? game->map->zoom += 1 : 0;
            game->map->update = 1;
        }
        i++;
    }
}
