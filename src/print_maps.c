/*
** EPITECH PROJECT, 2020
** print_maps
** File description:
** print maps
*/

#include "navy.h"

void print_p1(maps_t m)
{
    int i = 0;
    int j = 0;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    while (i < 8) {
        my_put_nbr(i + 1);
        my_putchar('|');
        while (j < 8) {
            my_putchar(m.p1_map[i][j]);
            my_putchar(' ');
            j++;
        }
        my_putchar('\n');
        j = 0;
        i++;
    }
}

void print_visible_p1(maps_t m)
{
    int i = 0;
    int j = 0;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    while (i < 8) {
        my_put_nbr(i + 1);
        my_putchar('|');
        while (j < 8) {
            my_putchar(m.visible_p1[i][j]);
            my_putchar(' ');
            j++;
        }
        my_putchar('\n');
        j = 0;
        i++;
    }
}

void print_p2(maps_t m)
{
    int i = 0;
    int j = 0;

    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    while (i < 8) {
        my_put_nbr(i + 1);
        my_putchar('|');
        while (j < 8) {
            my_putchar(m.p2_map[i][j]);
            my_putchar(' ');
            j++;
        }
        my_putchar('\n');
        j = 0;
        i++;
    }
}