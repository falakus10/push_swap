#include "../push_swap.h"

void	ft_add_back(t_list **stack, t_list *new)
{
	t_list	*ptr;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->next = NULL;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_list	*ft_next_min(t_list **stack)
{
	t_list	*current;
	t_list	*min;
	int		start;

	start  = 0;
	current = *stack;
	min = NULL;
	while (current != NULL)
	{
		if ((current->index == -1) && (!start || current->content < min->content))
		{
			min = current;
			start = 1;
		}
		current = current->next;
	}
	return (min);
}

void	ft_index_stack(t_list **stack)
{
	t_list	*current;
	int		index;

	index = 0;
	current = ft_next_min(stack);
	while (current)
	{
		current->index = index++;
		current = ft_next_min(stack);
	}
}

void	ft_stack_create(t_list	**stack, char **str)
{
	t_list	*new;
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (!new)
			print_error(str);
		ft_add_back(stack, new);
		i++;
	}
	ft_index_stack(stack);
}