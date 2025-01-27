/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/27 15:34:39 by mpoplow          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*a;
	t_list	*b;
	int		i;

	data.source = NULL;
	ft_arg_convert(argc, argv, &data);
	b = NULL;
	a = ft_init_node(0, &data, NULL);
	i = 1;
	while (i < data.numbers_counts)
	{
		ft_node_addback(&a, ft_init_node(i, &data, a));
		i++;
	}
	while (ft_checksorted(a, b) == false)
	{
		print_linked_list(a, 'a');
		ft_sort(&a, &b);
	}
	ft_printf("final:");
	print_linked_list(a, 'a');
	ft_free_data(&data);
	(void)argv;
}
