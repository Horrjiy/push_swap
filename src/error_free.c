/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:33:36 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 13:19:00 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_data *data, t_list *a)
{
	write(2, "Error\n", 6);
	if (data == NULL && a == NULL)
		exit(2);
	ft_free_data(data);
	ft_free_a(&a);
	exit(2);
}

//frees all malloced variables from the data struct.
void	ft_free_data(t_data *data)
{
	int	i;

	if (data->source && data->split_used == true)
	{
		i = 0;
		while (data->source[i])
		{
			free(data->source[i]);
			data->source[i++] = NULL;
		}
		free(data->source);
		data->source = NULL;
	}
}

void	ft_free_a(t_list **a)
{
	t_list	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	*a = NULL;
}
