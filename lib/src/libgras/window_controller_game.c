/*
** EPITECH PROJECT, 2021
** LIBGRAPH
** File description:
** control the loop game
*/

#include "my_gras.h"

static void check_event(window_controller_t *manager, int *is_pause)
{
    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->win);
    if (manager->event.type == sfEvtKeyPressed &&
            manager->event.key.code == sfKeyPause) {
        *is_pause *= -1;
    }
    if (manager->event.type == sfEvtKeyPressed &&
            manager->event.key.code == sfKeyEscape)
        sfRenderWindow_close(manager->win);
}

static int update(scene_entity_t *curr, window_controller_t *manager)
{
    int ret_code = 0;
    object_entity_t *obj = curr->objects;

    while (ret_code == 0 && obj != NULL) {
        ret_code = obj->update(obj, curr, manager);
        obj = obj->next;
    }
    ret_code = (ret_code == 0) ? curr->update(curr, manager) : ret_code;
    return (ret_code);
}

static int game_loop(window_controller_t *manager, sfClock *clock)
{
    scene_entity_t *curr;
    int ret_code = 0;
    static int is_pause = -1;

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) < 1.0 / 120.0)
        return (0);
    if (is_pause == -1) {
        sfRenderWindow_clear(manager->win, sfBlack);
        curr = get_current_scene_entity(manager);
        if (curr == NULL)
            ret_code = 84;
        else
            ret_code = update(curr, manager);
    }
    while (sfRenderWindow_pollEvent(manager->win, &manager->event))
        check_event(manager, &is_pause);
    sfClock_restart(clock);
    return (ret_code);
}

int game_controller(window_controller_t *manager)
{
    int ret_code = 0;
    sfClock *clock = sfClock_create();

    if (!clock)
        return (84);
    while (ret_code == 0 && sfRenderWindow_isOpen(manager->win)) {
        game_loop(manager, clock);
        sfRenderWindow_display(manager->win);
    }
    if (ret_code != 0 && sfRenderWindow_isOpen(manager->win))
        sfRenderWindow_close(manager->win);
    sfClock_destroy(clock);
    return (ret_code);
}
