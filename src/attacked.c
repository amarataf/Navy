/*
** EPITECH PROJECT, 2020
** attacked
** File description:
** modify map when you get attacked
*/

#include "navy.h"

void attacked_p1(maps_t *m, input_t *input, int *attack_coords, int *lives)
{
    int lttr = attack_coords[0];
    int n = attack_coords[1];

    if (m->p1_map[n][lttr] >= '2' && m->p1_map[n][lttr] <= '5') {
        m->p1_map[n][lttr] = 'x';
        lives[0] -= 1;
        my_putchar(attack_coords[0] + 65);
        my_putchar(attack_coords[1] + 49);
        my_putstr(": hit\n");
        kill(input->pid, SIGUSR1);
    } else {
        my_putchar(attack_coords[0] + 65);
        my_putchar(attack_coords[1] + 49);
        my_putstr(": missed\n");
        m->p1_map[n][lttr] = 'o';
        kill(input->pid, SIGUSR2);
    }
    usleep(10000);
}

void p1_attacks(maps_t *m, input_t *input, int *attack_coords, int *lives)
{
    get_input(input);
    input->first_input = 1;
    if (input->first_input == 0)
        input->first_input = 1;
    attack_coords[0] = input->letter;
    attack_coords[1] = input->number;
}

void check_if_hit(maps_t *m, input_t *input, int *attack_coords, int *lives)
{
    int hit = attack_coords[2];

    if (hit == 1) {
        m->visible_p1[input->number][input->letter] = 'x';
        lives[1] -= 1;
        my_putchar(attack_coords[0] + 65);
        my_putchar(attack_coords[1] + 49);
        my_putstr(": hit\n");
    } else if (hit == 0) {
        m->visible_p1[input->number][input->letter] = 'o';
        my_putchar(attack_coords[0] + 65);
        my_putchar(attack_coords[1] + 49);
        my_putstr(": miss\n");
    }
}