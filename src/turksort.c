/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:30:24 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/13 22:01:46 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// linked list print function for testing purposes
void	print_linked_list(t_list *a, char c)
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

// static void	printtarget(t_list **a)
// {
// 	t_list	*temp;

// 	temp = *a;
// 	while (temp != NULL)
// 	{
// 		ft_printf("Num: %d -->> %d\n", temp->num, temp->target->num);
// 		temp = temp->next;
// 	}
// 	return ;
// }

static int	ft_cheapest_position(t_list *node)
{
	t_list	*temp;
	int		cheapest;

	temp = node;
	cheapest = INT_MAX;
	while (temp)
	{
		if (cheapest > temp->pushcost)
			cheapest = temp->pushcost;
		temp = temp->next;
	}
	temp = node;
	while (temp)
	{
		if (cheapest == temp->pushcost)
			break ;
		temp = temp->next;
	}
	return (ft_find_position(node, temp->num));
}

static void	ft_bringtotop(t_list **a, t_list **b, t_data *data, bool back)
{
	if (data->a_up == true && data->b_up == true)
		while (data->cheap_a-- > 1 && data->cheap_b-- > 1)
			ft_rr(a, b);
	else if (data->a_up == false && data->b_up == false)
		while (data->cheap_a++ <= ft_listlen(*a)
			&& data->cheap_b++ <= ft_listlen(*b))
			ft_rrr(a, b);
	if (data->a_up == true)
		while (data->cheap_a-- > 1)
			ft_ra(a);
	else
		while (data->cheap_a++ <= ft_listlen(*a))
			ft_rra(a);
	if (data->b_up == true)
		while (data->cheap_b-- > 1)
			ft_rb(b);
	else
		while (data->cheap_b++ <= ft_listlen(*b))
			ft_rrb(b);
	if (back == true)
		ft_pa(a, b);
	else
		ft_pb(a, b);
}

// second part of ft_turksort because of norminette
static void	ft_turksort_back(t_list **a, t_list **b, t_data *data, t_list *temp,
		int i)
{
	ft_sort_3(a, data);
	ft_printf("\n\n //// ZWEITER TEIL //// \n\n");
	print_linked_list(*a, 'a');
	print_linked_list(*b, 'b');
	while (ft_listlen(*b) != 0)
	{
		ft_target_largest(a, b, data);
		ft_calccost_to_a(a, b);
		temp = *b;
		i = 0;
		data->cheap_b = ft_cheapest_position(*b);
		while (++i != data->cheap_b)
			temp = temp->next;
		data->cheap_a = ft_find_position(*a, temp->target->num);
		if (ft_listlen(*b) / 2 >= data->cheap_b)
			data->b_up = true;
		else
			data->b_up = false;
		if (ft_listlen(*a) / 2 >= data->cheap_a)
			data->a_up = true;
		else
			data->a_up = false;
		ft_printf("cheap_a: %d // up: %d;   cheap_b: %d // up: %d\n", data->cheap_a,
				data->a_up, data->cheap_b, data->b_up);
		ft_bringtotop(a, b, data, true);
		print_linked_list(*a, 'a');
		print_linked_list(*b, 'b');
	}
	ft_spot_numbers(a, data);
	while (data->smallest_num != (*a)->num)
		ft_rra(a);
}

void	ft_turksort(t_list **a, t_list **b, t_data *data)
{
	t_list	*temp;
	int		i;

	print_linked_list(*a, 'a');
	print_linked_list(*b, 'b');
	while (ft_listlen(*a) > 3)
	{
		ft_target_smallest(a, b, data);
		ft_calccost_to_b(a, b);
		temp = *a;
		i = 0;
		data->cheap_a = ft_cheapest_position(*a);
		while (++i != data->cheap_a)
			temp = temp->next;
		data->cheap_b = ft_find_position(*b, temp->target->num);
		if (ft_listlen(*a) / 2 >= data->cheap_a)
			data->a_up = true;
		else
			data->a_up = false;
		if (ft_listlen(*b) / 2 >= data->cheap_b)
			data->b_up = true;
		else
			data->b_up = false;
		ft_printf("cheap_a: %d // up: %d;   cheap_b: %d // up: %d\n", data->cheap_a,
				data->a_up, data->cheap_b, data->b_up);
		ft_bringtotop(a, b, data, false);
		print_linked_list(*a, 'a');
		print_linked_list(*b, 'b');
	}
	ft_turksort_back(a, b, data, temp, i);
}
