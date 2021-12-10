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
        int (*update)(scenne_entity_t *, window_controler_t *),
        void (*destroy)(scenne_entity_t *, window_controler_t *))
{
    scenne_entity_t *new = malloc(sizeof(scenne_entity_t));

    if (new == NULL)
        return (NULL);
    new->objects = NULL;
    if (create(new, manager) == 0)
        return (NULL);
    new->create = create;
    new->update = update;
    new->destroy = destroy;
    return (new);
}

int create_scenne(window_controler_t *manager,
        int (*create)(scenne_entity_t *, window_controler_t *),
        int (*update)(scenne_entity_t *, window_controler_t *),
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

static void destroy_all_scenne_obj(scenne_entity_t *scenne)
{
    object_entity_t *curr = scenne->objects;
    object_entity_t *tmp;

    while (curr != NULL) {
        tmp = curr->next;
        if (curr->type == MUSIC)
            destroy_music(scenne, curr);
        if (curr->type == TEXT)
            destroy_text(scenne, curr);
        if (curr->type == SPRITE)
            destroy_picture(scenne, curr);
        curr = tmp;
    }
}

void destroy_scenne(window_controler_t *manager, scenne_entity_t *scenne)
{
    scenne_entity_t *last = manager->scennes;

    if (last == NULL)
        return;
    if (last == scenne)
        manager->scennes = scenne->next;
    else {
        while (last != NULL && last->next != scenne)
            last = last->next;
        if (last == NULL)
            return;
        last->next = scenne->next;
    }
    scenne->destroy(scenne, manager);
    destroy_all_scenne_obj(scenne);
    free(scenne);
}

scenne_entity_t *get_current_scenne_entity(window_controler_t *manager)
{
    scenne_entity_t *curr = manager->scennes;

    if (curr == NULL)
        return (NULL);
    while (curr != NULL && curr->zindex != manager->current_zindex)
        curr = curr->next;
    return (curr);
}
