#include "../push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*beforelast;
	t_list	*last;

	beforelast = *stack;
	while (beforelast->next->next)
		beforelast = beforelast->next;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = last;
	beforelast->next = NULL;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
