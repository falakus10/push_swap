/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:06 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:16:06 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	space_control(char **av)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] != ' ')
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
	if (ac == 2)
		return (av[1]);
	while (ac > i)
	{
		j = 0;
		while (av[i] != NULL && av[i][j] != '\0')
		{
			if ((av[i][j] != ' ') && (av[i][j] != '\t'))
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
	k = 0;
	str = (char *)malloc(sizeof(char) * size + 1 + (ac -2));
	if (str == NULL)
		print_error(NULL);
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] != ' ') && (av[i][j] != '\t'))
				str[k++] = av[i][j];
			j++;
		}
		if (i != ac - 1)
			str[k++] = ' ';
		i++;
	}
	str[k++] = '\0';
	return (str);
}

void	control_detail(char **av, int ac)
{
	long	tmp;
	int		i;
	char	**str;

	i = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		i = -1;
	}
	else
		str = av;
	while (str[++i] != NULL)
	{
		tmp = ft_atoi(str[i]);
		if (!is_num(str[i]) || is_exist(tmp, str, i) || (tmp < -2147483648)
			|| (tmp > 2147483647))
		{
			ft_exit(str, ac);
		}
		if (ft_strlen(str[i]) > 13)
			ft_exit(str, ac);
	}
	if (ac == 2)
		free_str(str);
}

char	**ft_control(int ac, char **av)
{
	char	*str;
	char	**args;

	if (space_control(av) == 0)
		print_error(NULL);
	control_detail(av, ac);
	str = ft_create(av, ac);
	args = ft_split(str, ' ');
	if (ac != 2)
		free (str);
	return (args);
}
