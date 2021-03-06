/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** get dem numbars
*/

#include "../../include/printf.h"

int my_getnbr(char const *str)
{
    int negative = 0;
    long digit_spot = 1;
    int i = 0;

    if (!str || str[0] == '\0')
        return (-1);
    for (i = 0; str[i] == 45 || str[i] == 43; i++) {
        if (str[i] == 45)
            negative++;
    }
    for (int a = 1; str[a + i] > 47 && str[a + i] < 58; a++)
        digit_spot *= 10;
    if (digit_spot > 1000000000)
        return (-1);
    return (getnbr_result(str, i, negative, digit_spot));
}

int getnbr_result(char const *str, int start, int negative, int digit_spot)
{
    long test_nb = 0;
    int nb = 0;
    long save_nb;

    for (int i = 0; str[i]; i++) {
        if (str[i + start] < '0' || str[i + start] > '9')
            return (-1);
        if (negative % 2 == 0 || negative == 0)
            save_nb = (str[i + start] - 48) * digit_spot;
        else
            save_nb = (str[i + start] - 48) * -1 * digit_spot;
        test_nb += save_nb;
        if (test_nb > 2147483647 || test_nb < -2147483647)
            return (-1);
        digit_spot /= 10;
    }
    nb = (int) test_nb;
    return (nb);
}
