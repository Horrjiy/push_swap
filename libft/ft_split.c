/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:42:48 by mpoplow           #+#    #+#             */
/*   Updated: 2025/01/22 17:36:14 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	wordc;

	i = 0;
	wordc = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wordc++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wordc);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_all(char **dest, size_t d1)
{
	while (d1 > 0)
		free(dest[--d1]);
	free(dest);
	return (NULL);
}

static char	**cut(char const *s, char **dest, char c)
{
	size_t	si;
	size_t	d1;
	size_t	d2;

	si = 0;
	d1 = 0;
	while (s[si])
	{
		dest[d1] = malloc(wordlen(s + si, c) + 1);
		if (!dest[d1])
			return (free_all(dest, d1));
		d2 = 0;
		while (s[si] && s[si] != c)
			dest[d1][d2++] = s[si++];
		dest[d1++][d2] = '\0';
		while (s[si] == c)
			si++;
	}
	dest[d1] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	wordcount;

	if (!s)
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	wordcount = wordcounter(s, c);
	if (wordcount == 0)
		return (ft_calloc(sizeof(char *), 1));
	dest = malloc(sizeof(char *) * (wordcount + 1));
	if (!dest)
		return (NULL);
	return (cut(s, dest, c));
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*str;
// 	char	cha;
// 	char	**dst;
// 	int		i;

// 	i = 0;
// 	str = "hello!zzzzzzzz";
// 	cha = 'z';
// 	dst = ft_split(str, cha);
// 	while (dst[i])
// 	{
// 		printf("Final: %s\n", dst[i]);
// 		i++;
// 	}
// 	printf("Final: %s\n\n", dst[i]);
// 	system("leaks a.out");
// 	return (0);
// }
