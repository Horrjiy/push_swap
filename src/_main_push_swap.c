/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/20 15:58:15 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*a;
	t_list	*b;
	int		i;

	ft_arg_convert(argc, argv, &data);
	b = NULL;
	a = ft_init_node(0, &data, NULL);
	i = 1;
	while (i < (argc - 1))
	{
		ft_node_addback(&a, ft_init_node(i, &data, a));
		i++;
	}
}

// static void	print_linked_list(t_list *a, char c)
// {
// 	t_list *current = a; // Start at the head of the list
// 	write(1, &c, 1);
// 	write(1, ": ", 2);
// 	while (current != NULL) // Traverse the list until the end
// 	{
// 		ft_printf("%d -> ", current->num); // Print the data in the current node
// 		current = current->next;           // Move to the next node
// 	}
// 	ft_printf("NULL\n"); // End of the list
// }

// print_linked_list(a, 'a');
// ft_sa(&a);
// print_linked_list(a, 'a');
// print_linked_list(b, 'b');
// ft_pb(&a, &b);
// ft_pb(&a, &b);
// print_linked_list(a, 'a');
// ft_sa(&a);
// print_linked_list(a, 'a');
// print_linked_list(b, 'b');
// ft_sb(&b);
// print_linked_list(b, 'b');