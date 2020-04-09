/*
** EPITECH PROJECT, 2020
** lemin.h
** File description:
** lemin headerfile
*/

#ifndef CPE_LEMIN_2019_LEMIN_H
#define CPE_LEMIN_2019_LEMIN_H

#include "printf.h"

struct my_graph;

typedef struct tunnel {
    char *start_name;
    char *end_name;
} t_tunnel;

typedef struct singly_linked_list {
    void *data;
    struct singly_linked_list *next;
} t_singly_linked_list;

typedef struct rooms {
    char *name;
    int is_start;
    int is_end;
    int x;
    int y;
    int curr_ant_nb;
    int ant_count;
} t_rooms;

typedef struct raw_data {
    t_singly_linked_list *rooms;
    t_singly_linked_list *tunnel;
} t_raw_data;

typedef struct my_graph {
    void *curr_vertex;
    t_singly_linked_list *adjacent_vertices;
    int weight;
} t_my_graph;

typedef struct solution {

} t_solution;

t_singly_linked_list *remove_element_by_data_pointer_from_list(t_singly_linked_list \
*list, void *data_to_remove);
void delete_vertex_from_graph(t_my_graph *vertex_to_remove, \
t_singly_linked_list *vertex_list);
void fill_adjescent_vertices(t_raw_data *input_data, \
const t_singly_linked_list *tmp_vertex_list, \
t_singly_linked_list *tmp_vertex_list_copy, \
t_singly_linked_list *tmp_vertex_list_copy_2);
void remove_self_ref_edges(t_singly_linked_list *tmp_vertex_list_copy, \
t_singly_linked_list *tmp_list_adj);
t_singly_linked_list *remove_element_by_pointer_from_list(\
t_singly_linked_list *element, t_singly_linked_list  *list);
t_singly_linked_list *append_data_to_list(void *data, \
t_singly_linked_list *list);
t_singly_linked_list *create_singly_linked_list_from_data(void *data);
t_singly_linked_list *create_empty_singly_linked_list(void);
void destructor_list(t_singly_linked_list *list);
t_raw_data *get_input(int argc);
char *save_next_input_line(int *is_end);
int handle_input_line(t_raw_data *result, char *line);
int handle_input_line_2(t_raw_data *result, char *line, int *is_end, \
int *is_start);
int save_room(t_raw_data *result, char *line, int *is_end, int *is_start);
char *cut_given_char_and_everything_before(char *str, char cut);
char *cut_given_char_and_everything_after(char *str, char cut);
t_my_graph * create_data_graph_from_input(t_raw_data *input_data);
t_solution *get_solution(t_my_graph *data_graph);
int print_solution(t_solution *solution);
int is_tunnel(t_raw_data *, char *);
int save_tunnel(t_raw_data *result, char *line);
int get_room_name_and_coordinate(t_rooms *room, char *line);
int are_all_rooms_unique(t_singly_linked_list *rooms);
int is_given_room_unique(t_singly_linked_list *rooms, \
t_singly_linked_list *room);

#endif //CPE_LEMIN_2019_LEMIN_H