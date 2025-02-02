/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:30:24 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 20:27:07 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_position(t_list *node, int i)
{
	t_list	*temp;
	int		position;

	position = 0;
	temp = node;
	while (temp)
	{
		position++;
		if (temp->num = i)
			break ;
		temp = temp->next;
	}
	return (position);
}

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
		position = ft_find_position(*a, atemp->num);
		if (alistlen / 2 >= position)
			atemp->pushcost += (position - 1);
		else
			atemp->pushcost += (alistlen - position - 1);
		position = ft_find_position(*b, atemp->target->num);
		if (blistlen / 2 >= position)
			atemp->pushcost += (position - 1);
		else
			atemp->pushcost += (blistlen - position - 1);
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
		position = ft_find_position(*b, btemp->num);
		if (blistlen / 2 >= position)
			btemp->pushcost += (position - 1);
		else
			btemp->pushcost += (blistlen - position - 1);
		position = ft_find_position(*a, btemp->target->num);
		if (alistlen / 2 >= position)
			btemp->pushcost += (position - 1);
		else
			btemp->pushcost += (alistlen - position - 1);
		btemp = btemp->next;
	}
}

void	ft_turksort(t_list **a, t_list **b, t_data *data)
{
	while (ft_listlen(*a) > 3)
	{
		ft_target_smallest(a, b);
		ft_calccost_to_b(a, b);
	}
	ft_sort_3(a, b, data);
}
