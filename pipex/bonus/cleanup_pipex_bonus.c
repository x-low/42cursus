/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_pipex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:11:57 by xlow              #+#    #+#             */
/*   Updated: 2024/02/03 19:16:34 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	flush_err(char *msg, char *cmd)
{
	int	err;

	err = dup(STDERR_FILENO);
	ft_printf_fd(STDERR_FILENO, msg, cmd);
	close(STDERR_FILENO);
	dup2(err, STDERR_FILENO);
	close(err);
}

void	error_on_exit(char *msg)
{
	perror(msg);
	exit(errno);
}

void	cleanup_fd(int *fd)
{
	if (*fd != -1)
	{
		close(*fd);
		*fd = -1;
	}
}

void	cleanup_pipex(t_pipex info, char *msg)
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
	cleanup_fd(&info.infile);
	cleanup_fd(&info.outfile);
	cleanup_fd(&info.fd[0]);
	cleanup_fd(&info.fd[1]);
	if (msg)
		error_on_exit(msg);
	exit(errno);
}
