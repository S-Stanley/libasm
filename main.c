#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int 		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *buff, int size);

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

void	test_strcmp(char *mode)
{
	printf("\n** TEST STRCMP **\n");

	if (strcmp(mode, "real") == 0)
	{
		printf("%d\n", strcmp("Hello world", "Hello world"));
		printf("%d\n", strcmp("Hello world", "Hello"));
		printf("%d\n", strcmp("Hello", "Hello world"));
		printf("%d\n", strcmp("", ""));
		printf("%d\n", strcmp("Hello world", "Hello 1world"));
		printf("%d\n", strcmp("Hello 1world", "Hello world"));
	}
	else
	{
		printf("%d\n", ft_strcmp("Hello world", "Hello world"));
		printf("%d\n", ft_strcmp("Hello world", "Hello"));
		printf("%d\n", ft_strcmp("Hello", "Hello world"));
		printf("%d\n", ft_strcmp("", ""));
		printf("%d\n", ft_strcmp("Hello world", "Hello 1world"));
		printf("%d\n", ft_strcmp("Hello 1world", "Hello world"));
	}
}

void	test_write(char *mode)
{
	printf("\n** TEST WRITE **\n");
	
	int fd_real = open("tests/test-write-real", O_RDWR | O_CREAT);
	int fd_libasm = open("tests/test-write-libasm", O_RDWR | O_CREAT);

	if (strcmp(mode, "real") == 0)
	{
		printf("\n%ld\n", write(1, "Hello world", strlen("Hello world")));
		write(fd_real, "test\nsalut", 10);
	}
	else
	{
		printf("\n%d\n", ft_write(1, "Hello world", strlen("Hello world")));
		ft_write(fd_libasm, "test\nsalut", 10);
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
	test_strcmp(av[1]);
	test_write(av[1]);

	return (0);
}
