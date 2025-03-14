#include "../push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_exist(int num, char **av, int i)
{
	while (av[++i] != NULL)
	{
		if (ft_atoi(av[i]) == num)
			return (1);
	}
	return (0);
}

int	is_num(char *num)
{
	if (*num == '-')
	{
		num++;
		if (!ft_isdigit(*num))
			return (0);
	}
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}