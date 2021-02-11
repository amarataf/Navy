/*
** EPITECH PROJECT, 2020
** connection
** File description:
** check connection
*/

#include "libmy.h"
#include "navy.h"

int main(int ac, char **av)
{
    int error = 0;
    if (ac > 3 || ac < 2)
        return (84);
    error = navy(ac, av);
    return (error);
}