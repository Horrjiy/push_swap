/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:31:58 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/16 12:24:26 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_init_node(int i, t_data *data, t_list *a)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		ft_error(data, a);
	node->num = data->arglist[i];
	node->next = NULL;
	node->back = NULL;
	return (node);
}

int	ft_listlen(t_list *a)
{
	t_list	*temp;
	int		i;

	temp = a;
	if (!temp)
		return (0);
	i = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_list	*ft_lastnode(t_list *a)
{
	t_list	*temp;

	temp = a;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_node_addback(t_list **a, t_list *node)
{
	t_list *temp;

	if (!node)
		return ;
	if (!a)
	{
		*a = node;
		return ;
	}
	temp = ft_lastnode(*a);
	node->back = temp;
	temp->next = node;
}
