/*
** EPITECH PROJECT, 2020
** read_file
** File description:
** read position files and put them in a matrix
*/

#include "navy.h"
#include <stdio.h>

void ship_map(char **ship1, char **buff1)
{
    int i = 0;
    int j = 0;

    while (j < 4) {
        (*ship1)[j] = (*buff1)[i];
        j++;
        i += 8;
    }
}

int read_file(ship_pos_t *ship_pos, char *file)
{
    int error = 0;
    int size_p1 = measure_size(file);
    char *buff_p1 = malloc(sizeof(char) * (size_p1 + 1));
    int fd_p1 = open(file, O_RDONLY);

    if (buff_p1 == NULL || fd_p1 == -1)
        return (84);
    buff_p1 = get_buff_p1(buff_p1, size_p1, fd_p1);
    if (error != 0)
        return (84);
    error = str_to_pos(buff_p1, ship_pos);
    if (error != 0)
        return (84);
    free (buff_p1);
    return (0);
}