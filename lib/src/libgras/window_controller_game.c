/*
** EPITECH PROJECT, 2021
** LIBGRAPH
** File description:
** control the loop game
*/

#include "my_gras.h"

static void check_need_close(window_controler_t *manager)
{
    if (manager->event.type == sfEvtClosed)
        sfRenderWindow_close(manager->win);
}

static int update(scenne_entity_t *curr, window_controler_t *manager)
{
    int ret_code = curr->update(curr, manager);
    object_entity_t *obj = curr->objects;

    while (ret_code == 0 && obj != NULL) {
        ret_code = obj->update(obj, curr, manager);
        obj = obj->next;
    }
    return (ret_code);
}

int game_controller(window_controler_t *manager)
{
    int ret_code = 0;
    scenne_entity_t *curr;

    while (ret_code == 0 && sfRenderWindow_isOpen(manager->win)) {
        sfRenderWindow_clear(manager->win, sfBlack);
        curr = get_current_scenne_entity(manager);
        if (curr == NULL) {
            sfRenderWindow_close(manager->win);
            ret_code = 84;
        } else {
            ret_code = update(curr, manager);
        }
        while (sfRenderWindow_pollEvent(manager->win, &manager->event))
            check_need_close(manager);
        sfRenderWindow_display(manager->win);
    }
    if (ret_code != 0 && sfRenderWindow_isOpen(manager->win))
        sfRenderWindow_close(manager->win);
    return (ret_code);
}
