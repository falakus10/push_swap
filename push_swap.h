/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:16:59 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:16:59 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_list;

void	basic_sort(t_list **a, t_list **b, int size);
void	sort_5(t_list **a, t_list **b);
void	sort_4(t_list **a, t_list **b);
void	sort_3(t_list **a);
int		is_num(char *num);
int		is_exist(int num, char **av, int i);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_control(int ac, char **av);
void	control_detail(char **av, int ac);
char	*fill_str(char **av, int ac, int size);
char	*ft_create(char **av, int ac);
int		space_control(char **av);
char	**ft_split(char const *s, char c);
void	stack_free(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	put(t_list **src, t_list **dst);
void	radix_sort(t_list **a, t_list **b);
int		ft_max_bit(t_list **stack);
void	rrb(t_list **b);
void	rra(t_list **a);
void	reverse_rotate(t_list **stack);
void	rr(t_list **a, t_list **b);
void	rb(t_list **b);
void	ra(t_list **a);
void	rotate(t_list **stack);
int		get_position(t_list **stack, int min);
int		get_min(t_list **stack, int value);
t_list	*ft_lstlast(t_list	*stack);
int		ft_list_size(t_list *stack);
int		is_sorted(t_list **stack);
void	ft_sort(t_list **a, t_list **b, int size);
void	ft_stack_create(t_list	**stack, char **str);
void	ft_index_stack(t_list **stack);
t_list	*ft_next_min(t_list **stack);
t_list	*ft_lstnew(int content);
void	ft_add_back(t_list **stack, t_list *new);
void	ss(t_list **a, t_list **b);
void	sb(t_list **b);
void	sa(t_list	**a);
void	swap(t_list **stack);
size_t	ft_strlen(const char *str);
void	print_error(char **str);
void	free_str(char **str);
void	ft_exit(char **str, int ac);
#endif