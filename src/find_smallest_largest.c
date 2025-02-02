/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_largest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:42:34 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/31 12:06:00 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_smallest_number(t_list **nd)
{
	t_list	*temp;
	int		smallest;

	temp = *nd;
	smallest = 2147483647;
	while (temp)
	{
		if (smallest > temp->num)
			smallest = temp->num;
		temp = temp->next;
	}
	return (smallest);
}

static int	ft_largest_number(t_list **nd)
{
	t_list	*temp;
	int		smallest;

	temp = *nd;
	smallest = -2147483648;
	while (temp->next != NULL)
	{
		if (smallest < temp->num)
			smallest = temp->num;
		temp = temp->next;
	}
	return (smallest);
}

void	ft_spot_numbers(t_list **nd, t_data *data)
{
	t_list	*temp;
	int position;

	if (!(*nd))
		return ;
	else
	{
		data->smallest_num = ft_smallest_number(nd);
		data->largest_num = ft_largest_number(nd);
	}
	temp = *nd;
	position = 1;
	while (temp->next != NULL)
	{
		if(data->smallest_num == temp->num)
			break;
		temp = temp->next;
		position++;
	}
	data->smallest_pos = position;
}
