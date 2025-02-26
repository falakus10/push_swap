/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:15:38 by falakus           #+#    #+#             */
/*   Updated: 2025/02/26 18:15:38 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put(t_list **src, t_list **dst)
{
	t_list	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_list **a, t_list **b)
{
	put(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	put(a, b);
	write(1, "pb\n", 3);
}
