/*
** EPITECH PROJECT, 2020
** get signal
** File description:
** receiver.c
*/

#include "libmy.h"
#include "navy.h"

signal_t rec_sig_one(signal_t sig)
{
    if (sig.one > 2)
        sig.one = sig.one * -1;
    if (sig.one < 0)
        sig.one--;
    if (sig.one == 1 || sig.one == 2)
        sig.one++;
    return (sig);
}

signal_t hit_rec(signal_t sig, int *coordinates)
{
    if (sig.one == 4)
        coordinates[2] = 0;
    else
        coordinates[2] = 1;
    sig.one = 3;
    return (sig);
}

int is_alive(int *lives)
{
    if (lives[0] == 0)
        return (1);
    else if (lives[1] == 0)
        return (0);
    return (5);
}