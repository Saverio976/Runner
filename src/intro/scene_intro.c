/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** intro sequence creation
*/

#include <SFML/Graphics.h>
#include "my_gras.h"
#include "my_runner.h"

int o_update_intro_background(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    sfRenderWindow_drawSprite(manager->win, obj->sprite, NULL);
    return (0);
}

void s_destroy_intro(scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    sfClock_destroy(scene->clock);
    return;
}

int s_update_intro(scene_entity_t *scene,
        window_controller_t *manager)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(scene->clock)) > 2.0)
        manager->current_zindex = 1;
    return (0);
}

int s_create_intro(scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    sfVector2f pos = {0.0, 0.0};

    create_picture(scene, INTRO_BG_PATH, pos, o_update_intro_background);
    scene->clock = sfClock_create();
    if (scene->clock == NULL)
        return (0);
    return (1);
}
