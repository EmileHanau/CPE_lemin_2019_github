/*
** EPITECH PROJECT, 2020
** input_handling
** File description:
** handles input
*/

#include "../include/lemin.h"

t_raw_data *get_input(int argc)
{
    t_raw_data *result = 0;
    char *line = 0;
    int is_end = 0;

    if (argc != 1) {
        my_printf("Error: invalid argument number.\n" \
"(Program doesn't require arguments.)\n");
        return (0);
    }
    if (!(result = malloc(sizeof(t_raw_data)))) return (0);
    result->rooms = 0;
    result->tunnel = 0;
    while (is_end == 0) {
        line = save_next_input_line(&is_end);
        if (handle_input_line(result, line) == -1) {
            my_printf("Error: invalid input.\n");
            return (0);
        }
    }
    return (are_all_rooms_unique(result->rooms) ? result: 0);
}

char *save_next_input_line(int *is_end)
{
    size_t size = 0;
    char *str = 0;

    if (getline(&str, &size, stdin) == -1)
        *is_end = 1;
    if (str[0] == '\n') //Todo: remove this -> only for debug
        *is_end = 1;
    str = cut_given_char_and_everything_after(str, '\n');
    return (str);
}

int handle_input_line(t_raw_data *result, char *line)
{
    static int next_is_start = 0;
    static int next_is_end = 0;

    if (my_strcmp(line, "##start") == 0) {
        next_is_start = 1;
        return (0);
    }
    if (my_strcmp(line, "##end") == 0) {
        next_is_end = 1;
        return (0);
    }
    line = cut_given_char_and_everything_after(line, '#');
    if (line[0] == '\0')
        return (0);
    return (handle_input_line_2(result, line, &next_is_end, &next_is_start));
}

int handle_input_line_2(t_raw_data *result, char *line, int *is_end, \
int *is_start)
{
    static int ants_count = -1;
    static int rooms_complete = 0;
    t_singly_linked_list *temp = 0;

    if (ants_count == -1) {
        if ((ants_count = my_getnbr(\
cut_given_char_and_everything_after(line, '\n'))) < 0)
            return (-1);
    }
    else if (rooms_complete != 1) {
        if ((rooms_complete = save_room(result, line, is_end, is_start)) == -1)
            return (-1);
        for (temp = result->rooms; temp->next; temp = temp->next);
        if (((t_rooms *) temp->data)->is_start == 1)
            ((t_rooms *) temp->data)->ant_count = ants_count;
    } else {
        if (save_tunnel(result, line) == -1)
            return (-1);
    }
    return (0);
}

int save_room(t_raw_data *result, char *line, int *is_end, int *is_start)
{
    t_rooms *room = malloc(sizeof(t_rooms));

    if (is_tunnel(result, line)) {
        save_tunnel(result, line);
        return (1);
    }
    if (get_room_name_and_coordinate(room, line) == -1)
        return (-1);
    room->is_end = is_end[0];
    is_end[0] = 0;
    room->is_start = is_start[0];
    is_start[0] = 0;
    room->curr_ant_nb = 0;
    if (room->is_start == 1)
        room->curr_ant_nb = 1;
    room->ant_count = 0;
    if (room->x < 0 || room->y < 0 || room->name[0] == '\0')
        return (-1);
    result->rooms = append_data_to_list(room, result->rooms);
    return (0);
}