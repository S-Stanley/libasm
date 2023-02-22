#include "ft_list.h"

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *new = malloc(sizeof(t_list));
    t_list  *lst = *begin_list;

    new->data = data;
    new->next = NULL;

    if (!(*begin_list))
    {
        (*begin_list) = new;
        return;
    }
    while ((*begin_list)->next)
        *begin_list = (*begin_list)->next;
    (*begin_list)->next = new;

    *(begin_list) = lst;
}

int     ft_list_size(t_list *begin_list)
{
    int size = 0;
    t_list *tmp = begin_list;

    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}

// bool    is_sorted(t_list **begin_list, int (*comp)())
// {
//     t_list  *tmp = *begin_list;

//     if (ft_list_size(*begin_list) < 2)
//         return (true);
//     while ((*begin_list)->next)
//     {
//         if (comp((*begin_list)->data), (*begin_list)->next->data != 0)
//         {
//             *begin_list = tmp;
//             return (false);
//         }
//         *begin_list = (*begin_list)->next;
//     }
//     *begin_list = tmp;
//     return (true);
// }

// t_list  *get_smallest(t_list **begin_list, t_list *ref, int (*comp)())
// {
//     t_list  *tmp = *begin_list;
//     t_list  *new_ref = NULL;

//     while (*begin_list)
//     {
//         if (ref)
//         {
//             if (comp((*begin_list)->data, ref->data) != 0)
//             {
//                 if (new_ref && comp((*begin_list)->data), new_ref->data)
//                     new_ref = (*begin_list);
//             }
//         }
//         else
//         {
//             if (new_ref && comp((*begin_list)->data), new_ref->data)
//                 new_ref = (*begin_list)->data;
//         }
//         *begin_list = (*begin_list)->next;
//     }
//     *begin_list = tmp;
//     return (new_ref);
// }

// void    ft_list_sort(t_list **begin_list, int (*comp)())
// {
//     t_list   *new = NULL;
//     t_list  *last_smallest = NULL;

//     if (ft_list_size(*begin_list) < 2)
//         return ;
//     for (int i = 0; i < ft_list_size(*begin_list); i++)
//     {
//         last_smallest = get_smallest(begin_list, last_smallest, comp);
//         new->next = last_smallest;
//         new = new->next;
//     }
//     *begin_list = new;

//     // if (ft_list_size(*begin_list) < 2)
//     //     return ;
//     // while (*begin_list)
//     // {
//     //     if (comp(tmp, (*begin_list)->next))
//     //     {
//     //         tmp = (*begin_list)->next;
//     //     }
//     // }
//     // new = tmp;
// }

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*comp)(), void (*free_fct)(void *))
{
    t_list  *lst = *begin_list;

    while (*begin_list)
    {
        if (comp((*begin_list)->data, data_ref) == 0)
        {
            free_fct((*begin_list)->data);
            (*begin_list)->data = NULL;
            *(begin_list) = lst;
            return ;
        }
        *begin_list = (*begin_list)->next;
    }
    *(begin_list) = lst;
}