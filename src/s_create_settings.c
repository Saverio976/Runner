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

int s_create_settings(scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    sfVector2f pos_bg = {0, 0};
    sfVector2f pos_menu = {50, 500};
    sfVector2f pos_mus = {500, 500};

    create_picture(scene, INTRO_BG_PATH, pos_bg, o_update_intro_background);
    create_text(scene, FONT_PATH, pos_menu, o_update_settings_menu);
    create_text(scene, FONT_PATH, pos_mus, o_update_settings_music);
    scene->clock = sfClock_create();
    if (!scene->clock)
        return (0);
    return (1);
}
