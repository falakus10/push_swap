#include "push_swap.h"

void	stack_free(t_list **a, t_list **b)
{
	free(a);
	free(b);
	print_error(NULL);
}

int main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	char	**str;

	if (ac < 2)
		return 0;
	str = ft_control(ac, av);
	a = (t_list **)malloc(sizeof(t_list *));
	b = (t_list **)malloc(sizeof(t_list *));
	if (!a || !b)
		stack_free(a, b);
	*a = NULL;
	*b = NULL;
	ft_stack_create(a, str);
	if (is_sorted(a))
	{
		free (a);
		free (b);
		return (0);
	}
	ft_sort(a, b, ft_list_size(*a));
	free(a);
	free (b);
	return (0);
}
