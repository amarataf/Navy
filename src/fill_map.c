/*
** EPITECH PROJECT, 2020
** fill_map
** File description:
** fill maps with ship values
*/

#include "navy.h"

int fill_maps(maps_t *m, ship_pos_t *s)
{
    fill_map_p1(m, s);
    return (0);
}

void fill_vertical(maps_t *m, ship_pos_t *s, int i, int *count)
{
    int j = s->p1_pos[i][1]-49;
    int k = s->p1_pos[i][0]-65;

    if (k != s->p1_pos[i][2]-65 && j == s->p1_pos[i][3]-49) {
        while (k <= (s->p1_pos[i][2]-65)) {
            m->p1_map[j][k++] = i + 50;
            *count = *count + 1;
        }
    }
}

void fill_horizontal(maps_t *m, ship_pos_t *s, int i, int *count)
{
    int j = s->p1_pos[i][1]-49;
    int k = s->p1_pos[i][0]-65;
    int y = 0;

    if (k == s->p1_pos[i][2]-65 && j != s->p1_pos[i][3]-49) {
        while (y <= i + 1) {
            m->p1_map[j++][k] = i + 50;
            y++;
            *count = *count + 1;
        }
        y = 0;
    }
}

int check_dots(maps_t *m)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i < 8) {
        while (j < 8) {
            if (m->p1_map[i][j] == '.')
                count++;
            j++;
        }
        j = 0;
        i++;
    }
    return (count);
}

int fill_map_p1(maps_t *m, ship_pos_t *s)
{
    int i = 0;
    int count = 0;

    while (i < 4) {
        fill_vertical(m, s, i, &count);
        fill_horizontal(m, s, i, &count);
        i++;
    }
    if (check_dots(m) != 50)
        return (84);
    return (0);
}