/*
** EPITECH PROJECT, 2020
** navy.h
** File description:
** h file for navy project
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libmy.h"

typedef struct maps_s {
    char **p1_map;
    char **p2_map;
    char **visible_p1;
    char **visible_p2;
} maps_t;

typedef struct input_s {
    int letter;
    int number;
    int first_input;
    int got_hit;
    int pid;
} input_t;

typedef struct ship_pos_s {
    char **p1_pos;
    char **p2_pos;
} ship_pos_t;

int measure_size(char *);
char *get_buff_p1(char *, int, int);
char *get_buff_p2(char *, int, int);
int str_to_pos(char *, ship_pos_t *);
ship_pos_t init_ship_pos(ship_pos_t);
maps_t init_maps(maps_t);
int fill_map_p1(maps_t *, ship_pos_t *);
void fill_map_p2(maps_t *, ship_pos_t *);
int fill_maps(maps_t *, ship_pos_t *);
int ship_position(ship_pos_t *, char **);
void print_p1(maps_t);
void print_visible_p1(maps_t);
void print_p2(maps_t);
void ship_map(char **, char **);
void get_input(input_t *);
input_t init_input(input_t);
void attacked_p1(maps_t *, input_t *, int *, int *);
int start_game_ter1(int *, maps_t *, input_t *);
int start_game_ter2(int , int *, maps_t *, input_t *);
void p1_attacks(maps_t *, input_t *, int *, int *);
int  read_file(ship_pos_t *, char *);
void print_layout(maps_t *);
void check_if_hit(maps_t *, input_t *, int *, int *);
int *print_con_ter1(int *coordinate, signal_t *, maps_t *, input_t *);
int *print_con_ter2(int *coordinate, int pid, maps_t *, input_t *);
void hits(maps_t *maps, input_t *input, int *coordinate, int *lives);
int *defend(maps_t *maps, input_t *input, int *coordinates, int *lives);
int navy(int, char **);

#endif /* !NAVY_H_ */
