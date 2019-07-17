#define IS_SPACE(x) ((x == ' ') || (x >= '\t' && x <= '\n'))
#define IS_C_ALPHA(x) ((x >= 'A' && x <= 'Z'))

int		is_valid(char c, int base)
{
	char 	tmp[16] = "0123456789abcdef";

	if (IS_C_ALPHA(c))
		c += 32;
	while (base--)
	{
		if (c == tmp[base])
			return (0);
	}
	return (1);
}

int		return_value(char c)
{
	if (IS_C_ALPHA(c))
		c += 32;
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		num = 0;
	int		neg = 1;

	while (IS_SPACE(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (!is_valid(*str, str_base))
		num = num * str_base + return_value(*str++);
	return (num * neg);                              // I forgot to multiply neg...
}
