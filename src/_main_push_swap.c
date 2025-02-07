/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/07 15:27:39 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//initializes a new node
t_list	*ft_init_node(int i, t_data *data, t_list *a)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		ft_error(data, a);
	node->num = i;
	node->next = NULL;
	node->target = NULL;
	return (node);
}

//Checks if every value exists only once in a->num.
//Exits with an error in case of duplicates.
static void	ft_dupcheck(t_data *data, t_list *a)
{
	t_list	*temp;
	t_list	*temp2;

	temp = a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->num == temp2->num)
				ft_error(data, a);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

static void	ft_sort_main(t_list **a, t_list **b, t_data *data)
{
	if (ft_checksorted(*a, *b) == false)
	{
		if (ft_listlen(*a) == 2)
			ft_sa(a);
		else if (ft_listlen(*a) == 3)
			ft_sort_3(a, b, data);
		else if (ft_listlen(*a) == 4)
			ft_sort_4(a, b, data);
		else if (ft_listlen(*a) == 5)
			ft_sort_5(a, b, data);
		else if (ft_listlen(*a) >= 6)
		{
			ft_pb(a, b);
			ft_pb(a, b);
			ft_turksort(a, b, data);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*a;
	t_list	*b;

	data.source = NULL;
	b = NULL;
	ft_arg_convert(argc, argv, &data, &a);
	ft_dupcheck(&data, a);
	ft_sort_main(&a, &b, &data);
	ft_free_data(&data);
	ft_free_a(&a);
}

// linked list print function for testing purposes
// void	print_linked_list(t_list *a, char c)
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

// system("leaks push_swap");