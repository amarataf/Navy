/*
** EPITECH PROJECT, 2020
** init_ship_pos
** File description:
** initialize ship positions
*/

#include "navy.h"

ship_pos_t init_ship_pos(ship_pos_t ship_pos)
{
    int i = 0;

    ship_pos.p1_pos = malloc(sizeof(char *) * 4);
    ship_pos.p2_pos = malloc(sizeof(char *) * 4);
    while (i < 4) {
        ship_pos.p1_pos[i] = malloc(sizeof(char) * (4 + 1));
        ship_pos.p2_pos[i] = malloc(sizeof(char) * (4 + 1));
        i++;
    }
    return (ship_pos);
}