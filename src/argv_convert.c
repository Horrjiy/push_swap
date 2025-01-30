/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:20:32 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/29 16:12:43 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//like ft_atoi, but nothing else than numbers and one sign are allowed.
static int	ft_atoi_strict(const char *str, t_data *data)
{
	int	i;
	int	signcount;

	i = 0;
	signcount = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			signcount++;
		else
		{
			if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
				&& str[i] != '+')
				ft_error(data, NULL);
			if (signcount > 1)
				ft_error(data, NULL);
		}
		i++;
	}
	return (ft_atoi(str));
}

//converts the one argumument case input to a **char
static void	ft_argvstring(char *str, t_data *data)
{
	int	i;

	data->source = ft_split(str, ' ');
	if (!data->source)
		ft_error(data, NULL);
	i = 0;
	while (data->source[i])
	{
		if (!data->source[i][0])
			ft_error(data, NULL);
		i++;
	}
	if (i < 1)
		ft_error(data, NULL);
	data->numbers_counts = i;
}

//checks if there is an argument input and handles the single argument case
static int	ft_argc_check(int argc, char *argv[], t_data *data)
{
	if (argc < 2)
		return (ft_error(NULL, NULL), -1);
	else if (argc == 2)
	{
		ft_argvstring(argv[1], data);
		return (0);
	}
	else
		return (1);
}

void	ft_arg_convert(int argc, char *argv[], t_data *data)
{
	int i;

	i = 0;
	if (ft_argc_check(argc, argv, data) == 1)
	{
		data->source = argv + 1;
		data->split_used = false;
		data->numbers_counts = argc - 1;
	}
	else
		data->split_used = true;
	data->arglist = malloc((data->numbers_counts) * sizeof(int));
	if (!data->arglist)
		ft_error(data, NULL);
	while (i < data->numbers_counts)
	{
		data->arglist[i] = ft_atoi_strict(data->source[i], data);
		i++;
	}
}

void	ft_dupcheck(t_data *data, t_list *a)
{
	t_list	*temp;
	t_list	*temp2;

	temp = a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->num == temp2->num)
				ft_error(data, a);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}