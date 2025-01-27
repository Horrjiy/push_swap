/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:33:36 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/27 13:25:35 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_data *data, t_list *a)
{
	write(2, "Error\n", 6);
	exit(2);
	ft_free_data(data);
	(void)a;
}

//frees all malloced variables from the data struct.
void	ft_free_data(t_data *data)
{
	int	i;

	if (data->arglist)
	{
		free(data->arglist);
		data->arglist = NULL;
	}
	if (data->dup_check)
	{
		free(data->dup_check);
		data->dup_check = NULL;
	}
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
