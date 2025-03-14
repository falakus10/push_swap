#include "../push_swap.h"

void	ft_sort(t_list **a, t_list **b, int size)
{
	if (is_sorted(a) || size <= 1)
		return ;
	else if (size < 6)
		return (basic_sort(a, b, size));
	else
		return (radix_sort(a, b));
}