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
    #define MENU_MUSIC_PATH "assets/forever_bound_stereo_madness.ogg"
    #define FONT_PATH "assets/fonts.otf"
    #define PLAY_BUTTON_PATH "assets/play.png"
    #define PARALAX_2_PATH "assets/paralax_2.png"

typedef struct game_runner game_runner_t;
typedef struct game_player game_player_t;

struct game_runner {
    int life;
    sfMusic *music;
    int is_playing;
    int global_sound;
    int speed_paralax_1;
    int speed_paralax_2;
    int speed_paralax_3;
    char const *bg_game;
    char const *map_txt;
    char const *block;
    char const *spike;
    char const *player;
    char const *end;
};

struct game_player {
    sfTexture *texture;
    sfSprite *sprite;
    int gravity;
    sfVector2f pos;
    int buffer_gravity;
    int on_ground;
    sfClock *clock;
};

// ****************************************************************************
// utility
// ****************************************************************************

int create_map_obj_from(game_runner_t *, scenne_entity_t *);

int pass_game_to_menu(window_controler_t *);

int restart_game(scenne_entity_t *, window_controler_t *);

int check_point_in(float, float, sfFloatRect *);

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

// *****************
// SETTINGS

int s_create_settings(scenne_entity_t *, window_controler_t *);

int s_update_settings(scenne_entity_t *, window_controler_t *);

void s_destroy_settings(scenne_entity_t *, window_controler_t *);

// OBJ

int o_update_settings_music(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

int o_update_settings_menu(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

int o_update_settings_switch(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

// *****************
// GAME

int s_create_game(scenne_entity_t *, window_controler_t *);

int s_update_game(scenne_entity_t *, window_controler_t *);

void s_destroy_game(scenne_entity_t *, window_controler_t *);

// OBJ

int o_update_game_background(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

int o_update_game_block(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

int o_update_game_time(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

int o_update_game_paralax_2(object_entity_t *, scenne_entity_t *,
        window_controler_t *);

#endif
