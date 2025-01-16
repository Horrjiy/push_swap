/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:33:36 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/16 13:04:58 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_error(t_data *data, t_list *a)
{
	write(2, "Error\n", 6);
	exit(2);
	free_data(data);
	(void)a;
}
              
void ft_free_data(t_data *data)
{
	free(data->arglist);
	free(data->dup_check);
}

