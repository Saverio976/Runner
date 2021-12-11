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

typedef struct window_controler window_controler_t;
typedef struct scenne_entity scenne_entity_t;
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
    int (*update)(object_entity_t *, scenne_entity_t *, window_controler_t *);
    object_entity_t *next;
    void *data;
};

struct scenne_entity {
    int zindex;
    struct scenne_entity *next;
    int (*create)(scenne_entity_t *, window_controler_t *);
    int (*update)(scenne_entity_t *, window_controler_t *);
    void (*destroy)(scenne_entity_t *, window_controler_t *);
    sfRenderWindow *win;
    sfClock *clock;
    object_entity_t *objects;
    void *data;
};

struct window_controler {
    int current_zindex;
    scenne_entity_t *scennes;
    sfRenderWindow *win;
    sfEvent event;
    sfClock *clock;
    void *data;
    int (*create)(window_controler_t *);
    void (*destroy)(window_controler_t *);
};

// ****************************************************************************
// OBJECT_ENTITY_T
// ****************************************************************************

// ***********************************
// MUSIC

/*
** create_music
** create a music object
** scenne_entity_t *: the scene to attatch the object
** char const *: path to the music
** int: music need to be playing now ?
** void (*)(..): the update funtion to call at each frame
*/
int create_music(scenne_entity_t *, char const *, int,
        int (*)(object_entity_t *, scenne_entity_t *, window_controler_t *));

/* destroy_music
** destroy a music object
** scenne_entity_t *: the scene that have the object
** object_entity_t *: the music to destroy
*/
int destroy_music(scenne_entity_t *, object_entity_t *);

// ***********************************
// PICTURE / SPRITE

/*
** create_picture
** create a picture object
** scenne_entity_t *: the scene to attatch the object
** char const *: path to the texture img
** sfVector2i: the position of this sprite
** void (*)(..): the update funtion to call at each frame
*/
int create_picture(scenne_entity_t *, char const *, sfVector2f,
        int (*)(object_entity_t *, scenne_entity_t *, window_controler_t *));

/* destroy_picture
** destroy a sprite object
** scenne_entity_t *: the scene that have the object
** object_entity_t *: the music to destroy
*/
int destroy_picture(scenne_entity_t *, object_entity_t *);

// ***********************************
// TEXT

/*
** create_text
** create a text object
** scenne_entity_t *: the scenne to attach the object
** char const *path: the path of the font
** sfVector2f: position of the text
** void (*)(..): the update function call each frame
*/
int create_text(scenne_entity_t *, char const *, sfVector2f,
        int (*)(object_entity_t *, scenne_entity_t *, window_controler_t *));

/*
** destroy_text
** destroy a text object
** scenne_entity_t *: the scenne to destroy the object
** object_entity_t *: the obj to destroy
*/
int destroy_text(scenne_entity_t *, object_entity_t *);

// ****************************************************************************
// SCENNE_ENTITY_T
// ****************************************************************************

/*
** create_scenne
** create a scenne in a window controler
** window_controler_t *: the main window
** int (*)(..): the function called to create the scenne
** void (*)(..): the function called at each frame
** void (*)(..): the function called at the end
*/
int create_scenne(window_controler_t *,
        int (*)(scenne_entity_t *, window_controler_t *),
        int (*)(scenne_entity_t *, window_controler_t *),
        void (*)(scenne_entity_t *, window_controler_t *));

/*
** destroy_scenne
** destroy a scenne entity in a window controler
** window_controler_t *: the window controler
** scenne_entity_t *: the scenne to destroy
*/
void destroy_scenne(window_controler_t *, scenne_entity_t *);

/*
** get_current_scenne_entity
** get the current scene
** window_controler_t *: the window controler
*/
scenne_entity_t *get_current_scenne_entity(window_controler_t *);

// ****************************************************************************
// WINDOW_CONTROLER_T
// ****************************************************************************

/*
** create
** create a window manager
** int (*)(..): function executed before window start
** void (*)(..): function executed at the end
*/
window_controler_t *create(int (*)(window_controler_t *),
        void (*)(window_controler_t *));

/*
** start
** start the game/scennes
** window_controler_t *: the window created by create()
** char const *: the window title
** sfVideoMode: width, height bpp (see csfml doc for more details)
** sfUint32: style of teh window (sfResize / sfFulScreen ..)
*/
int start(window_controler_t *, char const *, sfVideoMode,
        sfUint32);

// dont use it
int game_controller(window_controler_t *);

#endif
