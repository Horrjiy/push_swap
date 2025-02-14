/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:30:24 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/14 16:27:55 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_final_smallesttotop(t_list **a, t_data *data)
{
	ft_spot_numbers(a, data);
	if ((ft_listlen(*a) / 2) + 1 >= data->smallest_pos)
	{
		while (data->smallest_num != (*a)->num)
			ft_ra(a);
	}
	else
	{
		while (data->smallest_num != (*a)->num)
			ft_rra(a);
	}
}

static void	ft_bringtotop_helper(t_list **a, t_list **b, t_data *data)
{
	if (data->a_up == true && data->b_up == true)
	{
		while (data->cheap_a > 1 && data->cheap_b > 1)
		{
			ft_rr(a, b);
			data->cheap_a--;
			data->cheap_b--;
		}
	}
	else if (data->a_up == false && data->b_up == false)
	{
		while (data->cheap_a <= ft_listlen(*a)
			&& data->cheap_b <= ft_listlen(*b))
		{
			ft_rrr(a, b);
			data->cheap_a++;
			data->cheap_b++;
		}
	}
}

static void	ft_bringtotop(t_list **a, t_list **b, t_data *data, bool back)
{
	ft_bringtotop_helper(a, b, data);
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
static void	ft_turksort_back(t_list **a, t_list **b, t_data *data)
{
	t_list	*temp;
	int		i;

	ft_sort_3(a, data);
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
		if ((ft_listlen(*b) / 2) + 1 >= data->cheap_b)
			data->b_up = true;
		else
			data->b_up = false;
		if ((ft_listlen(*a) / 2) + 1 >= data->cheap_a)
			data->a_up = true;
		else
			data->a_up = false;
		ft_bringtotop(a, b, data, true);
	}
	ft_final_smallesttotop(a, data);
}

void	ft_turksort(t_list **a, t_list **b, t_data *data)
{
	t_list	*temp;
	int		i;

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
		if ((ft_listlen(*a) / 2) + 1 >= data->cheap_a)
			data->a_up = true;
		else
			data->a_up = false;
		if ((ft_listlen(*b) / 2) + 1 >= data->cheap_b)
			data->b_up = true;
		else
			data->b_up = false;
		ft_bringtotop(a, b, data, false);
	}
	ft_turksort_back(a, b, data);
}
