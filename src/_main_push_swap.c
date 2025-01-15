/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:41:19 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/15 12:49:12 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_list	*temp;
	t_data	data;
	int		i;

	ft_arg_convert(argc, argv, &data);
	list = ft_init_node(0, &data, list);
	i = 1;
	while (i < (argc - 1))
	{
		list->next = ft_init_node(i, &data, list);
		temp = list;
		list = list->next;
		list->back = temp;
		i++;
	}
}

t_list	*ft_init_node(int i, t_data *data, t_list *list)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		ft_error(&data, list);
	node->num = data->arglist[i];
	node->next = NULL;
	node->back = NULL;
}
