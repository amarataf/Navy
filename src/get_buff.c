/*
** EPITECH PROJECT, 2020
** get_buff
** File description:
** get buffers
*/

#include "navy.h"

char *get_buff_p1(char *buff, int size, int fd)
{
    read (fd, buff, size);
    buff[size] = '\0';
    close (fd);
    return (buff);
}

char *get_buff_p2(char *buff, int size, int fd)
{
    read (fd, buff, size);
    buff[size] = '\0';
    close (fd);
    return (buff);
}