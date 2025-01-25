/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:08:25 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/25 13:47:01 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sort(t_list *a, t_list *b)
{
	if (a->num > a->next->num)
	{
		ft_sa(&a);
		ft_ra(&a);
	}
	else if(a->num < a->next->num)
		ft_ra(&a);
	(void)b;
}
