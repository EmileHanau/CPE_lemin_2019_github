/*
** EPITECH PROJECT, 2020
** linked_list_handling.c
** File description:
** handles linked list
*/

#include "../include/lemin.h"

t_singly_linked_list *create_empty_singly_linked_list(void)
{
    t_singly_linked_list *sll = malloc(sizeof(t_singly_linked_list));

    if (sll == 0)
        return 0;
    sll->next = 0;
    sll->data = 0;
    return sll;
}

t_singly_linked_list *create_singly_linked_list_from_data(void *data)
{
    t_singly_linked_list *list = create_empty_singly_linked_list();

    list->data = data;
    return list;
}

t_singly_linked_list *append_data_to_list(void *data, \
t_singly_linked_list *list)
{
    t_singly_linked_list *orig_list = list;
    t_singly_linked_list *tmp_list = malloc(sizeof(t_singly_linked_list));

    if (orig_list == 0)
        return create_singly_linked_list_from_data(data);
    tmp_list->next = 0;
    tmp_list->data = data;
    for (; list->next != 0; list = list->next);
    list->next = tmp_list;
    return orig_list;
}

t_singly_linked_list *remove_element_by_pointer_from_list( \
t_singly_linked_list *element, t_singly_linked_list  *list)
{
    t_singly_linked_list *orig_list = list;

    if (list == element) {
        orig_list = list->next;
        free(element);
        return orig_list;
    }
    for (; list->next != element; list = list->next);
    list->next = list->next->next;
    free(element);
    return orig_list;
}

t_singly_linked_list *remove_element_by_data_pointer_from_list(t_singly_linked_list *list, \
void *data_to_remove)
{
    for (t_singly_linked_list *temp = list; temp; temp = temp->next) {
        if (temp->data == data_to_remove)
            return (remove_element_by_pointer_from_list(temp, list));
    }
    return (list);
}

void destructor_list(t_singly_linked_list *list)
{
    for (; list != 0;)
        list = remove_element_by_pointer_from_list(list, list);
}