/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** tab of map
*/

#ifndef SCENES_SETTINGS_H_
    #define SCENES_SETTINGS_H_

    #include "my_gras.h"

int o_update_settings_music(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_settings_menu(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int o_update_settings_switch(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_map_next(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_map_prev(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int print_current_map(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int print_current_bg(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_bg_prev(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_bg_next(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int print_current_music(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_music_prev(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_music_next(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int print_current_spike(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_spike_prev(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_spike_next(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int print_current_ground(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_ground_prev(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_ground_next(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int print_current_player(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_player_prev(object_entity_t *, scene_entity_t *,
        window_controller_t *);

int switch_player_next(object_entity_t *, scene_entity_t *,
        window_controller_t *);

#endif
