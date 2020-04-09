/*
** EPITECH PROJECT, 2020
** solve.c
** File description:
** solve problem
*/

#include "../include/lemin.h"

int rec_reduce_graph(t_my_graph *graph, int depth, int travelled_distance, t_singly_linked_list *graph_list)
{
    t_singly_linked_list *adj_copy = graph->adjacent_vertices;

    if (depth == 0) {
        if (graph->blocked == 0) {
            graph->blocked = travelled_distance;
            return 0;
        }
        else
            return 1;
    }
    for (; adj_copy != 0; adj_copy = adj_copy->next) {
        if (rec_reduce_graph((t_my_graph *) adj_copy->data, depth - 1, \
travelled_distance + 1, graph_list) == 1 && ((t_rooms *) graph->curr_vertex)->is_start != 1) {
            remove_element_by_pointer_from_list(adj_copy, graph->adjacent_vertices);

    }
}

void reduce_graph(t_my_graph *graph, t_singly_linked_list *graph_list)
{
    int end = 0;
    int depth = 1;

    while (!end) {
        end = rec_reduce_graph(graph, depth, 0, graph_list);
        depth++;
    }
}

t_solution *get_solution(t_my_graph *graph)
{
    t_solution *solution = 0;

    reduce_graph(graph);
    return (solution);
}