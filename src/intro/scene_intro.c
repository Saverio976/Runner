/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** intro sequence creation
*/

#include <SFML/Graphics.h>
#include "my_gras.h"
#include "my_runner.h"

void create_icon(window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *) manager->data;
    sfUint8 const *pixels;
    sfVector2u size;

    data->icon = sfImage_createFromFile("assets/geometry_glitch.png");
    if (!data->icon)
        return;
    pixels = sfImage_getPixelsPtr(data->icon);
    size = sfImage_getSize(data->icon);
    sfRenderWindow_setIcon(manager->win, size.x, size.y, pixels);
}

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
    static int frame = 0;

    if (sfTime_asSeconds(sfClock_getElapsedTime(scene->clock)) > 2.0)
        manager->current_zindex = 1;
    if (frame == 0) {
        create_icon(manager);
        sfRenderWindow_requestFocus(manager->win);
        sfRenderWindow_setVerticalSyncEnabled(manager->win, sfFalse);
        frame++;
    }
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
