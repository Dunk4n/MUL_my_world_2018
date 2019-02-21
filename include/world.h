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
    float       roll;
    float       yaw;
    float       pitch;
    int         center_x;
    int         center_y;
    int         zoom;
    int         update;
    int         tab_size_x;
    int         tab_size_y;
    int         pixel;
    int         **map_3d;
    sfVector2f  **map_2d;
}               map_t;

typedef struct  my_game_s
{
    my_window_t     *win;
    map_t           *map;
    sfClock         *clock;
    sfInt64         fgt;
}               my_game_t;

void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color);
void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color);
void    draw_line(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color);
void draw_line_horizontal(my_framebuff_t *buff, sfVector3f pos, sfColor color);
void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
void    create_2d_map(map_t *map);
void    display_2d_map(my_game_t *game);
my_game_t        *set_game(char *str);
void    update(my_game_t *game);
void    check(my_game_t *game);
int     window(char *str);
void    clear_buff(my_framebuff_t *buff);
int     **creat_map_3d(int xm, int ym);
int     **creat_map_3d_file(map_t *map, char *str);

void    draw_triangle(my_framebuff_t *buff, sfVector2f *pos, sfColor color);

#define WM 1920
#define HM 1080

#endif
