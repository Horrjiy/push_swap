/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 21:54:19 by mpoplow          ###   ########.fr       */
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

//initializes a new node
t_list	*ft_init_node(int i, t_data *data, t_list *a)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		ft_error(data, a);
	node->num = data->arglist[i];
	node->next = NULL;
	node->target = NULL;
	return (node);
}

static void	ft_makelist(t_list **a, t_data *data)
{
	int	i;

	*a = ft_init_node(0, data, NULL);
	i = 1;
	while (i < data->numbers_counts)
	{
		ft_node_addback(a, ft_init_node(i, data, *a));
		i++;
	}
	data->op_count = 0;
}

static void	ft_sort_main(t_list **a, t_list **b, t_data *data)
{
	print_linked_list(*a, 'a');
	if (ft_checksorted(*a, *b) == false)
	{
		if (ft_listlen(*a) == 2)
			ft_sa(a);
		else if (ft_listlen(*a) == 3)
			ft_sort_3(a, b, data);
		else if (ft_listlen(*a) == 4)
		{
			ft_pb(a, b);
			ft_turksort(a, b, data);
		}
		else if (ft_listlen(*a) >= 5)
		{
			ft_pb(a, b);
			ft_pb(a, b);
			ft_turksort(a, b, data);
		}
	}
	print_linked_list(*a, 'a');
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*a;
	t_list	*b;

	data.source = NULL;
	ft_arg_convert(argc, argv, &data);
	b = NULL;
	ft_makelist(&a, &data);
	ft_dupcheck(&data, a);
	ft_sort_main(&a, &b, &data);
	ft_free_data(&data);
	ft_free_a(&a);
}

// while (ft_checksorted(a, b) == false)
// 	{
// 		ft_printf("check!:");
// 		print_linked_list(a, 'a');
// 		ft_sort(&a, &b, &data);
// 	}

//	ft_printf("Op_count: %d\nfinal:", data.op_count);