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

const char      *img_name[13];
const char      *img_button[13];
const sfColor   color[10];

typedef struct  arg_interpolation_s
{
    double iza;
    double uiza;
    double viza;
    double dizdx;
    double duizdx;
    double dvizdx;
    double xa;
    double xb;
    double dxdya;
    double dxdyb;
    double dizdya;
    double duizdya;
    double dvizdya;
    int y1;
    int y2;
    int y1i;
    int y2i;
    int y3i;
}               arg_interpolation_t;

typedef struct  vector4f_s
{
    double x;
    double y;
    double z;
    double t;
    double bcy;
    double cbx;
    double cay;
    double acx;
    double div;
    sfVector3f c_point;
    sfVector3f a_uv;
    sfVector3f b_uv;
    sfVector3f c_uv;
    sfVector3f sz;
    sfVector3f su;
    sfVector3f sv;
}             vector4f_t;

typedef struct  my_framebuff_s
{
    int         width;
    int         height;
    sfUint8     *pixels;
}               my_framebuff_t;

typedef struct  triangle_s
{
    int         texture;
    sfVector3f  *point_3d[3];
    sfVector3f  *point_2d[3];
    sfVector3f  *point_tx[3];
    sfColor     color;
    int         indice_point[3];
    int         indice_texture[3];
    void        *square_part;
}               triangle_t;

typedef struct  my_window_s
{
    sfRenderWindow      *window;
    sfEvent             event;
    sfTexture           *texture;
    sfSprite            *sprite;
    my_framebuff_t      *framebuff;
    double              *z_buff;
    triangle_t          **t_buff;
    sfVector2u          pos;
}               my_window_t;

typedef struct  obj_s
{
    int         nb_point;
    int         nb_tr;
    int         nb_tx;
    sfVector3f  *point_3d;
    sfVector3f  *point_2d;
    sfVector3f  *point_tx;
    triangle_t  *triangle;
}               obj_t;

typedef struct  map_s
{
    float       roll_fg;
    float       yaw_fg;
    float       pitch_fg;
    float       roll;
    float       yaw;
    float       pitch;
    int         update;
    double      move_point_x;
    double      move_point_y;
    double      move_point_z;
    double      enlargement;
    double      zoom;
    double      lum;
    triangle_t  *ptr_tri;
    sfVector3f  *map_3d;
    sfVector3f  *map_2d;
    triangle_t  *triangle;
    obj_t       *obj;
}               map_t;

typedef struct  button_s
{
    sfTexture           *tx;
    sfSprite            *sp;
    sfIntRect           rect;
    int                 fg;
}               button_t;

typedef struct  my_game_s
{
    my_window_t     *win;
    map_t           *map;
    sfImage         **img;
    button_t        *button;
    sfTexture       *tx_button;
    sfSprite        *sp_button;
    sfIntRect       rect_button;
    sfVector3f      *select;
    sfText          *txt;
    char            text[50];
    char            last_input;
    int             text_nb;
    int             save_fg;
    int             load_fg;
    int             point_or_face_fg;
    int             t_or_c_fg;
    int             tex_col_fg;
    int             nb_img;
    int             nb_col_max;
}               my_game_t;

void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color);
void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color);
void    draw_line(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color);
void horz_line(my_game_t *game, sfVector3f pos, vector4f_t nor, sfColor color);
void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
void    create_2d_map(map_t *map);
my_game_t        *set_game(char *str);
void    update(my_game_t *game);
void    check(my_game_t *game);
int     window(char *str);
void    clear_buff(my_framebuff_t *buff);
void    put_pixel3d(my_game_t *game, sfVector3f cord, sfColor color);
void    clear_z_buff(double *z_buff);
void    clear_t_buff(triangle_t **t_buff);
sfVector3f      pube_to_screen(const sfVector3f vec);
void    transform_to_2d(map_t *map);
void    display(my_game_t *game);
void    rotation(map_t *map);
void    to_2d(my_game_t *game);
void    transform_move(my_game_t *game);
sfVector3f      normal_vec(sfVector3f a, sfVector3f b, sfVector3f c);
void    set_map(map_t **map);
obj_t   *open_file_obj(char *name);
void    free_array(char **array);
obj_t   *init_obj(void);
int     get_nbr_arg(obj_t *obj, char *name);
int     set_obj(obj_t *obj, char *name);
double  my_getfloat(char *str);
void    set_img(my_game_t *game);
void    set_point_tx(obj_t *obj, char **array);
void    horz_line_tx(my_game_t *game, sfVector3f pos, vector4f_t nor,
sfColor color);
void    transform_lower(my_game_t *game);
double  magnitude(sfVector3f v);
sfVector3f      cross_product(sfVector3f a, sfVector3f b);
void    draw_poly(my_game_t *game, triangle_t *tri);
void    init_arg(arg_interpolation_t *arg, double *tab);
int     calc_side(double *tab);
int     cond_inter(double *tab, int y1i, int y2i, int y3i);
void    swap_float(double *a, double *b);
void    draw_poly_interpolation(my_game_t *game, triangle_t *tri,
arg_interpolation_t *arg);
void    sort_ordone(double *tab);
void    init_draw_poly(my_game_t *game, triangle_t *tri, double *tab);
void    init_button(my_game_t *game);
void    display_button(my_game_t *game);
void    check_button(my_game_t *game);
void    make_button_texture(my_game_t *game);
void    point_or_face(my_game_t *game);
void    action_on_obj(my_game_t *game);
void    set_value_game(my_game_t *game);
void    draw_triangle(my_game_t *game, sfVector3f *pos, sfColor color);
void    save_file(my_game_t *game);
int     init_all_game(char *str, my_game_t *game);
void    get_name_file(my_game_t *game);
void    write_one_face(triangle_t *tri, int fd);
void    write_all_vertice_tex(my_game_t *game, int fd);
void    write_all_vertice(my_game_t *game, int fd);
void    set_triangle_tx(obj_t *obj, char **array, int nb);
void    set_point(obj_t *obj, char **array);

#define WM 1920
#define HM 1080

#endif
