#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str);
char *ft_strcpy(char *dest, char *src);

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

void	test_strcpy(char *mode)
{
	printf("\n** TEST STRCPY **\n");

	char buff[100];
	bzero(buff, 100);

	if (strcmp(mode, "real") == 0)
	{
		printf("%s\n", strcpy(buff, "Hello world"));
		printf("%s\n", buff);
		bzero(buff, 100);
		printf("%s\n", strcpy(buff, ""));
	}
	else
	{
		printf("%s\n", ft_strcpy(buff, "Hello world"));
		printf("%s\n", buff);
		bzero(buff, 100);
		printf("%s\n", ft_strcpy(buff, ""));
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
	test_strcpy(av[1]);

	return (0);
}
