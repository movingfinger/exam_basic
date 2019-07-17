#include <unistd.h>
#define WRONG_OPTION() (write(1, "Invalid Option", 14))
#define PRINT_USAGE() (write(1, "options: abcdefghijklmnopqrstuvwxyz", 35))
#define IS_S_ALPHA(x) ((x >= 'a' && x <= 'z'))

void	ft_putnbr(int n)
{
	char 	c;

	if (n == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr(21474);
		ft_putnbr(83648);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int		check_length(char *s)
{
	int		i = 0;

	while (s[i])
		i++;
	return (i);
}

int		check_error(char **s, int size)
{
	int		tmp[26] = {0};
	int		num = 0;
	int		length = 0;
	int		index = 0;

	if (size == 0)
	{
		PRINT_USAGE();
		return (-1);
	}
	for (int i = 0; i < size; i++)
	{
		if (s[i][0] != '-')
		{
			WRONG_OPTION();
			return (-1);
		}
		else
		{
			if (s[i][1] == 'h')
			{
				PRINT_USAGE();
				return (-1);
			}
			else
			{
				length = check_length(s[i]);
				for (int j = 1; j < length; j++)
				{
					if (IS_S_ALPHA(s[i][j]))
					{
						index = 'z' - s[i][j];
						tmp[index] = 1;             //it was incremented before, and I failed. So I changed it to 1.
					}
					else
					{
						WRONG_OPTION();
						return (-1);
					}
				}
			}
		}
	}
	for (int k = 0; k < 26; k++)
		num = num * 2 +  tmp[k];
	return (num);
}

int		main(int ac, char **av)
{
	if (check_error(av + 1, ac - 1) != -1)
		ft_putnbr(check_error(av + 1, ac - 1));
	write(1, "\n", 1);
	return (0);
}
