/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:20:32 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/06 19:34:04 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_argc_check(int argc, char *argv[])
{
	if (argc <= 1)
		ft_error("no input");
	else if (argc == 2)
	{
		ft_printf("%d", ft_atoi_strict(argv[1]));
		exit(0);
	}
	else
		return ;
}

//like ft_atoi, but nothing else than numbers and one '-' are allowed.
static int	ft_atoi_strict(const char *str)
{
	int	i;
	int	minuscount;

	i = 0;
	minuscount = 0;
	while (str[i])
	{
		if (str[i] == '-')
			minuscount++;
		else
		{
			if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
				ft_error("invalid characters used!");
			if (minuscount > 1)
				ft_error("");
		}
		i++;
	}
	return (ft_atoi(str));
}

int	*ft_arg_convert(int argc, char *argv[])
{
	int	*values;

	ft_argc_check(argc, argv);
	while ()
		return ();
}
