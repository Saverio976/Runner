/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** check if a point is in a suqare
*/

#include <SFML/Graphics.h>

int check_point_in(float px, float py, sfFloatRect *rect)
{
    if (rect->left <= px && px <= rect->left + rect->width &&
            rect->top <= py && py <= rect->top + rect->height)
        return (1);
    return (0);
}
