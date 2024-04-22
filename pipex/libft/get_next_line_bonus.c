/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 06:14:49 by xlow              #+#    #+#             */
/*   Updated: 2023/10/22 14:13:29 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	to_retrieve(int fd, char **storage, char **hold)
{
	char	*buffer;
	int		rd;

	buffer = gnl_calloc(BUFFER_SIZE + 1, 1);
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
		*hold = gnl_strdup(*storage);
		ft_free(storage, 0, 0);
		*storage = gnl_strjoin(*hold, buffer);
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
	res = gnl_calloc(i + 1, 1);
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
	if (!(j - i))
		return (NULL);
	store = gnl_calloc(j - i + 1, 1);
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
	static char	*storage[1024];
	char		*hold;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	hold = 0;
	res = 0;
	to_retrieve(fd, &storage[fd], &hold);
	if (storage[fd] && *storage[fd])
	{
		hold = gnl_strdup(storage[fd]);
		ft_free(&storage[fd], 0, 0);
		to_assign(&storage[fd], hold, &res);
	}
	if (!res || !*res)
	{
		ft_free(&storage[fd], &hold, &res);
		return (NULL);
	}
	return (res);
}
