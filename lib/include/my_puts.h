/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** the put part of libmy
*/

#ifndef MY_PUTS_H_
    #define MY_PUTS_H_

    #include <stdarg.h>

// put format
int my_printf(char const *, ...);

// put char in stdout
int my_putchar(char);

// put int in stdout
int my_putnbr(int);

// put int with base symbols in stdout
int my_putnbr_base(int nb, char const *);

// put str in stdout
int my_putstr(char const *);

// put unsigned int with base symbols in stdout
int my_putunbr_base(unsigned int, char const *);

#endif
