/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:08:25 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 16:41:52 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3(t_list **a, t_data *data)
{
	ft_spot_numbers(a, data);
	if(data->largest_pos == 1)
		ft_ra(a);
	else if(data->largest_pos == 2)
		ft_rra(a);
	if((*a)->num > (*a)->next->num)
		ft_ra(a);
}

void	ft_sort_4(t_list **a, t_list **b, t_data *data)
{
	ft_spot_numbers(a, data);
	if (data->smallest_pos == 1)
		ft_pb(a, b);
	else if (data->smallest_pos == 2)
	{
		ft_ra(a);
		ft_pb(a, b);
	}
	else if (data->smallest_pos == 3)
	{
		ft_rra(a);
		ft_rra(a);
		ft_pb(a, b);
	}
	else if (data->smallest_pos == 4)
	{
		ft_rra(a);
		ft_pb(a, b);
	}
	ft_sort_3(a, data);
	ft_pa(a, b);
}

void	ft_sort_5(t_list **a, t_list **b, t_data *data)
{
	ft_spot_numbers(a, data);
	if (data->smallest_pos == 1 || data->smallest_pos == 2)
	{
		while (data->smallest_num != (*a)->num)
			ft_ra(a);
	}
	else
	{
		while (data->smallest_num != (*a)->num)
			ft_rra(a);
	}
	ft_pb(a, b);
	ft_sort_4(a, b, data);
	ft_pa(a, b);
}
