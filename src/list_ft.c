/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:31:58 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/02 14:25:13 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//initializes a new node
t_list	*ft_init_node(int i, t_data *data, t_list *a)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		ft_error(data, a);
	node->num = data->arglist[i];
	node->next = NULL;
	node->target = NULL;
	return (node);
}

//retunrs the length of the linked list
int	ft_listlen(t_list *a)
{
	t_list	*temp;
	int		i;

	if (!a)
		return (0);
	temp = a;
	i = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

//returns the last node of the linked list
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

//returns the second last node of the linked list
t_list	*ft_secondlastnode(t_list *a)
{
	t_list	*temp;

	temp = a;
	if (!temp)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_node_addback(t_list **a, t_list *node)
{
	t_list	*temp;

	if (!node)
		return ;
	if (!a)
	{
		*a = node;
		return ;
	}
	temp = ft_lastnode(*a);
	temp->next = node;
}
