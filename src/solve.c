/*
** EPITECH PROJECT, 2020
** solve.c
** File description:
** solve problem
*/

#include "../include/lemin.h"

int rec_reduce_graph(t_my_graph *graph, int depth)
{
    t_singly_linked_list *adj_copy = 0;

    if (depth == 0)
        return ((t_rooms *) graph->adjacent_vertices->data)->is_end;
    adj_copy = graph->adjacent_vertices;
    for (; adj_copy != 0; adj_copy = adj_copy->next) {
        if (rec_reduce_graph(adj_copy->data, depth - 1)) {
            adj_copy = create_singly_linked_list_from_data(adj_copy->data);
            destructor_list(graph->adjacent_vertices);
            graph->adjacent_vertices = adj_copy;
            return 1;
        }
    }
    return 0;
}

void reduce_graph(t_my_graph *graph)
{
    t_singly_linked_list *adj_ways = create_empty_singly_linked_list();
    t_singly_linked_list *adj_copy = 0;
    int depth = 0;

    while (graph->adjacent_vertices != 0) {
        adj_copy = graph->adjacent_vertices;
        for (; adj_copy != 0; adj_copy = adj_copy->next) {
            if (rec_reduce_graph(graph, depth) == 1) {
                remove_element_by_pointer_from_list(adj_copy, graph->adjacent_vertices);
                append_data_to_list(adj_copy->data, adj_ways);
                ((t_my_graph *) adj_copy->data)->weight = depth;
            }
        }
        depth++;
    }
    graph->adjacent_vertices = adj_ways;
}

t_solution *get_solution(t_my_graph *graph)
{
    t_solution *solution = 0;

    reduce_graph(graph);
    return (solution);
}