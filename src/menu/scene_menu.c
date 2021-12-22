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
    static int status = 0;

    if (sfTime_asSeconds(sfClock_getElapsedTime(manager->clock)) < 0.5)
        return (0);
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        status = !status;
        sfRenderWindow_setVerticalSyncEnabled(manager->win, (status) ? sfTrue :
                sfFalse);
        sfClock_restart(manager->clock);
    }
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
    sfVector2f pos_status = {250, 180};
    sfVector2f pos_explanation = {250, 500};

    create_picture(scene, INTRO_BG_PATH, pos_bg, &o_update_intro_background);
    create_text(scene, FONT_PATH, pos_settings, &o_update_menu_settings);
    create_picture(scene, PLAY_BUTTON_PATH, pos_but, &o_update_menu_play);
    create_text(scene, FONT_PATH, pos_status, o_update_menu_status);
    create_text(scene, FONT_PATH, pos_explanation, draw_explanation);
    return (1);
}
