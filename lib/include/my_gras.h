/*
** EPITECH PROJECT, 2021
** LLIBGRAPH
** File description:
** abstract csfml
*/

#ifndef LIBGRAS_H_
    #define LIBGRAS_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct window_controller window_controller_t;
typedef struct scene_entity scene_entity_t;
typedef struct object_entity object_entity_t;

enum object_entity_type {
    MUSIC,
    TEXT,
    SPRITE
};

struct object_entity {
    enum object_entity_type type;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfFont *font;
    sfMusic *music;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock;
    int object_is_visible;
    int music_is_looping;
    int music_is_playing;
    int (*update)(object_entity_t *, scene_entity_t *, window_controller_t *);
    object_entity_t *next;
    void *data;
};

struct scene_entity {
    int zindex;
    struct scene_entity *next;
    int (*create)(scene_entity_t *, window_controller_t *);
    int (*update)(scene_entity_t *, window_controller_t *);
    void (*destroy)(scene_entity_t *, window_controller_t *);
    sfRenderWindow *win;
    sfClock *clock;
    object_entity_t *objects;
    void *data;
};

struct window_controller {
    int current_zindex;
    scene_entity_t *scenes;
    sfRenderWindow *win;
    sfEvent event;
    sfClock *clock;
    void *data;
    int (*create)(window_controller_t *);
    void (*destroy)(window_controller_t *);
};

// ****************************************************************************
// OBJECT_ENTITY_T
// ****************************************************************************

// ***********************************
// MUSIC

/*
** create_music
** create a music object
** scene_entity_t *: the scene to attatch the object
** char const *: path to the music
** int: music need to be playing now ?
** void (*)(..): the update funtion to call at each frame
*/
int create_music(scene_entity_t *, char const *, int,
        int (*)(object_entity_t *, scene_entity_t *, window_controller_t *));

/*
** destroy_music
** destroy a music object
** scene_entity_t *: the scene that have the object
** object_entity_t *: the music to destroy
*/
int destroy_music(scene_entity_t *, object_entity_t *);

// ***********************************
// PICTURE / SPRITE

/*
** create_picture
** create a picture object
** scene_entity_t *: the scene to attatch the object
** char const *: path to the texture img
** sfVector2i: the position of this sprite
** void (*)(..): the update funtion to call at each frame
*/
int create_picture(scene_entity_t *, char const *, sfVector2f,
        int (*)(object_entity_t *, scene_entity_t *, window_controller_t *));

/* destroy_picture
** destroy a sprite object
** scene_entity_t *: the scene that have the object
** object_entity_t *: the music to destroy
*/
int destroy_picture(scene_entity_t *, object_entity_t *);

// ***********************************
// TEXT

/*
** create_text
** create a text object
** scene_entity_t *: the scene to attach the object
** char const *path: the path of the font
** sfVector2f: position of the text
** void (*)(..): the update function call each frame
*/
int create_text(scene_entity_t *, char const *, sfVector2f,
        int (*)(object_entity_t *, scene_entity_t *, window_controller_t *));

/*
** destroy_text
** destroy a text object
** scene_entity_t *: the scene to destroy the object
** object_entity_t *: the obj to destroy
*/
int destroy_text(scene_entity_t *, object_entity_t *);

// ****************************************************************************
// scene_ENTITY_T
// ****************************************************************************

/*
** create_scene
** create a scene in a window controller
** window_controller_t *: the main window
** int (*)(..): the function called to create the scene
** void (*)(..): the function called at each frame
** void (*)(..): the function called at the end
*/
int create_scene(window_controller_t *,
        int (*)(scene_entity_t *, window_controller_t *),
        int (*)(scene_entity_t *, window_controller_t *),
        void (*)(scene_entity_t *, window_controller_t *));

/*
** destroy_all_scene_obj
** destroy all scene obj of a scene
** scene_entity_t *: the scene
*/
void destroy_all_scene_obj(scene_entity_t *);

/*
** destroy_scene
** destroy a scene entity in a window controller
** window_controller_t *: the window controller
** scene_entity_t *: the scene to destroy
*/
void destroy_scene(window_controller_t *, scene_entity_t *);

/*
** get_current_scene_entity
** get the current scene
** window_controller_t *: the window controller
*/
scene_entity_t *get_current_scene_entity(window_controller_t *);

// ****************************************************************************
// WINDOW_controller_T
// ****************************************************************************

/*
** create
** create a window manager
** int (*)(..): function executed before window start
** void (*)(..): function executed at the end
*/
window_controller_t *create(int (*)(window_controller_t *),
        void (*)(window_controller_t *));

/*
** start
** start the game/scenes
** window_controller_t *: the window created by create()
** char const *: the window title
** sfVideoMode: width, height bpp (see csfml doc for more details)
** sfUint32: style of teh window (sfResize / sfFulScreen ..)
*/
int start(window_controller_t *, char const *, sfVideoMode,
        sfUint32);

// dont use it
int game_controller(window_controller_t *);

#endif
