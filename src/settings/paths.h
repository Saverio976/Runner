/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** tab of map
*/

#ifndef MAPS_H_
    #define MAPS_H_

    #include <stddef.h>

static const int NUMBER_MAPS = 7;

static const char *MAPS[] = {
    "map/42.txt",
    "map/basic.txt",
    "map/some_tricky.txt",
    "map/matthieu.txt",
    "map/UwU.txt",
    "map/xddl.txt",
    "map/test.txt",
    NULL
};

static const int NUMBER_BACKGS = 3;

static const char *BACKGROUNDS[] = {
    "assets/background/blue.jpg",
    "assets/background/blue_sky.png",
    "assets/background/orange.png",
    NULL
};

static const int NUMBER_MUSICS = 2;

static const char *MUSICS[] = {
    "assets/music/djvi_base_after_base.ogg",
    "assets/music/forever_bound_stereo_madness.ogg",
    NULL
};

#endif
