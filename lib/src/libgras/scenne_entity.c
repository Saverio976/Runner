/*
** EPITECH PROJECT, 2021
** LIBGRAPH
** File description:
** create a scenne_entity_t or destroy it
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_gras.h"

static scenne_entity_t *create_scenne_create(window_controler_t *manager,
        int (*create)(scenne_entity_t *, window_controler_t *),
        void (*update)(scenne_entity_t *, window_controler_t *),
        void (*destroy)(scenne_entity_t *, window_controler_t *))
{
    scenne_entity_t *new = malloc(sizeof(scenne_entity_t));

    if (new == NULL)
        return (NULL);
    if (create(new, manager) == 0)
        return (NULL);
    new->create = create;
    new->update = update;
    new->destroy = destroy;
    return (new);
}

int create_scenne(window_controler_t *manager,
        int (*create)(scenne_entity_t *, window_controler_t *),
        void (*update)(scenne_entity_t *, window_controler_t *),
        void (*destroy)(scenne_entity_t *, window_controler_t *))
{
    scenne_entity_t *last = manager->scennes;
    scenne_entity_t *new = create_scenne_create(manager, create, update,
            destroy);

    if (new == NULL)
        return (0);
    if (last == NULL) {
        manager->scennes = new;
        new->next = NULL;
        return (1);
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    new->next = NULL;
    return (1);
}

void destroy_scenne(window_controler_t *manager, scenne_entity_t *scenne)
{
    scenne_entity_t *last = manager->scennes;

    if (last == NULL)
        return;
    while (last != scenne && last->next != scenne)
        last = last->next;
    last->next = scenne->next;
    scenne->destroy(scenne, manager);
    free(scenne);
}
