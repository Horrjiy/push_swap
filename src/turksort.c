/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:30:24 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 22:16:58 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_calccost_to_b(t_list **a, t_list **b)
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

static void	ft_calccost_to_a(t_list **a, t_list **b)
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

static int	ft_cheapest_position(t_list *node)
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

void	ft_turksort(t_list **a, t_list **b, t_data *data)
{
	int	i;

	while (ft_listlen(*a) > 3)
	{
		ft_target_smallest(a, b);
		ft_calccost_to_b(a, b);
		i = ft_cheapest_position(*a);
		if (ft_listlen(*a) / 2 >= i)
			while (i-- > 1)
				ft_ra(a);
		else
			while (i-- > 1)
				ft_rra(a);
		i = ft_find_position(*b, (*a)->target->num);
		if (ft_listlen(*b) / 2 >= i)
			while (i-- > 1)
				ft_rb(b);
		else
			while (i-- > 1)
				ft_rrb(b);
		ft_pb(a, b);
	}
	ft_sort_3(a, b, data);
	while (ft_listlen(*b))
	{
		ft_target_largest(a, b);
		ft_calccost_to_a(a, b);
		i = ft_cheapest_position(*b);
		if (ft_listlen(*b) / 2 >= i)
			while (i-- > 1)
				ft_rb(b);
		else
			while (i-- > 1)
				ft_rrb(b);
		i = ft_find_position(*a, (*b)->target->num);
		if (ft_listlen(*a) / 2 >= i)
			while (i-- > 1)
				ft_ra(a);
		else
			while (i-- > 1)
				ft_rra(a);
		ft_pa(a, b);
	}
	ft_printf("cheeeck\n");
	ft_spot_numbers(a, data);
	while(data->smallest_num != (*a)->num)
		ft_rra(a);
}
