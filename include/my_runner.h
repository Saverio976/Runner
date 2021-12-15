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
    #define DEFAULT_BG_IMG "assets/blue_bg.jpg"
    #define PLAY_BUTTON_PATH "assets/play.png"
    #define PARALAX_2_PATH "assets/paralax_2.png"
    #define DEFAULT_BLOCK_IMG "assets/block.png"
    #define DEFAULT_SPIKE_IMG "assets/spike.png"
    #define DEFAULT_MAP_PATH "map/42.txt"
    #define DEFAULT_PLAYER_IMG "assets/cubes_1.png"
    #define DEFAULT_END_IMG "assets/end_block.png"

typedef struct game_runner game_runner_t;
typedef struct game_player game_player_t;
typedef struct settings settings_t;

struct settings {
    int global_sound;
    int speed_paralax_1;
    int speed_paralax_2;
    int speed_paralax_3;
    char const *background_img;
    char const *map_path;
    char const *block_img;
    char const *spike_img;
    char const *player_img;
    char const *end_img;
};

struct game_runner {
    int life;
    sfMusic *music;
    int is_playing;
    settings_t settings;
    int is_win;
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

int create_map_obj_from(game_runner_t *, scene_entity_t *);

int pass_game_to_menu(window_controller_t *, int);

int restart_game(scene_entity_t *, window_controller_t *);

int check_point_in(float, float, sfFloatRect *);

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

// *****************
// SETTINGS

int s_create_settings(scene_entity_t *, window_controller_t *);

int s_update_settings(scene_entity_t *, window_controller_t *);

void s_destroy_settings(scene_entity_t *, window_controller_t *);

// OBJ

int o_update_settings_music(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_settings_menu(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_settings_switch(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_map_next(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_map_prev(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int print_current_map(object_entity_t *, scene_entity_t *,
        window_controller_t *);

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

// OTHER

int player_update(scene_entity_t *, window_controller_t *);

#endif
