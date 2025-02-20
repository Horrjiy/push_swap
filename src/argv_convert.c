/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:20:32 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/15 13:18:53 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//like ft_atol, but nothing else than numbers and one sign are allowed.
static int	ft_atol_strict(const char *str, t_data *data)
{
	int		i;
	long	value;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '\0')
			ft_error(data, NULL);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(data, NULL);
		i++;
	}
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN || i > 11)
		ft_error(data, NULL);
	return (value);
}

//converts the one argumument case input to a **char
static void	ft_argvstring(char *str, t_data *data)
{
	int	i;

	data->split_used = true;
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
static void	ft_argc_check(int argc, char *argv[], t_data *data)
{
	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		ft_argvstring(argv[1], data);
	}
	else
	{
		data->source = argv + 1;
		data->split_used = false;
		data->numbers_counts = argc - 1;
	}
}

void	ft_arg_convert(int argc, char *argv[], t_data *data, t_list **a)
{
	int	i;

	ft_argc_check(argc, argv, data);
	i = 1;
	*a = ft_init_node(ft_atol_strict(data->source[0], data), data, NULL);
	while (i < data->numbers_counts)
	{
		ft_node_addback(a, ft_init_node(ft_atol_strict(data->source[i], data),
				data, *a));
		i++;
	}
}
