/*
** EPITECH PROJECT, 2020
** graph_handling.c
** File description:
** handles graph
*/

#include "../include/lemin.h"

void delete_vertex_from_graph(t_my_graph *vertex_to_remove, \
t_singly_linked_list *vertex_list)
{
    t_singly_linked_list *adj_copy = 0;

    for (; vertex_list != 0; vertex_list = vertex_list->next) {
        adj_copy = ((t_my_graph *) vertex_list->data)->adjacent_vertices;
        for (; adj_copy != 0; adj_copy = adj_copy->next)
            if (adj_copy->data == vertex_to_remove)
                ((t_my_graph *) vertex_list->data)->adjacent_vertices = \
remove_element_by_pointer_from_list(adj_copy, \
((t_my_graph *) vertex_list->data)->adjacent_vertices);
    }
}

t_my_graph *get_start_edge(t_singly_linked_list *graph_list)
{
    for (; graph_list != 0; graph_list = graph_list->next)
        if (((t_rooms *) ((t_my_graph *) \
graph_list->data)->curr_vertex)->is_start == 1)
            return (t_my_graph *) graph_list->data;
    return 0;
}

t_singly_linked_list *create_data_graph_from_input(t_raw_data *input_data)
{
    t_my_graph *graph = 0;
    t_tunnel *tmp_tunnels = (t_tunnel *) input_data->tunnel;
    t_singly_linked_list *tmp_vertex_list = 0;
    t_singly_linked_list *tmp_vertex_list_copy = 0;
    t_singly_linked_list *tmp_vertex_list_copy_2 = 0;
    t_singly_linked_list *tmp_list_adj = 0;

    for (; input_data->rooms != 0; \
input_data->rooms = input_data->rooms->next) {
        graph = malloc(sizeof(t_my_graph));
        graph->curr_vertex = input_data->rooms->data;
        graph->adjacent_vertices = 0;
        tmp_vertex_list = append_data_to_list(graph, tmp_vertex_list);
    }
    tmp_vertex_list_copy = tmp_vertex_list;
    for (; tmp_vertex_list != 0; tmp_vertex_list = tmp_vertex_list->next) {
        input_data->tunnel = (void *) tmp_tunnels;
        fill_adjescent_vertices(input_data, tmp_vertex_list, \
tmp_vertex_list_copy, tmp_vertex_list_copy_2);
    }
    tmp_vertex_list = tmp_vertex_list_copy;
    remove_self_ref_edges(tmp_vertex_list_copy, tmp_list_adj);
    return tmp_vertex_list;
}

void remove_self_ref_edges(t_singly_linked_list *tmp_vertex_list_copy, \
t_singly_linked_list *tmp_list_adj)
{
    for (; tmp_vertex_list_copy != 0; tmp_vertex_list_copy = \
tmp_vertex_list_copy->next) {
        tmp_list_adj = \
((t_my_graph *)tmp_vertex_list_copy->data)->adjacent_vertices;
        for (; tmp_list_adj != 0; tmp_list_adj = tmp_list_adj->next) {
            if (my_strcmp(((t_rooms *) ((t_my_graph *) \
tmp_vertex_list_copy->data)->curr_vertex)->name, ((t_rooms *) ((t_my_graph *) \
tmp_list_adj->data)->curr_vertex)->name) == 0)
                ((t_my_graph *)tmp_vertex_list_copy->data)->adjacent_vertices \
= remove_element_by_pointer_from_list(tmp_list_adj, \
((t_my_graph *)tmp_vertex_list_copy->data)->adjacent_vertices);
        }
    }
}

void fill_adjescent_vertices(t_raw_data *input_data, \
const t_singly_linked_list *tmp_vertex_list, \
t_singly_linked_list *tmp_vertex_list_copy, \
t_singly_linked_list *tmp_vertex_list_copy_2)
{
    for (; input_data->tunnel != 0; \
input_data->tunnel = input_data->tunnel->next) {
        if (my_strcmp(((t_tunnel *) (input_data->tunnel->data))->start_name, \
((t_rooms *) ((t_my_graph *) (tmp_vertex_list->data))->curr_vertex)->name) \
== 0 || my_strcmp(((t_tunnel *) (input_data->tunnel->data))->end_name, \
((t_rooms *) ((t_my_graph *) \
(tmp_vertex_list->data))->curr_vertex)->name) == 0) {
            tmp_vertex_list_copy_2 = tmp_vertex_list_copy;
            for (; tmp_vertex_list_copy_2 != 0; \
tmp_vertex_list_copy_2 = tmp_vertex_list_copy_2->next)
                if (my_strcmp(((t_tunnel *) \
(input_data->tunnel->data))->start_name, ((t_rooms *) ((t_my_graph *) \
(tmp_vertex_list_copy_2->data))->curr_vertex)->name) == 0 \
|| my_strcmp(((t_tunnel *) (input_data->tunnel->data))->end_name, ((t_rooms *) \
((t_my_graph *) (tmp_vertex_list_copy_2->data))->curr_vertex)->name) == 0)
                    ((t_my_graph *)tmp_vertex_list->data)->adjacent_vertices = \
append_data_to_list(tmp_vertex_list_copy_2->data, \
((t_my_graph *)tmp_vertex_list->data)->adjacent_vertices);
        }
    }
}
