/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:47:11 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 18:31:42 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_target_smallest(t_list **a, t_list **b)
{
	t_list	*atemp;
	t_list	*btemp;
	t_list	*targettemp;

	btemp = *b;
	while (btemp)
	{
		btemp->target = NULL;
		btemp = btemp->next;
	}
	atemp = *a;
	while (atemp)
	{
		btemp = *b;
		while (btemp)
		{
			if (btemp->num < atemp->num)
				if (targettemp == NULL || btemp->num > targettemp->num)
					targettemp = btemp;
			btemp = btemp->next;
		}
		atemp = atemp->next;
	}
}

void	ft_target_largest(t_list **a, t_list **b)
{
	t_list	*atemp;
	t_list	*btemp;
	t_list	*targettemp;

	atemp = *a;
	while (atemp)
	{
		atemp->target = NULL;
		atemp = atemp->next;
	}
	btemp = *b;
	while (btemp)
	{
		atemp = *a;
		while (atemp)
		{
			if (atemp->num > btemp->num)
				if (targettemp == NULL || atemp->num > targettemp->num)
					targettemp = atemp;
			atemp = atemp->next;
		}
		btemp = btemp->next;
	}
}
