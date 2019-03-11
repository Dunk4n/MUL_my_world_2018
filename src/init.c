/*
** EPITECH PROJECT, 2018
** src/init
** File description:
** man man
*/

#include <stdlib.h>
#include "world.h"

void            delete_framebuff(my_framebuff_t *framebuff)
{
    free(framebuff->pixels);
    free(framebuff);
}

my_framebuff_t  *my_framebuff_create(int width, int height)
{
    my_framebuff_t      *buff;

    if ((buff = malloc(sizeof(my_framebuff_t))) == NULL)
        return (NULL);
    if ((buff->pixels = malloc(sizeof(sfUint8) * width * height * 4)) == NULL) {
        free (buff);
        return (NULL);
    }
    buff->width = width;
    buff->height = height;
    return (buff);
}

my_window_t     *set_window(my_window_t *win)
{
    sfVideoMode     video_mode;

    win->texture = sfTexture_create(WM, HM);
    win->sprite = sfSprite_create();
    video_mode.width = WM;
    video_mode.height = HM;
    video_mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(video_mode, "my_world",
sfFullscreen, NULL);
    sfSprite_setTexture(win->sprite, win->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(win->window, 60);
    if ((win->framebuff = my_framebuff_create(WM, HM)) == NULL)
        return (NULL);
    win->z_buff = malloc(sizeof(double) * WM * HM);
    win->t_buff = malloc(sizeof(triangle_t*) * WM * HM);
    return (win);
}

void            set_map(map_t **map)
{
    if (!(*map = malloc(sizeof(map_t)))) {
        *map = NULL;
        return ;
    }
    (*map)->roll_fg = 0;
    (*map)->yaw_fg = 0;
    (*map)->pitch_fg = 0;
    (*map)->roll = 0;
    (*map)->yaw = 0;
    (*map)->pitch = 0;
    (*map)->move_point_x = 0;
    (*map)->move_point_y = 0;
    (*map)->center_x = 0;
    (*map)->center_y = 0;
    (*map)->tab_size_x = 10;
    (*map)->tab_size_y = 10;
    (*map)->zoom = 5;
    (*map)->enlargement = 1;
    (*map)->update = 1;
    (*map)->triangle = NULL;
    (*map)->obj = NULL;
}

my_game_t        *set_game(char *str)
{
    my_game_t    *game = malloc(sizeof(my_game_t));

    if (!game || !(game->win = malloc(sizeof(my_window_t))) ||
!(game->win = set_window(game->win))) {
        (game->win) ? free(game->win) : 0;
        (game) ? free(game) : 0;
        return (NULL);
    }
    set_map(&(game->map));
    if (!game->map) {
        (game->win) ? free(game->win) : 0;
        (game) ? free(game) : 0;
        return (NULL);
    }
    if (str) {
        if (!(game->map->obj = open_file_obj(str)))
            return (NULL);
    }
    else
        return (NULL);
    set_img(game);
    return (game);
}
