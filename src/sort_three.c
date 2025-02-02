/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:08:25 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 15:09:01 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3(t_list **a, t_list **b, t_data *data)
{
	if ((*a)->num < (*a)->next->num && (*a)->next->num < (*a)->next->next->num)
		return ;
	ft_spot_numbers(a, data);
	if (data->smallest_pos == 1)
	{
		ft_pb(a, b);
		ft_sa(a);
		ft_pa(a, b);
	}
	else if (data->smallest_pos == 2 || data->smallest_pos == 3)
	{
		if (data->smallest_pos == 2)
			ft_ra(a);
		else if (data->smallest_pos == 3)
			ft_rra(a);
		if (ft_checksorted(*a, *b) == true)
			return ;
		ft_pb(a, b);
		ft_sa(a);
		ft_pa(a, b);
	}
}
