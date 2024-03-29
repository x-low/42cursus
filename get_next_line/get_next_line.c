/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:47:39 by xlow              #+#    #+#             */
/*   Updated: 2023/10/13 20:27:28 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	to_retrieve(int fd, char **storage, char **hold)
{
	char	*buffer;
	int		rd;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return ;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			ft_free(&buffer, hold, storage);
			return ;
		}
		buffer[rd] = 0;
		*hold = ft_strdup(*storage);
		ft_free(storage, 0, 0);
		*storage = ft_strjoin(*hold, buffer);
		ft_free(hold, 0, 0);
		if (is_there_nl(*storage))
			break ;
	}
	ft_free(&buffer, 0, 0);
}

char	*to_print(char *hold)
{
	char	*res;
	int		i;

	i = 0;
	while (hold[i] != '\n' && hold[i])
		i++;
	if (hold[i] == '\n')
		i++;
	res = ft_calloc(i + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (hold[i] != '\n' && hold[i])
	{
		res[i] = hold[i];
		i++;
	}
	if (hold[i] && hold[i] == '\n')
		res[i] = hold[i];
	return (res);
}

char	*to_save(char *hold)
{
	char	*store;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (hold[i] != '\n' && hold[i])
		i++;
	if (hold[i] == '\n')
		i++;
	while (hold[j])
		j++;
	store = ft_calloc(j - i + 1, 1);
	if (!store)
		return (NULL);
	j = 0;
	while (hold[i + j])
	{
		store[j] = hold[i + j];
		j++;
	}
	return (store);
}

void	to_assign(char **storage, char *hold, char **res)
{
	*storage = to_save(hold);
	*res = to_print(hold);
	ft_free(&hold, 0, 0);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*hold;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hold = NULL;
	res = NULL;
	to_retrieve(fd, &storage, &hold);
	if (storage && *storage)
	{
		hold = ft_strdup(storage);
		ft_free(&storage, 0, 0);
		to_assign(&storage, hold, &res);
	}
	if (!res || !*res)
	{
		ft_free(&storage, &hold, &res);
		return (NULL);
	}
	return (res);
}
