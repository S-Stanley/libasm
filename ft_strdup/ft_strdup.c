#include <stdlib.h>
#include <string.h>

char *ft_strdup(char *str)
{
	char *tmp;

	if (!str)
		return (NULL);
	tmp = malloc(sizeof(char) * (strlen(str) + 1));
	if (!tmp)
		return (NULL);
	for (int i = 0; str[i]; i++)
		tmp[i] = str[i];	
	return (tmp);
}
