#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Check if the base does not include two characteres
*/
bool check_doublon(char *base)
{
    for (int i = 0; base[i]; i++)
    {
        for (int x = i + 1; base[x]; x++)
        {
            if (base[x] == base[i])
                return (false);
        }
    }
    return (true);
}

/*
    Check if the base does not include +, - or a whitespace
    https://stackoverflow.com/a/18169122/21198893
*/
bool check_signs(char *base)
{
    for (int i = 0; base[i]; i++)
    {
        if (base[i] == '+' || base[i] == '-')
            return (false);
        if (base[i] == 32) // space
            return (false);
        if (base[i] == 9) // tab
            return (false);
        if (base[i] == 10) // line feed
            return (false);
        if (base[i] == 11) // line tabulation
            return (false);
        if (base[i] == 12) // formfeed
            return (false);
        if (base[i] == 13) // \n
            return (false);
    }
    return (true);
}

int get_value_from_base(int value, char *base)
{
    if (strlen(base) == 10)
    {
        return (base[value] - '0');
    }
    else if (strlen(base) > 10)
    {
        return (base[value] - '0');
    }
    else
    {
        return (base[value]);
    }
}

long ft_atoi(char *str)
{
    long nb = 0;
    int minus = 1;
    int i = 0;

    if (str[0] == '-')
    {
        minus = -1;
        i++;
    }
    while (str[i])
    {
        nb = (nb * 10) + str[i] - '0';
        i++;
    }
    return (nb * minus);
}

long     reverse_string(char *src)
{
    char dst[1000000];
    int x = strlen(src) -1;
    long nb;
    int i = 0;

    bzero(dst, 1000000);
    while (x >= 0)
    {
        dst[i] = src[x];
        x--;
        i++;
    }
    dst[i] = 0;
    nb = ft_atoi(dst);
    return (nb);
}

long atoi_base(long nb, char *base, unsigned int len_base)
{
    (void)base;
    unsigned int i = 0;
    int minus = 1;
    long result = 0;
    char tmp[100000];
    int x = -1;

    bzero(tmp, 100000);
    if (nb < 0)
    {
        nb = nb * -1;
        minus = -1;
    }
    while (nb > len_base)
    {
        tmp[++x] = (nb % len_base) + '0';
        nb = nb / len_base;
        i++;
    }
    tmp[++x] = (nb % len_base) + '0';
    result = reverse_string(tmp);
    return (result * minus);
}

long ft_atoi_base(char *str, char *base)
{
    unsigned int len_base;
    long result = 0;
    long nb;

    if (!base || strcmp(base, "1") == 0 || strlen(base) == 0)
        return (0);
    if (!check_doublon(base))
        return (0);
    if (!check_signs(base))
        return (0);
    len_base = strlen(base);
    nb = ft_atoi(str);
    result = atoi_base(nb, base, len_base);
    return (result);
}