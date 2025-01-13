/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:20:32 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/13 15:14:36 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//like ft_atoi, but nothing else than numbers and one '-' are allowed.
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

//checks if there is an argument input and handles the one argument case
static void	ft_argc_check(int argc, char *argv[])
{
	if (argc <= 1)
		ft_error(NULL, NULL);
	else if (argc == 2)
	{
		exit(0);
	}
	else
		return ;
}

void	ft_arg_convert(int argc, char *argv[], t_data *data)
{
	int	i;

	ft_argc_check(argc, argv);
	data->arglist = malloc((argc - 1) * sizeof(int));
	if (!data->arglist)
		ft_error(data, NULL);
	i = 0;
	while (i <= (argc - 2))
	{
		data->arglist[i] = ft_atoi_strict(argv[i + 1], data);
		i++;
	}
}
