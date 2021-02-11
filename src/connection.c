/*
** EPITECH PROJECT, 2020
** connection handler
** File description:
** handle connections
*/

#include "libmy.h"
#include "navy.h"

void hits(maps_t *maps, input_t *input, int *coordinate, int *lives)
{
    coordinate[2] = 5;
    coordinate = recieve(coordinate);
    check_if_hit(maps, input, coordinate, lives);
}

int *defend(maps_t *maps, input_t *input, int *coordinates, int *lives)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    coordinates = recieve(coordinates);
    attacked_p1(maps, input, coordinates, lives);
    return (coordinates);
}

int *print_con_ter1(int *coordinate, signal_t *sig, maps_t *m, input_t *input)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n");
    coordinate = recieve(coordinate);
    if (coordinate[0] == 777) {
        kill(sig->ter_t_pid, SIGUSR1);
        my_putstr("\nenemy connected\n");
    }
    sig->one = 3;
    print_layout(m);
    input->pid = sig->ter_t_pid;
    return (coordinate);
}

int *print_con_ter2(int *coordinate, int pid, maps_t *maps, input_t *input)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    kill(pid, SIGUSR1);
    coordinate = recieve(coordinate);
    if (coordinate[0] == 777) {
        my_putstr("successfully connected\n");
    }
    print_layout(maps);
    input->pid = pid;
    return (coordinate);
}