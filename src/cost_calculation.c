/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:03:48 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/14 15:50:08 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_calccost_to_b(t_list **a, t_list **b)
{
	t_list	*atemp;
	int		alistlen;
	int		blistlen;
	int		position;

	atemp = *a;
	alistlen = ft_listlen(*a);
	blistlen = ft_listlen(*b);
	while (atemp)
	{
		atemp->pushcost = 0;
		position = ft_find_position(*a, atemp->num) - 1;
		if (alistlen / 2 >= position)
			atemp->pushcost += (position);
		else
			atemp->pushcost += (alistlen - position);
		position = ft_find_position(*b, atemp->target->num);
		if (blistlen / 2 >= position)
			atemp->pushcost += (position);
		else
			atemp->pushcost += (blistlen - position);
		atemp = atemp->next;
	}
}

void	ft_calccost_to_a(t_list **a, t_list **b)
{
	t_list	*btemp;
	int		alistlen;
	int		blistlen;
	int		position;

	btemp = *b;
	alistlen = ft_listlen(*a);
	blistlen = ft_listlen(*b);
	while (btemp)
	{
		btemp->pushcost = 0;
		position = ft_find_position(*b, btemp->num) - 1;
		if (blistlen / 2 >= position)
			btemp->pushcost += (position);
		else
			btemp->pushcost += (blistlen - position);
		position = ft_find_position(*a, btemp->target->num);
		if (alistlen / 2 >= position)
			btemp->pushcost += (position);
		else
			btemp->pushcost += (alistlen - position);
		btemp = btemp->next;
	}
}

int	ft_cheapest_position(t_list *node)
{
	t_list	*temp;
	int		cheapest;

	temp = node;
	cheapest = INT_MAX;
	while (temp)
	{
		if (cheapest > temp->pushcost)
			cheapest = temp->pushcost;
		temp = temp->next;
	}
	temp = node;
	while (temp)
	{
		if (cheapest == temp->pushcost)
			break ;
		temp = temp->next;
	}
	return (ft_find_position(node, temp->num));
}
