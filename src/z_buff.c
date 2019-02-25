/*
** EPITECH PROJECT, 2018
** src/z_buff
** File description:
** try not to segfault, good luck :)
*/

#include "world.h"

void    clear_z_buff(double *z_buff)
{
    int i = 0;

    while (i < WM * HM) {
        z_buff[i] = -42;
        i++;
    }
}

sfVector3f      pube_to_screen(const sfVector3f vec)
{
    sfVector3f res = vec;
    float per = (vec.z == 0) ? 1 : 1.0 / (vec.z + 2);

    res.x = (vec.x * per + 1) * (WM / 2);
    res.y = (-vec.y * per + 1) * (HM / 2);
    res.z = vec.z;
    return (res);
}
