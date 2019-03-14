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
const int       rect[13][2] = {{200, 100}, {200, 100}, {200, 100}, {200, 100},
{50, 80}, {50, 80}, {50, 80}, {50, 80}, {50, 80}, {50, 80}, {100, 100},
{50, 50}, {50, 50}};

void    display_button(my_game_t *game)
{
    for (int i = 0; i < 13; i++)
        sfRenderWindow_drawSprite(game->win->window, game->button[i].sp, NULL);
}

void    init_button(my_game_t *game)
{
    int i = -1;

    if (!(game->button = malloc(sizeof(button_t) * 13)))
        return ;
    while (++i < 13) {
        game->button[i].tx = sfTexture_createFromFile(img_button[i], NULL);
        game->button[i].sp = sfSprite_create();
        sfSprite_setTexture(game->button[i].sp, game->button[i].tx, sfTrue);
        sfSprite_setPosition(game->button[i].sp,
(sfVector2f){pos[i][0], pos[i][1]});
        sfSprite_setTextureRect(game->button[i].sp,
(sfIntRect){0, 0, rect[i][0], rect[i][1]});
        game->button[i].rect = (sfIntRect){pos[i][0], pos[i][1],
rect[i][0], rect[i][1]};
    }
}

void    make_button_texture_color(my_game_t *game)
{
    if (game->t_or_c_fg == 0) {
        game->button[10].tx =
sfTexture_createFromFile("button/button-texture.png", NULL);
        sfSprite_setTexture(game->button[10].sp, game->button[10].tx, sfTrue);
        game->t_or_c_fg = 1;
        return ;
    }
    game->button[10].tx =
sfTexture_createFromFile("button/button-color.png", NULL);
    sfSprite_setTexture(game->button[10].sp, game->button[10].tx, sfTrue);
    game->t_or_c_fg = 0;
}

void    make_button(my_game_t *game, int i)
{
    (i == 3) ? make_button_texture(game) : 0;
    (i == 4) ? game->map->pitch_fg = -4 : 0;
    (i == 5) ? game->map->pitch_fg = 4 : 0;
    (i == 6) ? game->map->yaw_fg = -4 : 0;
    (i == 7) ? game->map->yaw_fg = 4 : 0;
    (i == 8) ? game->map->roll_fg = 4 : 0;
    (i == 9) ? game->map->roll_fg = -4 : 0;
    (i == 10) ? make_button_texture_color(game) : 0;
    (i == 11) ? game->map->zoom -= 1 : 0;
    (i == 12) ? game->map->zoom += 1 : 0;
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
            make_button(game, i);
            game->map->update = 1;
            return ;
        }
        i++;
    }
}
