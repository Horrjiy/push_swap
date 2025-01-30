/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/29 19:52:30 by mpoplow          ###   ########.fr       */
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

//prepares everything for the sorting algorythm
static void	ft_init_sorting(t_list **a, t_data *data)
{
	int	i;
	
	i = 1;
	while (i < data->numbers_counts)
	{
		ft_node_addback(a, ft_init_node(i, data, *a));
		i++;
	}
	ft_dupcheck(data, *a);
	data->op_count = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*a;
	t_list	*b;

	data.source = NULL;
	ft_arg_convert(argc, argv, &data);
	b = NULL;
	a = ft_init_node(0, &data, NULL);
	ft_init_sorting(&a, &data);
	print_linked_list(a, 'a');
	print_linked_list(b, 'b');
	while (ft_checksorted(a, b) == false)
	{
		ft_sort(&a, &b, &data);
	}
	ft_printf("Op_count: %d\nfinal:", data.op_count);
	print_linked_list(a, 'a');
	ft_free_data(&data);
	ft_free_a(&a);
}
