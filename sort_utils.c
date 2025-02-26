/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:40 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:16:40 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current -> next;
	}
	return (1);
}

int	ft_list_size(t_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list	*stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	get_min(t_list **stack, int value)
{
	t_list	*temp;
	int		min_index_value;

	temp = *stack;
	min_index_value = temp -> index;
	while (temp -> next != NULL )
	{
		temp = temp->next;
		if ((temp->index < min_index_value) && (temp->index != value))
			min_index_value = temp->index;
	}
	return (min_index_value);
}

int	get_position(t_list **stack, int min)
{
	int		position;
	t_list	*current;

	current = *stack;
	position = 0;
	while (current->next != NULL)
	{
		if (current->index == min)
			break ;
		position++;
		current = current->next;
	}
	return (position);
}
