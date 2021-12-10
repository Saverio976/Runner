/*
** EPITECH PROJECT, 2021
** LIBGRAPH
** File description:
** window controller function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_gras.h"

window_controler_t *create(int (*create)(window_controler_t *),
        void (*destroy)(window_controler_t *))
{
    window_controler_t *new = malloc(sizeof(window_controler_t));

    if (new == NULL)
        return (NULL);
    new->current_zindex = -1;
    new->scennes = NULL;
    new->create = create;
    new->destroy = destroy;
    return (new);
}

static int game_controller(window_controler_t *manager)
{
    manager = manager;
    return (0);
}

static void end(window_controler_t *manager)
{
    scenne_entity_t *curr = manager->scennes;
    scenne_entity_t *tmp;

    while (curr != NULL) {
        tmp = curr->next;
        destroy_scenne(manager, curr);
        curr = tmp;
    }
    manager->destroy(manager);
    sfRenderWindow_destroy(manager->win);
}

int start(window_controler_t *manager, char const *title, sfVideoMode mode,
        sfUint32 style)
{
    int ret_code = 0;

    if (manager == NULL)
        return (84);
    if (manager->current_zindex < 0)
        return (84);
    if (manager->create(manager) == 0)
        return (84);
    manager->win = sfRenderWindow_create(mode, title, style, NULL);
    ret_code = game_controller(manager);
    end(manager);
    return (ret_code);
}
