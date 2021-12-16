/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create settings scene
*/

#include "my_gras.h"
#include "my_runner.h"

int s_update_settings(__attribute__((unused)) scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    return (0);
}

void s_destroy_settings(__attribute__((unused)) scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    sfClock_destroy(scene->clock);
}

static void add_settings_button(scene_entity_t *scene)
{
    sfVector2f pos_prev_map = {10, 5};
    sfVector2f pos_next_map = {600, 5};
    sfVector2f pos_current_map = {10, 35};
    sfVector2f pos_prev_bg = {10, 70};
    sfVector2f pos_next_bg = {475, 70};
    sfVector2f pos_current_bg = {10, 100};
    sfVector2f pos_prev_music = {10, 135};
    sfVector2f pos_next_music = {475, 135};
    sfVector2f pos_current_music = {10, 165};


    create_text(scene, FONT_PATH, pos_prev_map, switch_map_prev);
    create_text(scene, FONT_PATH, pos_next_map, switch_map_next);
    create_text(scene, FONT_PATH, pos_current_map, print_current_map);
    create_text(scene, FONT_PATH, pos_prev_bg, switch_bg_prev);
    create_text(scene, FONT_PATH, pos_next_bg, switch_bg_next);
    create_text(scene, FONT_PATH, pos_current_bg, print_current_bg);
    create_text(scene, FONT_PATH, pos_prev_music, switch_music_prev);
    create_text(scene, FONT_PATH, pos_next_music, switch_music_next);
    create_text(scene, FONT_PATH, pos_current_music, print_current_music);
}

int s_create_settings(scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    sfVector2f pos_bg = {0, 0};
    sfVector2f pos_menu = {50, 500};
    sfVector2f pos_mus = {500, 500};

    create_picture(scene, SETTINGS_BG_PATH, pos_bg, o_update_intro_background);
    create_text(scene, FONT_PATH, pos_menu, o_update_settings_menu);
    create_text(scene, FONT_PATH, pos_mus, o_update_settings_music);
    add_settings_button(scene);
    scene->clock = sfClock_create();
    if (!scene->clock)
        return (0);
    return (1);
}
