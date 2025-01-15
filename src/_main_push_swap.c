/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/15 17:49:19 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_list	*a;
	int		i;

	ft_arg_convert(argc, argv, &data);
	a = ft_init_node(0, &data, NULL);
	i = 1;
	while (i < (argc - 1))
	{
		ft_node_addback(&a, ft_init_node(i, &data, a));
		i++;
	}
}
