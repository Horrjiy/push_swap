/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:08:25 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 14:33:12 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// linked list print function for testing purposes
static void	print_linked_list(t_list *a, char c)
{
	t_list *current = a; // Start at the head of the list
	write(1, &c, 1);
	write(1, ": ", 2);
	while (current != NULL) // Traverse the list until the end
	{
		ft_printf("%d -> ", current->num); // Print the data in the current node
		current = current->next;           // Move to the next node
	}
	ft_printf("NULL\n"); // End of the list
}

void	ft_sort_3(t_list **a, t_list **b, t_data *data)
{
	ft_spot_numbers(a, data);
	if (data->smallest_pos == 1)
	{
		ft_pb(a, b);
		ft_sa(a);
		ft_pa(a, b);
	}
	else if (data->smallest_pos == 2)
	{
		ft_ra(a);
		if (ft_checksorted(*a, *b) == true)
			return ;
		ft_pb(a, b);
		ft_sa(a);
		ft_pa(a, b);
	}
	else if (data->smallest_pos == 3)
	{
		ft_rra(a);
		if (ft_checksorted(*a, *b) == true)
			return ;
		ft_pb(a, b);
		ft_sa(a);
		ft_pa(a, b);
	}
}

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 2 1
// 3 1 2