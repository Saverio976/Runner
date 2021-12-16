/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create settings scene
*/

#include "my_gras.h"
#include "my_runner.h"
#include "scenes_settings.h"

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
    create_text(scene, FONT_PATH, (sfVector2f) {10, 5}, switch_map_prev);
    create_text(scene, FONT_PATH, (sfVector2f) {600, 5}, switch_map_next);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 35}, print_current_map);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 70}, switch_bg_prev);
    create_text(scene, FONT_PATH, (sfVector2f) {475, 70}, switch_bg_next);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 100}, print_current_bg);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 135}, switch_music_prev);
    create_text(scene, FONT_PATH, (sfVector2f) {475, 135}, switch_music_next);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 165}, print_current_music);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 200}, switch_spike_prev);
    create_text(scene, FONT_PATH, (sfVector2f) {475, 200}, switch_spike_next);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 230}, print_current_spike);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 265}, switch_ground_prev);
    create_text(scene, FONT_PATH, (sfVector2f) {475, 265}, switch_ground_next);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 295}, print_current_ground);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 330}, switch_player_prev);
    create_text(scene, FONT_PATH, (sfVector2f) {475, 330}, switch_player_next);
    create_text(scene, FONT_PATH, (sfVector2f) {10, 360}, print_current_player);
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
