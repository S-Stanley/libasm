#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define BASE_10 "0123456789"
# define BASE_8 "01234567"

long ft_atoi_base(char *str, char *base);

int test_nb = 1;

void    test_atoi_base_should_fail(char *str, char *base)
{
    int rd = ft_atoi_base(str, base);
    if (rd != 0)
    {
        printf("EXPECTED 0 got \"%d\"\n", rd);
        exit(test_nb);
    }
    printf("\033[0;32mTEST %d OK\n", test_nb);
    test_nb++;
}

void    test_atoi_base_should_succeed(char *str, char *base, long expected_result)
{
    long rd = ft_atoi_base(str, base);
    if (rd != expected_result)
    {
        printf("\033[0;31mERROR TEST %d\n", test_nb);
        printf("EXPECTED \"%ld\" got \"%ld\"\n", expected_result, rd);
        exit(test_nb);
    }
    printf("\033[0;32mTEST %d OK\n", test_nb);
    test_nb++;
    (void)expected_result;
}

int main(void)
{
    char tmp[10];

    test_atoi_base_should_fail("42", NULL);
    test_atoi_base_should_fail("42", "");

    test_atoi_base_should_fail("42", "1");
    test_atoi_base_should_fail("42", "42215");
    test_atoi_base_should_fail("42", "44214");
    test_atoi_base_should_fail("42", "42155");
    test_atoi_base_should_fail("42", "42+15");
    test_atoi_base_should_fail("42", "42-15");
    test_atoi_base_should_fail("42", "42 15"); // space
    test_atoi_base_should_fail("42", "42    15"); // tab

    bzero(tmp, 10);
    sprintf(tmp, "42%c15", 10);
    test_atoi_base_should_fail("42", tmp); // line feed

    bzero(tmp, 10);
    sprintf(tmp, "42%c15", 11);
    test_atoi_base_should_fail("42", tmp); // line tab

    bzero(tmp, 10);
    sprintf(tmp, "42%c15", 12);
    test_atoi_base_should_fail("42", tmp); // form feed

    test_atoi_base_should_fail("42", "42\n15"); // \n

    test_atoi_base_should_succeed("42", BASE_10, 42);
    test_atoi_base_should_succeed("1", BASE_10, 1);
    test_atoi_base_should_succeed("-1", BASE_10, -1);
    test_atoi_base_should_succeed("-42", BASE_10, -42);
    test_atoi_base_should_succeed("-2147483648", BASE_10, -2147483648);
    test_atoi_base_should_succeed("2147483647", BASE_10, 2147483647);
    test_atoi_base_should_succeed("0", BASE_10, 0);
    test_atoi_base_should_succeed("-0", BASE_10, -0);

    test_atoi_base_should_succeed("42", BASE_8, 52);
    test_atoi_base_should_succeed("1", BASE_8, 1);
    test_atoi_base_should_succeed("-1", BASE_8, -1);
    test_atoi_base_should_succeed("-42", BASE_8, -52);
    test_atoi_base_should_succeed("-2147483648", BASE_8, -20000000000);
    test_atoi_base_should_succeed("2147483647", BASE_8, 17777777777);
    test_atoi_base_should_succeed("0", BASE_8, 0);
    test_atoi_base_should_succeed("-0", BASE_8, -0);

    return (0);
}