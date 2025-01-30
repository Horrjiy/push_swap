/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:08:25 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/30 18:32:50 by mpoplow          ###   ########.fr       */
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

void	ft_sort(t_list **a, t_list **b, t_data *data)
{
	if (!(*a))
	{
		if (ft_check_reverse_sorted == true)
			while (*b)
				ft_pa(a, b);
	}
	else if (*a)
	{
		ft_spot_numbers(a, data);
		if (data->smallest_pos > (ft_listlen(*a) / 2))
			while ((*a)->num != data->smallest_num)
				ft_rra(a);
		else
			while ((*a)->num != data->smallest_num)
				ft_ra(a);
	}
}
