/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:16:19 by xlow              #+#    #+#             */
/*   Updated: 2023/10/22 14:14:07 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	void			*res;
	size_t			len;

	len = nmemb * size;
	res = malloc(len);
	if (!res)
		return (NULL);
	p = res;
	while (len)
	{
		*(p++) = 0;
		len--;
	}
	return (res);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	res = gnl_calloc(i + j + 1, 1);
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	return (res);
}

char	*gnl_strdup(char *s)
{
	char	*res;
	int		i;

	if (!s)
		return (gnl_strdup(""));
	i = 0;
	while (s[i])
		i++;
	res = gnl_calloc(i + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

int	is_there_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
