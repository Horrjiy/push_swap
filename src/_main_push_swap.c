/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/13 16:44:53 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*head;
	t_data	data;
	int		i;
	t_list	*node;

	ft_arg_convert(argc, argv, &data);
	i = 0;
	while (i < (argc - 1))
	{
	}
}

t_list	*ft_init_node(int i, t_data *data, t_list *head)
{
	t_list *node;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		ft_error(&data, head);
	node->num = data->arglist[i];
	node->next = NULL;
	node->back = NULL;
		i++;
}
