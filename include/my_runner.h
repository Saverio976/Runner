/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** the header project
*/

#ifndef MYRUNNER_H_
    #define MYRUNNER_H_

    #include "runner_constants.h"
    #include "my_gras.h"

typedef struct game_runner game_runner_t;
typedef struct game_player game_player_t;
typedef struct settings settings_t;
typedef struct intro_runner intro_runner_t;

struct intro_runner {
    sfSound *sound;
    sfSoundBuffer *buff;
};

struct settings {
    int global_sound;
    int speed_paralax_1;
    int speed_paralax_2;
    int speed_paralax_3;
    int speed_paralax_4;
    char const *background_img;
    char const *map_path;
    char const *block_img;
    char const *spike_img;
    char const *player_img;
    char const *end_img;
    char const *music_path;
    char const *jump_img;
};

struct game_runner {
    int life;
    sfMusic *music;
    int is_playing;
    settings_t settings;
    int is_win;
    sfImage *icon;
};

struct game_player {
    sfTexture *texture;
    sfSprite *sprite;
    float gravity;
    sfVector2f pos;
    float buffer_gravity;
    int on_ground;
    sfClock *clock;
};

// ****************************************************************************
// utility
// ****************************************************************************

int create_map_obj_from(game_runner_t *, scene_entity_t *);

int pass_game_to_menu(window_controller_t *, int);

int restart_game(scene_entity_t *, window_controller_t *);

int check_point_in(float, float, sfFloatRect *);

int len_calc(char const *);

int print_error(char const *, char const *);

int print_msg(char const *);

int print_help(char const *);

int collision_between(game_player_t *, object_entity_t *);

// ****************************************************************************
// WINDOW_controller
// ****************************************************************************

int w_create_runner(window_controller_t *);

void w_destroy_runner(window_controller_t *);

// ***********************************
// SCENES

// *****************
// INTRO

int s_create_intro(scene_entity_t *, window_controller_t *);

int s_update_intro(scene_entity_t *, window_controller_t *);

void s_destroy_intro(scene_entity_t *, window_controller_t *);

// OBJ

int o_update_intro_background(object_entity_t *, scene_entity_t *,
        window_controller_t *);

// *****************
// MENU

int s_create_menu(scene_entity_t *, window_controller_t *);

int s_update_menu(scene_entity_t *, window_controller_t *);

void s_destroy_menu(scene_entity_t *, window_controller_t *);

// OBJ

int o_update_menu_settings(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_menu_play(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_menu_status(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int draw_explanation(object_entity_t *, scene_entity_t *,
        window_controller_t *);

// *****************
// SETTINGS

int s_create_settings(scene_entity_t *, window_controller_t *);

int s_update_settings(scene_entity_t *, window_controller_t *);

void s_destroy_settings(scene_entity_t *, window_controller_t *);

// *****************
// GAME

int s_create_game(scene_entity_t *, window_controller_t *);

int s_update_game(scene_entity_t *, window_controller_t *);

void s_destroy_game(scene_entity_t *, window_controller_t *);

// OBJ

int o_update_game_background(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_game_block(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_game_time(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_game_paralax_2(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int draw_paralax_3(object_entity_t *, scene_entity_t *,
        window_controller_t *);

// OTHER

int player_update(scene_entity_t *, window_controller_t *);

#endif
