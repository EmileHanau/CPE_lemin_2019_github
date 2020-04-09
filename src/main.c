/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function of lemin
*/

#include "../include/lemin.h"

int main(int argc, char **argv)
{
    t_raw_data *input_data = get_input(argc);
    t_my_graph *data_graph = 0;
    t_solution *solution = 0;

    if (!input_data || !(data_graph = create_data_graph_from_input(input_data)))
        return (84);
    solution = get_solution(data_graph);

    my_printf("*potential output*");
    if (print_solution(solution) == -1)
        return (84);
    return (0);
}