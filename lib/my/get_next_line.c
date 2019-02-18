/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** if you code on paper, you're not a real programmer
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char    *next_line(int fd, char *buff, int nb)
{
    char tmp[READ_SIZE + 1];
    char *line = NULL;
    int  nb_tmp = 0;
    int  size = 0;

    if ((size = read(fd, tmp, READ_SIZE)) == -1)
        return (NULL);
    tmp[size] = '\0';
    while (tmp[nb_tmp] && tmp[nb_tmp] != '\n' && tmp[nb_tmp++]);
    if (size != 0 && tmp[nb_tmp] != '\n')
        line = next_line(fd, buff, nb + nb_tmp);
    if (tmp[nb_tmp] == '\n' || size == 0) {
        if ((line = malloc(nb + nb_tmp + 1)) == NULL)
            return (NULL);
        line[nb + nb_tmp] = '\0';
        while (size-- >= 0)
            buff[size + 1] = tmp[size + 1];
    }
    while (line && --nb_tmp >= 0)
        line[nb + nb_tmp] = tmp[nb_tmp];
    return (line);
}

void    to_n(char *buff, char *line, char *tmp, int nb)
{
    int size = 0;
    int i = -1;

    (buff[nb] == '\n') ? line[nb] = '\0' : 0;
    while (line && nb-- > 0)
        line[nb] = buff[nb];
    while (tmp[++nb])
        buff[nb] = tmp[nb];
    while (buff[size] && buff[size++] != '\n');
    while (buff[++i]) {
        buff[i] = buff[i + size];
        size = ((buff[i + size]) ? size : size - 1);
    }
}

char    *get_next_line(int fd)
{
    static char buff[READ_SIZE + 1];
    char        tmp[READ_SIZE + 1];
    char        *line = NULL;
    int         nb = 0;

    if (fd == -1)
        return (NULL);
    tmp[0] = '\0';
    while (buff[nb] && buff[nb] != '\n' && buff[nb++]);
    (buff[nb] != '\n') ? line = next_line(fd, tmp, nb) : 0;
    if ((buff[nb] == '\n') && !(line = malloc(nb + 1)))
            return (NULL);
    if (line && !buff[0] && !tmp[0]) {
        if (!line[0]) {
            free(line);
            return (NULL);
        }
    }
    to_n(buff, line, tmp, nb);
    return (line);
}
