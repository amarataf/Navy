/*
** EPITECH PROJECT, 2020
** print_layout
** File description:
** print enemy's map and your map
*/

#include "navy.h"

void print_layout(maps_t *maps)
{
    my_putstr("\nmy positions:\n");
    print_p1(*maps);
    my_putstr("\nenemy's positions:\n");
    print_visible_p1(*maps);
}