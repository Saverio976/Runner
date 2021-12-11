/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** the header project
*/

#ifndef MYRUNNER_H_
    #define MYRUNNER_H_

    #include "my_gras.h"

// MACRO

    #define INTRO_BG_PATH "assets/background_intro.png"
    #define MENU_MUSIC_PATH "assets/forever_bound_stereo_madness.flac"
    #define FONT_PATH "assets/fonts.otf"
    #define PLAY_BUTTON_PATH "assets/play.png"

typedef struct game_runner game_runner_t;

struct game_runner {
    int life;
    sfMusic *music;
    int is_playing;
};

// ****************************************************************************
// WINDOW_CONTROLER
// ****************************************************************************

int w_create_runner(window_controler_t *);

void w_destroy_runner(window_controler_t *);

// ***********************************
// SCENNES

// *****************
// INTRO

int s_create_intro(scenne_entity_t *, window_controler_t *);

int s_update_intro(scenne_entity_t *, window_controler_t *);

void s_destroy_intro(scenne_entity_t *, window_controler_t *);

// OBJ

int o_update_intro_background(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

// *****************
// MENU

int s_create_menu(scenne_entity_t *, window_controler_t *);

int s_update_menu(scenne_entity_t *, window_controler_t *);

void s_destroy_menu(scenne_entity_t *, window_controler_t *);

// OBJ

int o_update_menu_settings(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

int o_update_menu_play(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

#endif
