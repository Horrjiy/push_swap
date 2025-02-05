/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:47:11 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/05 17:49:22 by mpoplow          ###   ########.fr       */
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

static t_list	*ft_maximum_position(t_list **b, t_data *data)
{
	t_list	*temp;

	ft_spot_numbers(b, data);
	temp = *b;
	while (temp)
	{
		if (temp->num == data->largest_num)
			break ;
		temp = temp->next;
	}
	return (temp);
}

static t_list	*ft_minimum_position(t_list **a, t_data *data)
{
	t_list	*temp;

	ft_spot_numbers(a, data);
	temp = *a;
	while (temp)
	{
		if (temp->num == data->smallest_num)
			break ;
		temp = temp->next;
	}
	return (temp);
}

void	ft_target_smallest(t_list **a, t_list **b, t_data *data)
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
			atemp->target = ft_maximum_position(b, data);
		else
			atemp->target = targettemp;
		atemp = atemp->next;
	}
}

void	ft_target_largest(t_list **a, t_list **b, t_data *data)
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
				if (targettemp == NULL || atemp->num < targettemp->num)
					targettemp = atemp;
			atemp = atemp->next;
		}
		if (targettemp == NULL)
			btemp->target = ft_minimum_position(a, data);
		else
			btemp->target = targettemp;
		btemp = btemp->next;
	}
}
