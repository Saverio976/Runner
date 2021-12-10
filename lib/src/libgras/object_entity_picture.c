/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** all elements for an object entity of sprite type
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_gras.h"

static void *destroy_error(object_entity_t *obj, int first, int second)
{
    if (obj == NULL)
        return (NULL);
    if (first) {
        sfSprite_destroy(obj->sprite);
        obj->sprite = NULL;
    }
    if (second) {
        sfTexture_destroy(obj->texture);
        obj->texture = NULL;
    }
    free(obj);
    return (NULL);
}

static object_entity_t *create_picture_create(char const *path, sfVector2i pos,
        int (*update_ptr)(object_entity_t *, scenne_entity_t *,
            window_controler_t *))
{
    object_entity_t *new = malloc(sizeof(object_entity_t));

    if (new == NULL)
        return (NULL);
    new->type = SPRITE;
    new->texture = sfTexture_createFromFile(path, NULL);
    if (new->texture == NULL)
        return (destroy_error(new, 0, 0));
    new->sprite = sfSprite_create();
    if (new->sprite == NULL)
        return (destroy_error(new, 0, 1));
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos = pos;
    new->update = update_ptr;
    new->object_is_visible = 0;
    return (new);
}

int create_picture(scenne_entity_t *scene, char const *path,
        sfVector2i pos,
        int (*update_ptr)(object_entity_t *, scenne_entity_t *,
            window_controler_t *))
{
    object_entity_t *cursor = scene->objects;
    object_entity_t *new = create_picture_create(path, pos, update_ptr);

    if (new == NULL)
        return (0);
    if (cursor == NULL) {
        scene->objects = new;
        new->next = NULL;
        return (1);
    }
    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = new;
    return (1);
}

int destroy_picture(scenne_entity_t *scene, object_entity_t *obj)
{
    object_entity_t *last = scene->objects;

    if (obj->type != SPRITE || last == NULL)
        return (0);
    if (last == obj)
        scene->objects = obj->next;
    else {
        while (last != NULL && last->next != obj)
            last = last->next;
        if (last == NULL)
            return (0);
        last->next = obj->next;
    }
    destroy_error(obj, 1, 1);
    return (1);
}
