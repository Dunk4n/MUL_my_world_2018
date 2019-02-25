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
    clear_z_buff(win->z_buff);
    return (win);
}

void            set_map(map_t **map, char *str)
{
    if (!(*map = malloc(sizeof(map_t)))) {
        *map = NULL;
        return ;
    }
    (*map)->roll = 110;
    (*map)->yaw = 45;
    (*map)->pitch = 13;
    (*map)->center_x = WM / 2;
    (*map)->center_y = HM / 2;
    (*map)->tab_size_x = 6;
    (*map)->tab_size_y = 6;
    (*map)->zoom = 20;
    (*map)->update = 1;
    (*map)->pixel = 16;
    if (!str)
        (*map)->map_3d = creat_map_3d(6, 6);
    else
        (*map)->map_3d = creat_map_3d_file(*map, str);
    (*map)->map_2d = NULL;
    create_2d_map(*map);
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
    set_map(&(game->map), str);
    if (!game->map->map_2d)
        game->map = NULL;
    if (!game->map) {
        (game->win) ? free(game->win) : 0;
        (game) ? free(game) : 0;
        return (NULL);
    }
    return (game);
}
