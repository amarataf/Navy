/*
** EPITECH PROJECT, 2020
** start game
** File description:
** start game for both terminals
*/

#include "libmy.h"
#include "navy.h"

signal_t sig;

void check_con_par(int signo, siginfo_t *info, void *extra)
{
    info = info;
    extra = extra;
    if (signo == 12) {
        if (sig.one < 0)
            sig.one = sig.one * -1;
        sig.one++;
    } else if (signo == 10) {
        if (sig.one == 0) {
            sig.ter_t_pid = info->si_pid;
            sig.one++;
        }
        sig = rec_sig_one(sig);
    }
}

int *new_coords(int *coordinates)
{
    if (sig.one == 1 || sig.one == 2) {
        coordinates[0] = 777;
        coordinates[1] = 0;
        return (coordinates);
    }
    else if (sig.one >= 3 && sig.one < 11) {
        if (sig.one > 0)
            coordinates[0] = sig.one - 3;
    } else if (sig.one >= 11 && sig.one < 19) {
        if (sig.one > 0)
            coordinates[1] = sig.one - 11;
    }
    return (coordinates);
}

int *recieve(int *coordinates)
{
    struct sigaction *sigo = malloc(sizeof(struct sigaction));

    sigemptyset(&sigo->sa_mask);
    sigo->sa_flags = SA_SIGINFO;
    sigo->sa_sigaction = &check_con_par;
    sigaction(SIGUSR1, sigo, NULL);
    sigaction(SIGUSR2, sigo, NULL);
    if (coordinates[2] == 5) {
        sig = hit_rec(sig, coordinates);
        return (coordinates);
    }
    while (sig.one < 19 && sig.one > -19) {
        coordinates = new_coords(coordinates);
        if (coordinates[0] == 777)
            return (coordinates);
    }
    sig.one = 3;
    return (coordinates);
}

int start_game_ter1(int *lives, maps_t *maps, input_t *input)
{
    int *coordinate = malloc(sizeof(int) * 3);

    coordinate[0] = 0;
    coordinate[1] = 0;
    coordinate[2] = 0;
    coordinate = print_con_ter1(coordinate, &sig, maps, input);
    while (lives[0] > 0 && lives[1] > 0) {
        p1_attacks(maps, input, coordinate, lives);
        sender(coordinate[0], coordinate[1], sig.ter_t_pid);
        hits(maps, input, coordinate, lives);
        if (is_alive(lives) == 1 || is_alive(lives) == 0)
            return (is_alive(lives));
        coordinate = defend(maps, input, coordinate, lives);
        if (is_alive(lives) == 1 || is_alive(lives) == 0)
            return (is_alive(lives));
        print_layout(maps);
    }
    if (is_alive(lives) == 1 || is_alive(lives) == 0)
        return (is_alive(lives));
}

int start_game_ter2(int pid, int *lives, maps_t *maps, input_t *input)
{
    int *coordinate = malloc(sizeof(int) * 3);

    coordinate[0] = 0;
    coordinate[1] = 0;
    coordinate[2] = 0;
    coordinate = print_con_ter2(coordinate, pid, maps, input);
    sig.one = 3;
    while (lives[0] > 0 && lives[1] > 0) {
        coordinate = defend(maps, input, coordinate, lives);
        if (is_alive(lives) == 1 || is_alive(lives) == 0)
            return (is_alive(lives));
        p1_attacks(maps, input, coordinate, lives);
        sender(coordinate[0], coordinate[1], sig.ter_t_pid);
        hits(maps, input, coordinate, lives);
        if (is_alive(lives) == 1 || is_alive(lives) == 0)
            return (is_alive(lives));
        print_layout(maps);
    }
    if (is_alive(lives) == 1 || is_alive(lives) == 0)
        return (is_alive(lives));
}