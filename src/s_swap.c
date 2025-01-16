/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:47:38 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/16 20:11:42 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stack a/b. 
// Do nothing if there is only one or no elements.
void	ft_sa_sb(t_list *list, int operation)
{
	
	int temp;
	int temp2;
	if (ft_listlen(list) < 2)
		return ;
	temp = list->num;
	list = list->next;
	temp2 = list->num;
	list->num = temp;
	list = list->back;
	list->num = temp2;
	if(operation == 1)
		ft_printf("sa\n");
	else if(operation == 2)
		ft_printf("sb\n");	
}

void ft_ss(t_list *a, t_list *b)
{
	ft_sa_sb(a, 0);
	ft_sa_sb(b, 0);
	ft_printf("ss\n");	
}
