/*
** EPITECH PROJECT, 2020
** init_maps.c
** File description:
** initialize maps
*/

#include "navy.h"

maps_t init_maps(maps_t maps)
{
    int i = 0;
    int j = 0;

    maps.p1_map = malloc(sizeof(char *) * 8);
    maps.visible_p1 = malloc(sizeof(char *) * 8);
    while (i < 8) {
        maps.p1_map[i] = malloc(sizeof(char) * (8 + 1));
        maps.visible_p1[i] = malloc(sizeof(char) * (8 + 1));
        while (j < 8) {
            maps.p1_map[i][j] = '.';
            maps.visible_p1[i][j] = '.';
            j++;
        }
        j = 0;
        i++;
    }
    return (maps);
}