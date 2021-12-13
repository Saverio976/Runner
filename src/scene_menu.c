/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** intro sequence creation
*/

#include <SFML/Graphics.h>
#include "my_gras.h"
#include "my_runner.h"

int s_update_menu(__attribute__((unused)) scenne_entity_t *scenne,
        __attribute__((unused)) window_controler_t *manager)
{
    return (0);
}

void s_destroy_menu(__attribute__((unused)) scenne_entity_t *scenne,
        __attribute__((unused)) window_controler_t *manager)
{
    return;
}

int s_create_menu(scenne_entity_t *scenne,
        __attribute__((unused)) window_controler_t *manager)
{
    sfVector2f pos_bg = {0, 0};
    sfVector2f pos_settings = {50, 500};
    sfVector2f pos_but = {360, 260};

    create_picture(scenne, INTRO_BG_PATH, pos_bg, &o_update_intro_background);
    create_text(scenne, FONT_PATH, pos_settings, &o_update_menu_settings);
    create_picture(scenne, PLAY_BUTTON_PATH, pos_but, &o_update_menu_play);
    return (1);
}
