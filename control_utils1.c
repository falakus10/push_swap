/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:00 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:16:00 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_exit(char **str, int ac)
{
	if (ac == 2)
	{
		print_error(str);
	}
	else
		print_error(NULL);
}
