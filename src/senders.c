/*
** EPITECH PROJECT, 2020
** senders
** File description:
** sending numbers function
*/

#include "libmy.h"
#include "navy.h"

void send_nbr(int pid, int num)
{
    int x = 0;

    while (x < 8) {
        if (x < num)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(10000);
        x++;
    }
}

void sender(int lett, int num, int pid)
{
    int x = 0;

    while (x < 8) {
        if (x < lett)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(10000);
        x++;
    }
    send_nbr(pid, num);
}