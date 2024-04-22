/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:11:57 by xlow              #+#    #+#             */
/*   Updated: 2024/02/01 19:04:40 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_on_exit(char *msg)
{
	perror(msg);
	exit(errno);
}

void	cleanup_fd(int fd)
{
	if (fd != -1)
	{
		close(fd);
		fd = -1;
	}
}

void	cleanup_pipex(t_pipex info)
{
	int	i;

	i = 0;
	while (info.cmds[i])
	{
		ft_free_split(info.cmds[i]);
		i++;
	}
	free(info.cmds);
	ft_free_split(info.paths);
	cleanup_fd(info.infile);
	cleanup_fd(info.outfile);
	cleanup_fd(info.fd[0]);
	cleanup_fd(info.fd[1]);
	exit(errno);
}
