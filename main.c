/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:52 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:16:52 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_list **a, t_list **b)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
	free(a);
	free(b);
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	char	**str;

	if (ac < 2)
		return (0);
	str = ft_control(ac, av);
	a = (t_list **)malloc(sizeof(t_list *));
	b = (t_list **)malloc(sizeof(t_list *));
	if (!a || !b)
		stack_free(a, b);
	*a = NULL;
	*b = NULL;
	ft_stack_create(a, str);
	free_str(str);
	if (is_sorted(a))
	{
		stack_free(a, b);
		return (0);
	}
	ft_sort(a, b, ft_list_size(*a));
	stack_free(a, b);
	return (0);
}
