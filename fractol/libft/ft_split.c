/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:34:07 by xlow              #+#    #+#             */
/*   Updated: 2023/09/24 00:56:04 by xlow             ###   ########.fr       */
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

/*int	main(void)
{
	char **str = ft_split("piece of shit", ' ');
	printf("%s", str[0]);
	free(str);
	return (0);
}*/
