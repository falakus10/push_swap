#include "../push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*end;
	t_list	*first;

	if (ft_list_size(*stack) < 2)
		return ;
	first = (*stack);
	end = ft_lstlast(*stack);
	(*stack) = (*stack)->next;
	end->next = first;
	first->next = NULL;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}