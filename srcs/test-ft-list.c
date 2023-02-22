#include "ft_list.h"

int test_nb = 1;

void    check_value_char(t_list *lst, char *expected_value)
{
    if (!lst)
        return;
    if (strcmp((char *)lst->data, expected_value) != 0)
    {
        printf(RED);
        printf("REDEXPECTED \"%s\" got \"%s\"\n", expected_value, (char *)lst->data);
        exit(test_nb);
    }
    printf(GREEN);
    printf("\033[0;32mTEST %d OK\n", test_nb);
    test_nb++;
}

void    check_value_int(t_list *lst, int expected_value)
{
    if (!lst)
        return;
    if (ft_list_size(lst) != expected_value)
    {
        printf(RED);
        printf("REDEXPECTED \"%d\" got \"%d\"\n", expected_value, ft_list_size(lst));
        exit(test_nb);
    }
    printf(GREEN);
    printf("\033[0;32mTEST %d OK\n", test_nb);
    test_nb++;
}

void    check_expected_value_int(int value, int expected_value)
{
    if (value != expected_value)
    {
        printf(RED);
        printf("REDEXPECTED \"%d\" got \"%d\"\n", expected_value, value);
        exit(test_nb);
    }
    printf(GREEN);
    printf("\033[0;32mTEST %d OK\n", test_nb);
    test_nb++;
}

int     ft_list_size_non_null(t_list *begin_list)
{
    int size = 0;

    while (begin_list)
    {
        if (begin_list->data)
            size++;
        begin_list = begin_list->next;
    }
    return (size);
}

void    free_lst(t_list *lst)
{
    t_list *tmp = NULL;

    while (lst)
    {
        tmp = lst->next;
        if (lst->data)
            free(lst->data);
        free(lst);
        lst = tmp;
    }
}

void    test_ft_list_push_front(void)
{
    t_list  *lst = NULL;
    t_list  *tmp = NULL;

    printf(NC);
    printf("\nTEST FT_LIST_PUSH_FRONT\n");

    check_value_int(lst, 0);

    ft_list_push_front(&lst, strdup("hello world"));
    check_value_int(lst, 1);

    ft_list_push_front(&lst, strdup("AA"));
    check_value_int(lst, 2);

    ft_list_push_front(&lst, strdup("Hola"));
    check_value_int(lst, 3);


    ft_list_push_front(&lst, strdup("Test"));

    tmp = lst;
    check_value_int(lst, 4);

    check_value_char(lst, "hello world");

    lst = lst->next;
    check_value_char(lst, "AA");

    lst = lst->next;
    check_value_char(lst, "Hola");

    lst = lst->next;
    check_value_char(lst, "Test");

    free_lst(tmp);
}

void    test_ft_size(void)
{
    t_list  *lst = NULL;

    printf(NC);
    printf("\nTEST FT_LIST_SIZE\n");

    check_value_int(lst, 0);

    ft_list_push_front(&lst, strdup("hello world"));
    check_value_int(lst, 1);

    ft_list_push_front(&lst, strdup("AA"));
    check_value_int(lst, 2);

    free_lst(lst);
}

int     comp(void *data, void *data_ref)
{
    if (!data && !data_ref)
        return (0);
    if (!data && data_ref)
        return (1);
    if (data && !data_ref)
        return (-1);
    return strcmp((char *)data, (char *)data_ref);
}

void    free_fct(void *data)
{
    free(data);
}

void    test_ft_list_remove_if(void)
{
    t_list  *lst = NULL;

    printf(NC);
    printf("\nTEST FT_LIST_REMOVE_IF\n");

    ft_list_push_front(&lst, strdup("Hola"));
    ft_list_push_front(&lst, strdup("hello world"));
    ft_list_push_front(&lst, strdup("AA"));

    ft_list_remove_if(&lst, "AA", comp, free_fct);
    check_expected_value_int(ft_list_size_non_null(lst), 2);

    ft_list_remove_if(&lst, "Hola", comp, free_fct);
    check_expected_value_int(ft_list_size_non_null(lst), 1);

    ft_list_remove_if(&lst, "hello world", comp, free_fct);
    check_expected_value_int(ft_list_size_non_null(lst), 0);

    free_lst(lst);
}

// void    test_ft_list_sort(void)
// {
//     t_list  *lst = NULL;

//     printf(NC);
//     printf("\nTEST FT_LIST_SORT\n");

//     ft_list_push_front(&lst, strdup("Hola"));
//     ft_list_push_front(&lst, strdup("hello world"));
//     ft_list_push_front(&lst, strdup("AA"));

//     ft_list_sort(&lst, comp);

//     printf("value=%d\n", ft_list_size(lst));
//     check_value_char(lst, "AA");

//     lst = lst->next;
//     check_value_char(lst, "Hola");

//     // lst = lst->next;
//     // check_value_char(lst, "hello world");
// }

int main(void)
{

    test_ft_list_push_front();
    test_ft_size();
    test_ft_list_remove_if();
    // test_ft_list_sort();
    return (0);
}