/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:01:18 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/14 14:49:35 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ft_ra(t_list **a)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*a) < 2)
		return ;
	temp = *a;
	*a = temp->next;
	temp->next = NULL;
	temp2 = ft_lastnode(*a);
	temp2->next = temp;
	ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ft_rb(t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*b) < 2)
		return ;
	temp = *b;
	*b = temp->next;
	temp->next = NULL;
	temp2 = ft_lastnode(*b);
	temp2->next = temp;
	ft_printf("rb\n");
}

// rr : ra and rb at the same time.
void	ft_rr(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(*a) < 2 && ft_listlen(*b) < 2)
		return ;
	if (!(ft_listlen(*a) < 2))
	{
		temp = *a;
		*a = temp->next;
		temp->next = NULL;
		temp2 = ft_lastnode(*a);
		temp2->next = temp;
	}
	if (!(ft_listlen(*b) < 2))
	{
		temp = *b;
		*b = temp->next;
		temp->next = NULL;
		temp2 = ft_lastnode(*b);
		temp2->next = temp;
	}
	ft_printf("rr\n");
}
