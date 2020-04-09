/*
** EPITECH PROJECT, 2019
** input_handling2.c
** File description:
** extends input_handling1
*/

#include "../include/lemin.h"

int is_tunnel(t_raw_data *result, char *line)
{
    char *first = cut_given_char_and_everything_after(line, '-');
    char *second = cut_given_char_and_everything_before(line, '-');
    int name_is_existing = 0;

    for (t_singly_linked_list *temp = result->rooms; temp; temp = temp->next) {
        if (my_strcmp(first, ((t_rooms *) temp->data)->name) == 0 || \
my_strcmp(second, ((t_rooms *) temp->data)->name) == 0)
            name_is_existing++;
        if (name_is_existing == 2)
            return (1);
    }
    return (0);
}

int save_tunnel(t_raw_data *result, char *line)
{
    t_tunnel *tunnel = malloc(sizeof(t_tunnel));

    if(!is_tunnel(result, line))
        return (-1);
    tunnel->start_name = cut_given_char_and_everything_after(line, '-');
    tunnel->end_name = cut_given_char_and_everything_before(line, '-');
    if (tunnel->start_name[0] == '\0' || tunnel->end_name[0] == '\0')
        return (-1);
    result->tunnel = append_data_to_list(tunnel, result->tunnel);
    return (0);
}

int get_room_name_and_coordinate(t_rooms *room, char *line)
{
    room->name = cut_given_char_and_everything_after(line,' ');
    if (my_strcmp(line, (cut_given_char_and_everything_before(line, ' '))) == 0)
        return (-1);
    line = cut_given_char_and_everything_before(line, ' ');
    room->x = my_getnbr(cut_given_char_and_everything_after(line, ' '));
    if (my_strcmp(line, (cut_given_char_and_everything_before(\
    line, ' '))) == 0)
        return (-1);
    line = cut_given_char_and_everything_before(line, ' ');
    room->y = my_getnbr(cut_given_char_and_everything_after(line, ' '));
    if (my_strcmp(line, (cut_given_char_and_everything_after(\
    line, ' '))) != 0)
        return (-1);
    return (0);
}

int are_all_rooms_unique(t_singly_linked_list *rooms)
{
    for (t_singly_linked_list *temp = rooms; temp; temp = temp->next) {
        if (!is_given_room_unique(rooms, temp)) {
            my_printf("Error: invalid input.\n(All rooms must have unique " \
"names and coordinates.)\n");
            return (0);
        }
    }
    return (1);
}

int is_given_room_unique(t_singly_linked_list *rooms, \
t_singly_linked_list *room)
{
    for (t_singly_linked_list *temp = rooms; temp; temp = temp->next) {
        if (temp == room)
            continue;
        if (my_strcmp(((t_rooms *) temp->data)->name, ((t_rooms *) \
        room->data)->name) == 0)
            return (0);
        if (((t_rooms *) temp->data)->x == ((t_rooms *) room->data)->x && \
        ((t_rooms *) temp->data)->y == ((t_rooms *) room->data)->y)
            return (0);
        return (1);
    }
}