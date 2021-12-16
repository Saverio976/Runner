/*
** EPITECH PROJECT, 2021
** LIBGRAPH
** File description:
** window controller function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_gras.h"

window_controller_t *create(int (*create)(window_controller_t *),
        void (*destroy)(window_controller_t *))
{
    window_controller_t *new = malloc(sizeof(window_controller_t));

    if (new == NULL)
        return (NULL);
    new->current_zindex = -1;
    new->scenes = NULL;
    new->create = create;
    if (create(new) == 0)
        return (NULL);
    new->destroy = destroy;
    return (new);
}

static void end(window_controller_t *manager)
{
    scene_entity_t *curr = manager->scenes;
    scene_entity_t *tmp;

    while (curr != NULL) {
        tmp = curr->next;
        destroy_scene(manager, curr);
        curr = tmp;
    }
    manager->destroy(manager);
    sfRenderWindow_destroy(manager->win);
    free(manager);
}

int start(window_controller_t *manager, char const *title, sfVideoMode mode,
        sfUint32 style)
{
    sfFloatRect rect = {0, 0, 800, 600};
    sfView *view = sfView_createFromRect(rect);
    int ret_code = 0;

    if (manager == NULL)
        return (84);
    if (manager->current_zindex < 0)
        return (84);
    manager->win = sfRenderWindow_create(mode, title, style | sfClose, NULL);
    sfRenderWindow_setView(manager->win, view);
    sfRenderWindow_setFramerateLimit(manager->win, 60);
    ret_code = game_controller(manager);
    end(manager);
    sfView_destroy(view);
    return (ret_code);
}
