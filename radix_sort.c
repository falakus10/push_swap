/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:33 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:16:33 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max_bit(t_list **stack)
{
	int		max_index;
	int		max_bit;
	t_list	*current;

	max_index = -1;
	max_bit = 0;
	current = *stack;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while ((max_index >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	radix_sort(t_list **a, t_list **b)
{
	int		bit;
	int		max_bit;
	int		size;
	int		i;
	t_list	*current;

	bit = 0;
	max_bit = ft_max_bit(a);
	size = ft_list_size(*a);
	while (bit < max_bit)
	{
		i = 0;
		while (i < size)
		{
			current = *a;
			if ((current->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
