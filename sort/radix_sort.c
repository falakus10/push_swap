#include "../push_swap.h"

int	ft_max_bit(t_list **stack)
{
	int		max_index;
	int		max_bit;
	t_list	*current;

	max_index = -1;
	max_bit = 0;
	current = *stack;
	while (current->next != NULL)
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
	i = 0;
	max_bit = ft_max_bit(a);
	size = ft_list_size(*a);
	current = *a;
	while (bit < max_bit)
	{
		while (i < size)
		{
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
