/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** intro sequence creation
*/

#include <SFML/Graphics.h>
#include "my_gras.h"
#include "my_runner.h"

int s_create_intro(scenne_entity_t *scenne,
        __attribute__((unused)) window_controler_t *manager)
{
    sfVector2i pos = {0, 0};

    create_picture(scenne, INTRO_BG_PATH, pos, &o_update_intro_background);
    return (1);
}
