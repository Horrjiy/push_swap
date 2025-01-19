/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:47:38 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/19 19:58:10 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	ft_sa(t_list *a)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_listlen(a) < 2)
		return ;
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	ft_sb(t_list *b)
{
	if (ft_listlen(b) < 2)
		return ;
}

// ss: sa and sb at the same time.
void	ft_ss(t_list *a, t_list *b)
{
	ft_sa(a);
	ft_sb(b);
}
