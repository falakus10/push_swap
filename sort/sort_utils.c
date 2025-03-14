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
	int		min;
	t_list	*current;

	current = *stack;
	min = current->index;
	while (current->next != NULL)
	{
		if ((current->index < min) && (current-> index > value))
			min = current->index;
		current = current->next;
	}
	return (min);
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
			break;
		position++;
		current = current->next;
	}
	return (position);
}