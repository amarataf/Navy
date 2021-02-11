/*
** EPITECH PROJECT, 2020
** ship_position
** File description:
** put the position of the ships in the map
*/

#include "navy.h"

int check_line(char *s)
{
    if (s[0] < '2' || s[0] > '5')
        return (84);
    if (s[1] != ':' || s[4] != ':')
        return (84);
    if (s[2] < 'A' || s[2] > 'H' || s[5] < 'A' || s[5] > 'H')
        return (84);
    if (s[3] < '1' || s[3] > '8' || s[6] < '1' || s[6] > '8')
        return (84);
    return (0);
}

int check_file(char *str)
{
    char **arr = my_str_to_word_array(str);
    int i = 0;

    if (str[my_strlen(str) - 1] != '\n' || arr == NULL)
        return (84);
    while (arr[i] != NULL) {
        i++;
    }
    if (i != 4)
        return (84);
    i = 0;
    while (arr[i] != NULL) {
        if (my_strlen(arr[i]) != 7)
            return (84);
        if (check_line(arr[i++]) != 0)
            return (84);
    }
    return (0);
}

int ship_position(ship_pos_t *ship_pos, char **buff1)
{
    int k = 2;
    int i = 0;
    int j = 0;

    if (check_file(*buff1) != 0)
        return (84);
    while (i < 4) {
        while (j <= 2) {
            ship_pos->p1_pos[i][j] = (*buff1)[k];
            ship_pos->p1_pos[i][j + 1] = (*buff1)[k + 1];
            j += 2;
            k += 3;
        }
        j = 0;
        k += 2;
        i++;
    }
    return (0);
}