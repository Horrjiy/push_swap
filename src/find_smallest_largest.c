/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_largest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:42:34 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/14 15:10:32 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_smallest_number(t_list **nd)
{
	t_list	*temp;
	int		smallest;

	temp = *nd;
	smallest = INT_MAX;
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
	int		largest;

	temp = *nd;
	largest = INT_MIN;
	while (temp)
	{
		if (largest < temp->num)
			largest = temp->num;
		temp = temp->next;
	}
	return (largest);
}

static void	ft_number_positions(t_list **nd, t_data *data)
{
	t_list	*temp;
	int		position;

	temp = *nd;
	position = 1;
	while (temp->next != NULL)
	{
		if (data->smallest_num == temp->num)
			break ;
		temp = temp->next;
		position++;
	}
	data->smallest_pos = position;
	temp = *nd;
	position = 1;
	while (temp->next != NULL)
	{
		if (data->largest_num == temp->num)
			break ;
		temp = temp->next;
		position++;
	}
	data->largest_pos = position;
}

void	ft_spot_numbers(t_list **nd, t_data *data)
{
	if (!(*nd))
		return ;
	else
	{
		data->smallest_num = ft_smallest_number(nd);
		data->largest_num = ft_largest_number(nd);
	}
	ft_number_positions(nd, data);
}
