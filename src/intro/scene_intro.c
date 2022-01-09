/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** intro sequence creation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_gras.h"
#include "my_runner.h"

void *create_icon_and_music(window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *) manager->data;
    sfUint8 const *pixels;
    sfVector2u size;
    intro_runner_t *intro;

    data->icon = sfImage_createFromFile("assets/geometry_glitch.png");
    if (!data->icon)
        return (NULL);
    pixels = sfImage_getPixelsPtr(data->icon);
    size = sfImage_getSize(data->icon);
    sfRenderWindow_setIcon(manager->win, size.x, size.y, pixels);
    intro = malloc(sizeof(intro_runner_t));
    if (!intro)
        return (NULL);
    intro->buff = sfSoundBuffer_createFromFile(INTRO_SOUND);
    intro->sound = sfSound_create();
    if (!(intro->buff) || !(intro->sound))
        return (NULL);
    sfSound_setBuffer(intro->sound, intro->buff);
    return (intro);
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
    intro_runner_t *data = (intro_runner_t *) scene->data;
    sfClock_destroy(scene->clock);
    if (!(scene->data))
        return;
    sfSound_stop(data->sound);
    sfSound_destroy(data->sound);
    sfSoundBuffer_destroy(data->buff);
    free(data);
    return;
}

int s_update_intro(scene_entity_t *scene,
        window_controller_t *manager)
{
    static int frame = 0;

    if (sfTime_asSeconds(sfClock_getElapsedTime(scene->clock)) > 2.0)
        manager->current_zindex = 1;
    if (frame == 0) {
        scene->data = create_icon_and_music(manager);
        if (scene->data != NULL)
            sfSound_play(((intro_runner_t *) scene->data)->sound);
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
