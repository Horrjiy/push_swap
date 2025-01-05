/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthex_capx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:54 by mpoplow           #+#    #+#             */
/*   Updated: 2024/12/02 17:04:55 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthexc(unsigned int cast)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (write(1, &str[cast], 1) == -1)
		return (-1);
	return (0);
}

static int	ft_putnbr_hexc(unsigned int n, int *wrc)
{
	unsigned long	cast;

	if (n < 0)
		cast = (unsigned long)(-n);
	else
		cast = (unsigned long)n;
	if (cast == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		(*wrc)++;
		return (0);
	}
	if (cast >= 16)
	{
		if (ft_putnbr_hexc((cast / 16), wrc) == -1)
			return (-1);
	}
	(*wrc)++;
	if (ft_puthexc((cast % 16)) == -1)
		return (-1);
	return (0);
}

int	capxfound(int f, int *wrc)
{
	if (ft_putnbr_hexc(f, wrc) == -1)
		return (-1);
	return (0);
}
