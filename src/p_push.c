/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:01:21 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/25 12:53:58 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// pa (push a): Take the first element at the top of b
// and put it at the top of a.
// Do nothing if b is empty.
void	ft_pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a 
// and put it at the top of b.
// Do nothing if a is empty.
void	ft_pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_printf("pb\n");
}
