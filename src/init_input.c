/*
** EPITECH PROJECT, 2020
** init_input
** File description:
** initialize input structure
*/

#include "navy.h"

input_t init_input(input_t input)
{
    input.got_hit = 0;
    input.letter = 0;
    input.number = 0;
    input.first_input = 0;
    input.pid = 0;
    return (input);
}