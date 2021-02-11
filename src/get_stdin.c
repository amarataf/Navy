/*
** EPITECH PROJECT, 2020
** get_stdin
** File description:
** get standard input from tty
*/

#include "libmy.h"
#include "navy.h"

void get_input(input_t *input)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    my_putstr("\nattack: ");
    lineSize = getline(&line, &len, stdin);
    if (lineSize != 3 || line[1] == '0') {
        my_putstr("wrong position");
        get_input(input);
    }
    if (line[0] - 65 > 7 || line[1] - 49 > 7) {
        my_putstr("wrong position");
        get_input(input);
    } else {
        input->letter = line[0] - 65;
        input->number = line[1] - 49;
    }
    free(line);
}