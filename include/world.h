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

typedef struct  vector4f_s
{
    double x;
    double y;
    double z;
    double t;
}               vector4f_t;

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
    double              *z_buff;
    sfVector2u          pos;
}               my_window_t;

typedef struct  map_s
{
    float       roll;
    float       yaw;
    float       pitch;
    int         update;
    int         tab_size_x;
    int         tab_size_y;
    double      move_point_x;
    double      move_point_y;
    double      center_x;
    double      center_y;
    double      zoom;
    sfVector3f  *map_3d;
    sfVector3f  *map_2d;
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
void horz_line(my_window_t *win, sfVector3f pos, vector4f_t nor, sfColor color);
void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
void    create_2d_map(map_t *map);
void    display_2d_map(my_game_t *game);
my_game_t        *set_game(char *str);
void    update(my_game_t *game);
void    check(my_game_t *game);
int     window(char *str);
void    clear_buff(my_framebuff_t *buff);
void    put_pixel3d(my_window_t *win, sfVector3f cord, sfColor color);
void    clear_z_buff(double *z_buff);
sfVector3f      pube_to_screen(const sfVector3f vec);
void    transform_to_2d(map_t *map);
void    display(my_game_t *game);
void    set_3d_map(map_t **map, char *str);
void    rotation(map_t *map);
void    to_2d(map_t *map);
void    transform_move(map_t *map);

void    draw_triangle(my_window_t *win, sfVector3f *pos, sfColor color);

#define WM 1920
#define HM 1080

#endif
