/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** my_atoi
*/

#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
            || *str == '\f' || *str == '\v')
        str++;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;

    while (*str >= '0' && *str <= '9') {
        res = res * 10 + (*str - '0');
        str++;
    }

    return sign * res;
}
