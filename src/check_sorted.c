/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:55:16 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/25 13:21:38 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_checksorted(t_list *a, t_list *b)
{
	t_list	*temp;
	int		i;

	if (!b)
	{
		if (!a || a->next == NULL)
			return (false);
		temp = a;
		while (temp->next != NULL)
		{
			i = temp->num;
			temp = temp->next;
			if (i > temp->num)
				return (false);
		}
	}
	else
		return (false);
	return (true);
}
