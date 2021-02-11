/*
** EPITECH PROJECT, 2020
** navy
** File description:
** principal function of navy
*/

#include "libmy.h"
#include "navy.h"

int terminal_one(ship_pos_t ship_pos, input_t input, maps_t maps, int *lives)
{
    int r = 0;

    if (r == 84)
        return (84);
    r = fill_map_p1(&maps, &ship_pos);
    if (r == 84)
        return (84);
    r = start_game_ter1(lives, &maps, &input);
    return (r);
}

int run_game(int ac, maps_t maps, char **av, int *lives)
{
    ship_pos_t ship_pos = init_ship_pos(ship_pos);
    input_t input = init_input(input);
    int r = 0;

    if (ac == 2) {
        r = read_file(&ship_pos, av[1]);
        if (r != 0)
            return (84);
        r = terminal_one(ship_pos, input, maps, lives);
    } else if (ac == 3) {
        r = read_file(&ship_pos, av[2]);
        if (r != 0)
            return (84);
        fill_map_p1(&maps, &ship_pos);
        if (my_str_isnum(av[1]) == 0)
            return (84);
        r = start_game_ter2(my_getnbr(av[1]), lives, &maps, &input);
    }
    return (r);
}

int navy(int ac, char **av)
{
    maps_t maps = init_maps(maps);
    int *lives = malloc(sizeof(int) * 2);
    int r = 0;

    lives[0] = 14;
    lives[1] = 14;
    r = run_game(ac, maps, av, lives);
    if (r == 0) {
        print_layout(&maps);
        my_putstr("\nI won\n");
    } else if (r == 1) {
        print_layout(&maps);
        my_putstr("\nEnemy won\n");
    } else
        return (84);
    return (0);
}