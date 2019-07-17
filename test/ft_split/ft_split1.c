#include <stdlib.h>
#define IS_SPACE(x) ((x == ' ') || (x >= '\t' && x <- '\n'))

int		words_count(char *s)
{
	int		n = 0;
	int		i = 0;

	while (s[i])
	{
		while (s[i] && IS_SPACE(s[i]))
			i++;
		if (s[i] && !IS_SPACE(s[i]))
		{
			n++;
			while (s[i] && !IS_SPACE(s[i]))
				i++;
		}
	}
	return (n);
}

char    **ft_split(char *str)
{
	int		size = words_count(str);
	int		i = 0;
	int		j = 0;
	int		len;
	char	**res = (char **)malloc(sizeof(char *) * (size + 1));

	while (str[i])
	{
		while (str[i] && IS_SPACE(str[i]))
			i++;
		len = 0;
		if (str[i] && !IS_SPACE(str[i]))
		{
			while (str[i] && !IS_SPACE(str[i]))
			{
				len++;
				i++;
			}
		}
		res[j] = (char *)malloc(sizeof(char) * (len + 1));
		for (int k = 0; k < len; k++)
			res[j][k] = str[i - len + k];
		res[j++][len] = '\0';
	}
	return (res);
}
