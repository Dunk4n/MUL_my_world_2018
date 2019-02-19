/*
** EPITECH PROJECT, 2018
** src/iso
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "math.h"

sfVector2f      project_iso_point(double x, double y, double z, int f,
float roll, float yaw, float pitch, int hh, int ww, int dis)
{
    sfVector2f pos = {0, 0};
    float tab[] = {roll * M_PI / 180, yaw * M_PI / 180, pitch * M_PI / 180};
    double xx = x;
    double yy = y;

    z = z / 6;
    yy = (cos(tab[0]) * y) - (sin(tab[0]) * z);
    z = (sin(tab[0]) * y) + (cos(tab[0]) * z);

    xx = (cos(tab[1]) * x) + (sin(tab[1]) * z);
    z = -(sin(tab[1]) * x) + (cos(tab[1]) * z);

    x = (cos(tab[2]) * xx) - (sin(tab[2]) * yy);
    y = (sin(tab[2]) * xx) + (cos(tab[2]) * yy);

    pos.x = ww + ((x * f * 20) / (z + dis));
    pos.y = hh + ((y * f * 20) / (z + dis));
    return (pos);
}

sfVector2f      **create_2d_map(int **d3_map, int *roll)
{
    sfVector2f  **tab = NULL;
    int         i = 0;
    int         j = 0;

    if (!(tab = malloc(sizeof(sfVector2f*) * (TAB_SIZE))))
        return (NULL);
    while (i < TAB_SIZE) {
        if (!(tab[i] = malloc(sizeof(sfVector2f) * TAB_SIZE)))
            return (NULL);
        j = 0;
        while (j < TAB_SIZE) {
            tab[i][j] = project_iso_point((double)i - TAB_SIZE / 2.0 + 0.5,
(double)j - TAB_SIZE / 2.0 + 0.5, (double)d3_map[i][j], 128,
roll[3], roll[4], roll[5], roll[1], roll[2], roll[6]);
            j++;
        }
        i++;
    }
    return (tab);
}
