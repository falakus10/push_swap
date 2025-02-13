#include "../push_swap.h"

int	space_control(char **av)
{
	int	i;
	int j;
	int flag;

	flag = 0;
	i = 1;

	while (av[i] != NULL)
	{
		j = 0;
		flag = 0;
		while (av[i][j] != '\0')
		{
			if(av[i][j] != ' ')
			{
				flag = 1;
			}
			j++;
		}
		i++;
	}
	return (flag);
}

char	*ft_create(char **av, int ac)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = 1;
	count = 0;
	while (ac > i)
	{
		j = 0;
		while (av[i] != NULL && av[i][j] != '\0')
		{
			if ( ft_isdigit(av[i][j]) == 1)
				count++;
			j++;
		}
		i++;
	}
	str = fill_str(av, ac, count);
	return (str);
}

char	*fill_str(char **av, int ac, int size)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = -1;
	str =(char *)malloc(sizeof(char) * size + 1 + (ac -2));
	if (str == NULL)
		print_error(NULL);
	while (av[i] != NULL)
	{
		j = -1;
		while (av[i][j++] != '\0')
		{
			if ( ft_isdigit(av[i][j]) == 1)
				str[k++] = av[i][j];
		}
		if (i != ac - 1)
        	str[k++] = ' ';
		i++;
	}
	str[k++] = '\0';
	return (str);
}

void	control_detail(char **av)
{
	long	tmp;
	int		i;

	i = 0;
	while (av[++i] != NULL)
	{
		tmp = ft_atoi(av[i]);
		if (!is_num(av[i]) || is_exist(tmp, av, i) || (tmp < -2147483648)
			|| (tmp > 2147483647))
			print_error(NULL);
		if (ft_strlen(av[i]) > 13)
			print_error(NULL);
	}
}

char	**ft_control(int ac, char **av)
{
	char	*str;
	char	**args;
	
	if (space_control(av) == 0)
		print_error(NULL);
	control_detail(av);
	str = ft_create(av, ac);
	args = ft_split(str, ' ');
	free(str);
	return(args);
}
