/*
** EPITECH PROJECT, 2020
** str_to_pos
** File description:
** string to position
*/

#include "navy.h"

int str_to_pos(char *buff_p1, ship_pos_t *ship_pos)
{
    char *ship_value_p1 = my_malloc(4 + 1);

    if (my_strlen(buff_p1) != 32 || ship_value_p1 == NULL)
        return (84);
    ship_map(&ship_value_p1, &buff_p1);
    if ((my_strcmp(ship_value_p1, "2345") != 0))
        return (84);
    if (ship_position(ship_pos, &buff_p1) != 0)
        return (84);
    return (0);
}