#include <stdio.h>
#include <string.h>

size_t	ft_strlen(char *str);

int main(void)
{
	printf("mine: %ld\n", ft_strlen("hello world\n"));
	printf("real: %ld\n", strlen("hello world\n"));
	
	printf("mine: %ld\n", ft_strlen(NULL));
	printf("real: %ld\n", strlen(NULL));
	
	return (0);
}
