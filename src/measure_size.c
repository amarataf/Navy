/*
** EPITECH PROJECT, 2020
** maesure_size
** File description:
** maesure size of buffer
*/

#include "navy.h"

int measure_size(char *str)
{
    struct stat buffsize;

    stat(str, &buffsize);
    return (buffsize.st_size);
}