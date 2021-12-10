/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** header of the strings part
*/

#ifndef MY_STRINGS_H_
    #define MY_STRINGS_H_

// get length of null terminated char **
int my_arraylen(char **);

// char alloc and set all to \0
char *my_calloc(int);

// reverse a nul terminated str
char *my_revstr(char *);

// concat the seconds arg in the first
char *my_strcat(char *, char const *);

// compare two string and do the substrac on each char
int my_strcmp(char const *, char const *);

// copy the second arg in the first
char *my_strcpy(char *, char const *);

// duplicate a null terminated str
char *my_strdup(char const *);

// check if str contains char
int my_strinclude(char const *, char);

// length of null terminated str
int my_strlen(char const *);

// check if the first str starts with the second
int my_strstartswith(char const *, char const *);

#endif
