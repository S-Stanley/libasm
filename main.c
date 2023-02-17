#include <stdio.h>
#include <string.h>

int ft_strlen(char *str);

void	test_strlen(char *mode)
{
	printf("** TEST STRLEN **\n");

	if (strcmp(mode, "real") == 0)
	{
		printf("%ld\n", strlen("Hello world"));
		printf("%ld\n", strlen("Hello world\n"));
		printf("%ld\n", strlen("Hello world\nTest\n"));
		printf("%ld\n", strlen(""));
	}
	else
	{
		printf("%d\n", ft_strlen("Hello world"));
		printf("%d\n", ft_strlen("Hello world\n"));
		printf("%d\n", ft_strlen("Hello world\nTest\n"));
		printf("%d\n", ft_strlen(""));
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: ./a.out [MODE]\n");
		printf("Mode could be \"real\" or \"libasm\"");
		return (1);
	}
	if (strcmp(av[1], "real") != 0 && strcmp(av[1], "libasm") != 0)
	{
		printf("Unknow mode\n");
		return (1);
	}
	test_strlen(av[1]);
	return (0);
}
