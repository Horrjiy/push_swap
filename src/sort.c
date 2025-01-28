/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:08:25 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/28 19:08:14 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_list **a, t_list **b, t_data *data)
{
	if (*b == NULL || (*a)->num > (*b)->num)
	{
		ft_pb(a, b);
		data->op_count++;
	}
	else if ((*a)->num < (*b)->num)
	{
		ft_pa(a, b);
		ft_sa(a);
		data->op_count += 2; 
	}
	
}
