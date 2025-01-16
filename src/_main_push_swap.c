/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/16 20:17:46 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*a;
	int		i;

	ft_arg_convert(argc, argv, &data);
	a = ft_init_node(0, &data, NULL);
	i = 1;
	while (i < (argc - 1))
	{
		ft_node_addback(&a, ft_init_node(i, &data, a));
		i++;
	}
	
}

// static void print_linked_list(t_list *a)
// {
//     t_list *current = a; // Start at the head of the list

//     while (current != NULL) // Traverse the list until the end
//     {
//         ft_printf("%d -> ", current->num); // Print the data in the current node
//         current = current->next; // Move to the next node
//     }
//     ft_printf("NULL\n"); // End of the list
// }

// print_linked_list(a);
// ft_sa_sb(a, 1);
// print_linked_list(a);