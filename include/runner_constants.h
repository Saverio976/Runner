/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** constants def
*/

#ifndef RUNNER_CONSTANT_H_
    #define RUNNER_CONSTANT_H_

// MACRO

    #define ASSETS_BG_PATH "assets/background/"
static const char INTRO_BG_PATH[] = ASSETS_BG_PATH"intro.png";
static const char SETTINGS_BG_PATH[] = ASSETS_BG_PATH"blue.jpg";
static const char DEFAULT_BG_IMG[] = ASSETS_BG_PATH"blue.jpg";
static const char PARALAX_2_PATH[] = ASSETS_BG_PATH"paralax_2.png";
static const char PARALAX_3_PATH[] = ASSETS_BG_PATH"paralax_2_building.png";
    #define ASSETS_BUMPER_PATH "assets/bumper/"
static const char DEFAULT_JUMP_IMG[] = ASSETS_BUMPER_PATH"bumper.png";
    #define ASSETS_BUTTON_PATH "assets/buttons/"
static const char PLAY_BUTTON_PATH[] = ASSETS_BUTTON_PATH"play.png";
    #define ASSETS_ENDBLOCK_PATH "assets/end_block/"
static const char DEFAULT_END_IMG[] = ASSETS_ENDBLOCK_PATH"end_block.png";
    #define ASSETS_FONTS_PATH "assets/fonts/"
static const char FONT_PATH[] = ASSETS_FONTS_PATH"fonts.otf";
    #define ASSETS_GROUND_PATH "assets/ground/"
static const char DEFAULT_BLOCK_IMG[] = ASSETS_GROUND_PATH"block.png";
    #define ASSETS_MUSIC_PATH "assets/music/"
static const char MENU_MUSIC_PATH[] = ASSETS_MUSIC_PATH
"forever_bound_stereo_madness.ogg";
static const char DEATH_SOUND[] = ASSETS_MUSIC_PATH"death_sound_effect.ogg";
    #define ASSETS_PLAYER_PATH "assets/player/"
static const char DEFAULT_PLAYER_IMG[] = ASSETS_PLAYER_PATH"cubes_1.png";
static const char ICON_EXPLODE[] = ASSETS_PLAYER_PATH"bubes_1_expl.png";
    #define ASSETS_SPIKES_PATH "assets/spikes/"
static const char DEFAULT_SPIKE_IMG[] = ASSETS_SPIKES_PATH"spike.png";

    #define MAX_CHAR_IN_SETTINGS 50

#endif
