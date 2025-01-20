/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:47:38 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/20 15:57:15 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	ft_sa(t_list **a)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*a) < 2)
		return ;
	temp = *a;
	temp2 = (*a)->next;
	temp->next = temp2->next;
	temp2->next = *a;
	*a = temp2;
	ft_printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	ft_sb(t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*b) < 2)
		return ;
	temp = *b;
	temp2 = (*b)->next;
	temp->next = temp2->next;
	temp2->next = *b;
	*b = temp2;
	ft_printf("sb\n");
}

// ss: sa and sb at the same time.
void	ft_ss(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*a) < 2 && ft_listlen(*b) < 2)
		return ;
	if (ft_listlen(*a) >= 2)
	{
		temp = *a;
		temp2 = (*a)->next;
		temp->next = temp2->next;
		temp2->next = *a;
		*a = temp2;
	}
	if (ft_listlen(*b) >= 2)
	{
		temp = *b;
		temp2 = (*b)->next;
		temp->next = temp2->next;
		temp2->next = *b;
		*b = temp2;
	}
	ft_printf("ss\n");
}
