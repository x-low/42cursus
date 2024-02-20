/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:34:07 by xlow              #+#    #+#             */
/*   Updated: 2024/02/20 16:21:04 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

static char	**ft_free_on_failure(char **res, size_t i)
{
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t				i;
	char const			*start;
	char				**res;

	i = 0;
	res = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s != c && *s)
				s++;
			res[i++] = ft_substr(start, 0, s - start);
			if (!res[i - 1])
				return (ft_free_on_failure(res, i));
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
/*
int	main(void)
{
	char *strings = NULL;
//	char *s = "\0";
//	char c = ' ';
	// int i = 0;
	// while (strings[i])
	// {
	// 	printf("word %i is %s\n", i, strings[i]);
	// 	i++;
	// }
	// ft_freewords(strings, i);
	printf("%s\n", ft_split(strings, ' ')[0]);
}*/
