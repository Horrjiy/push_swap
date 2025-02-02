/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:47:11 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 21:46:48 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	target_null(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	while (temp)
	{
		temp->target = NULL;
		temp = temp->next;
	}
	temp = *a;
	while (temp)
	{
		temp->target = NULL;
		temp = temp->next;
	}
}

void	ft_target_smallest(t_list **a, t_list **b)
{
	t_list	*atemp;
	t_list	*btemp;
	t_list	*targettemp;

	target_null(a, b);
	atemp = *a;
	while (atemp)
	{
		btemp = *b;
		targettemp = NULL;
		while (btemp)
		{
			if (btemp->num < atemp->num)
				if (targettemp == NULL || btemp->num > targettemp->num)
					targettemp = btemp;
			btemp = btemp->next;
		}
		if (targettemp == NULL)
			atemp->target = ft_lastnode(*b);
		else
			atemp->target = targettemp;
		atemp = atemp->next;
	}
}

void	ft_target_largest(t_list **a, t_list **b)
{
	t_list	*atemp;
	t_list	*btemp;
	t_list	*targettemp;

	target_null(a, b);
	btemp = *b;
	while (btemp)
	{
		atemp = *a;
		targettemp = NULL;
		while (atemp)
		{
			if (atemp->num > btemp->num)
				if (targettemp == NULL || atemp->num > targettemp->num)
					targettemp = atemp;
			atemp = atemp->next;
		}
		if (targettemp == NULL)
			btemp->target = *a;
		else
			btemp->target = targettemp;
		btemp = btemp->next;
	}
}
