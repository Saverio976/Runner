/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** intro sequence creation
*/

#include <SFML/Graphics.h>
#include "my_gras.h"
#include "my_runner.h"

int s_update_menu(__attribute__((unused)) scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    return (0);
}

void s_destroy_menu(__attribute__((unused)) scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    return;
}

int s_create_menu(scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    sfVector2f pos_bg = {0, 0};
    sfVector2f pos_settings = {50, 500};
    sfVector2f pos_but = {360, 260};
    sfVector2f pos_status = {400, 20};

    create_picture(scene, INTRO_BG_PATH, pos_bg, &o_update_intro_background);
    create_text(scene, FONT_PATH, pos_settings, &o_update_menu_settings);
    create_picture(scene, PLAY_BUTTON_PATH, pos_but, &o_update_menu_play);
    create_text(scene, FONT_PATH, pos_status, o_update_menu_status);
    return (1);
}
