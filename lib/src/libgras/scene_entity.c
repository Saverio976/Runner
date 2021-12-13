/*
** EPITECH PROJECT, 2021
** LIBGRAPH
** File description:
** create a scene_entity_t or destroy it
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_gras.h"

static scene_entity_t *create_scene_create(window_controller_t *manager,
        int (*create)(scene_entity_t *, window_controller_t *),
        int (*update)(scene_entity_t *, window_controller_t *),
        void (*destroy)(scene_entity_t *, window_controller_t *))
{
    scene_entity_t *new = malloc(sizeof(scene_entity_t));

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

int create_scene(window_controller_t *manager,
        int (*create)(scene_entity_t *, window_controller_t *),
        int (*update)(scene_entity_t *, window_controller_t *),
        void (*destroy)(scene_entity_t *, window_controller_t *))
{
    scene_entity_t *last = manager->scenes;
    scene_entity_t *new = create_scene_create(manager, create, update,
            destroy);

    if (new == NULL)
        return (0);
    if (last == NULL) {
        manager->scenes = new;
        new->next = NULL;
        new->zindex = 0;
        manager->current_zindex = 0;
        return (1);
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    new->zindex = last->zindex + 1;
    new->next = NULL;
    return (1);
}

void destroy_all_scene_obj(scene_entity_t *scene)
{
    object_entity_t *curr = scene->objects;
    object_entity_t *tmp;

    while (curr != NULL) {
        tmp = curr->next;
        if (curr->type == MUSIC)
            destroy_music(scene, curr);
        if (curr->type == TEXT)
            destroy_text(scene, curr);
        if (curr->type == SPRITE)
            destroy_picture(scene, curr);
        curr = tmp;
    }
}

void destroy_scene(window_controller_t *manager, scene_entity_t *scene)
{
    scene_entity_t *last = manager->scenes;

    if (last == NULL)
        return;
    if (last == scene)
        manager->scenes = scene->next;
    else {
        while (last != NULL && last->next != scene)
            last = last->next;
        if (last == NULL)
            return;
        last->next = scene->next;
    }
    scene->destroy(scene, manager);
    destroy_all_scene_obj(scene);
    free(scene);
}

scene_entity_t *get_current_scene_entity(window_controller_t *manager)
{
    scene_entity_t *curr = manager->scenes;

    if (curr == NULL)
        return (NULL);
    while (curr != NULL && curr->zindex != manager->current_zindex)
        curr = curr->next;
    return (curr);
}
