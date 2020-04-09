/*
** EPITECH PROJECT, 2020
** cut_string.c
** File description:
** cuts strings
*/

#include "../../include/printf.h"

char *cut_string(char *str, int beginning, int end, int cut)
{
    char *cut_string;
    int size = 0;
    int d = 0;

    for (; str[size] != '\0'; size++);
    if (cut >= size)
        return (str);
    if (!(cut_string = malloc(sizeof(char) * size + 1)))
        exit(84);
    for (int i = beginning;
        (i < end || end == 0) && str[i + cut] != '\0'; i++) {
        cut_string[d] = str[i];
        d++;
    }
    cut_string[d] = '\0';
    return (cut_string);
}

char *cut_given_char_and_everything_before(char *str, char cut)
{
    char *cut_string;
    int size = 0;
    int d = 0;
    int i = 0;

    for (; str[size] != '\0'; size++);
    if (!(cut_string = malloc(sizeof(char) * size + 1)))
        exit(84);
    for (; str[i] != cut && str[i] != '\0'; i++);
    if (str[i] == cut)
        i++;
    else
        return (str);
    for (; str[i] != '\0'; i++) {
        cut_string[d] = str[i];
        d++;
    }
    cut_string[d] = '\0';
    return (cut_string);
}

char *cut_given_char_and_everything_after(char *str, char cut)
{
    char *cut_string;
    int size = 0;
    int d = 0;
    int i = 0;

    if (str == NULL)
        return (NULL);
    for (; str[size] != '\0'; size++);
    if (!(cut_string = malloc(sizeof(char) * size + 1)))
        exit(84);
    for (; str[i] != '\0' && str[i] != cut; i++) {
        cut_string[d] = str[i];
        d++;
    }
    cut_string[d] = '\0';
    return (cut_string);
}
