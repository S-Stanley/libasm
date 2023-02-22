#ifndef FT_LIST_H
# define FT_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"

typedef struct  s_list {
    void            *data;
    struct s_list   *next;
}   t_list;

void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
void    ft_list_sort(t_list **begin_list, int (*comp)());
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*comp)(), void (*free_fct)(void *));

#endif