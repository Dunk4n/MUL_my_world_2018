/*
** EPITECH PROJECT, 2018
** world
** File description:
** try not to segfault, good luck :)
*/

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

typedef struct  my_framebuff_s
{
    int         width;
    int         height;
    sfUint8     *pixels;
}               my_framebuff_t;

typedef struct  my_window_s
{
    sfRenderWindow      *window;
    sfEvent             event;
    sfTexture           *texture;
    sfSprite            *sprite;
    my_framebuff_t      *framebuff;
    sfVector2u          pos;
}               my_window_t;

typedef struct  map_s
{
    int update;
    float roll;
    float yaw;
    float pitch;
    float roll;
}               map_t;
typedef struct  my_game_s
{
    my_window_t     *win;
    sfClock         *clock;
    sfInt64         fgt;
}               my_game_t;

void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color);
void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color);
void    draw_line(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color);
void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
sfVector2f      **create_2d_map(int **d3_map, int *roll);
void    display_2d_map(my_framebuff_t *buff, sfVector2f **map_2d);
my_game_t        *set_game(char *str);
void    update(my_game_t *game);
void    check(my_game_t *game, int *roll);
int     window(char *str);
void    clear_buff(my_framebuff_t *buff);

#define WM 1920
#define HM 1080

#define TAB_SIZE 6

#endif