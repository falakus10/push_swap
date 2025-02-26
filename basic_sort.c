/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:27 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:16:27 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_list **a)
{
	int		min;
	int		next_min;
	t_list	*current;

	min = get_min(a, -1);
	next_min = get_min(a, min);
	current = *a;
	if (current->index == min && current->next->index != next_min)
	{
		rra(a);
		sa(a);
	}
	else if (current->index == next_min && current->next->index == min)
		sa(a);
	else if (current->index == next_min && current->next->index != min)
		rra(a);
	else if (current->next->index == min && current->index != next_min)
		ra(a);
	else if (current->index != min && current->next->index == next_min)
	{
		sa(a);
		rra(a);
	}
}

void	sort_4(t_list **a, t_list **b)
{
	int	position;

	position = get_position(a, get_min(a, -1));
	if (position == 1)
		sa(a);
	else if (position == 2)
	{
		rra(a);
		rra(a);
	}
	else if (position == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int	position;

	position = get_position(a, get_min(a, -1));
	if (position == 1)
		sa(a);
	else if (position == 2)
	{
		ra(a);
		ra(a);
	}
	else if (position == 3)
	{
		rra(a);
		rra(a);
	}
	else if (position == 4)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	basic_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
