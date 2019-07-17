#include <stdio.h>
#include <string.h>

char    **ft_split(char *str);
int		words_count(char *s);

int		main(int ac, char **av)
{
	char	**s;
	int		size;

	if (ac == 2)
	{
		s = ft_split(av[1]);
		size = words_count(av[1]);
		printf("size is %d\n", size);
		for (int i = 0; i < size; i++)
			printf("%s\n", s[i]);
	}
	return (0);
}
