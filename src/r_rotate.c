/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:01:18 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/22 12:38:39 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_list **a)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*a) < 2)
		return ;
	temp = ft_lastnode(*a);
	temp2 = *a;
	temp->next = *a;
	*a = (*a)->next;
	temp2->next = NULL;
	ft_printf("ra\n");
}

void	ft_rb(t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*b) < 2)
		return ;
	temp = ft_lastnode(*b);
	temp2 = *b;
	temp->next = *b;
	*b = (*b)->next;
	temp2->next = NULL;
	ft_printf("rb\n");
}

void	ft_rr(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*a) < 2 && ft_listlen(*b) < 2)
		return ;
	if (!(ft_listlen(*a) < 2))
	{
		temp = ft_lastnode(*a);
		temp2 = *a;
		temp->next = *a;
		*a = (*a)->next;
		temp2->next = NULL;
	}
	if (!(ft_listlen(*b) < 2))
	{
		temp = ft_lastnode(*b);
		temp2 = *b;
		temp->next = *b;
		*b = (*b)->next;
		temp2->next = NULL;
	}
	ft_printf("rr\n");
}
