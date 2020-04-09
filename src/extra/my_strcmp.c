/*
** EPITECH PROJECT, 2019
** strcmp.c
** File description:
** compare dat str
*/
#include "../../include/printf.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if ((int)s1[i] > (int)s2[i] || (s2[i] == '\0' && s1[i] != '\0'))
            return (1);
        if ((int)s1[i] < (int)s2[i] || (s1[i] == '\0' && s2[i] != '\0'))
            return (-1);
    }
    for (i = 0; s1[i] != '\0'; i++);
    for (j = 0; s2[j] != '\0'; j++);
    if (i < j)
        return (-1);
    if (i > j)
        return (1);
    return (0);
}

int my_str_n_cmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] != '\0' && i < n; i++) {
        if ((int)s1[i] > (int)s2[i] || (s2[i] == '\0' && s1[i] != '\0'))
            return (1);
        if ((int)s1[i] < (int)s2[i] || (s1[i] == '\0' && s2[i] != '\0'))
            return (-1);
    }
    return (0);
}