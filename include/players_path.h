/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** define players path
*/

#ifndef PLAYERS_H_
    #define PLAYERS_H_

    #include <stddef.h>
    #include "runner_constants.h"
    #define NUMBER_PLAYERS 5

static const char PLAYERS[NUMBER_PLAYERS][MAX_CHAR_IN_SETTINGS] = {
    "assets/player/cubes_1.png",
    "assets/player/fool.jpg",
    "assets/player/pirate.png",
    "assets/player/pokemon.png",
    "assets/player/rage.png",
};

#endif
