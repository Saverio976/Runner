/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** all elements for an object entity of text type
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_gras.h"

static void *destroy_error(object_entity_t *obj, int first, int second)
{
    if (obj == NULL)
        return (NULL);
    if (first) {
        sfFont_destroy(obj->font);
        obj->font = NULL;
    }
    if (second) {
        sfText_destroy(obj->text);
        obj->text = NULL;
    }
    free(obj);
    return (NULL);
}

static object_entity_t *create_text_create(char const *path, sfVector2f pos,
        int (*update_ptr)(object_entity_t *, scenne_entity_t *,
            window_controler_t *))
{
    object_entity_t *new = malloc(sizeof(object_entity_t));

    if (new == NULL)
        return (NULL);
    new->type = TEXT;
    new->font = sfFont_createFromFile(path);
    if (new->font == NULL)
        return (destroy_error(new, 0, 0));
    new->text = sfText_create();
    if (new->text == NULL)
        return (destroy_error(new, 1, 0));
    sfText_setFont(new->text, new->font);
    sfText_setPosition(new->text, pos);
    new->pos = pos;
    new->update = update_ptr;
    new->object_is_visible = 0;
    new->next = NULL;
    return (new);
}

int create_text(scenne_entity_t *scene, char const *path,
        sfVector2f pos,
        int (*update_ptr)(object_entity_t *, scenne_entity_t *,
            window_controler_t *))
{
    object_entity_t *cursor = scene->objects;
    object_entity_t *new = create_text_create(path, pos, update_ptr);

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

int destroy_text(scenne_entity_t *scene, object_entity_t *obj)
{
    object_entity_t *last = scene->objects;

    if (obj->type != TEXT || last == NULL)
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
