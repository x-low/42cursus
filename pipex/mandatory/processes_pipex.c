/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_pipex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:12:06 by xlow              #+#    #+#             */
/*   Updated: 2024/02/03 19:18:00 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	dup_fds(t_pipex info, int file, int *pipe, int io)
{
	if (dup2(file, io) < 0 || dup2(pipe[!io], !io) < 0)
	{
		perror("dup2");
		cleanup_pipex(info);
	}
	cleanup_fd(info.infile);
	cleanup_fd(info.outfile);
	cleanup_fd(pipe[io]);
	cleanup_fd(pipe[!io]);
}

static char	*verified_path(t_pipex info, int cmd)
{
	char	*path;
	char	*append;
	int		i;

	i = 0;
	append = ft_strjoin("/", info.cmds[cmd][0]);
	while (info.paths[i])
	{
		path = ft_strjoin(info.paths[i], append);
		if (!access(path, X_OK))
		{
			free(append);
			return (path);
		}
		free(path);
		i++;
	}
	free(append);
	return (NULL);
}

void	child(t_pipex info)
{
	char	*path;

	if (info.infile < 0)
	{
		perror("open");
		cleanup_pipex(info);
	}
	dup_fds(info, info.infile, info.fd, STDIN_FILENO);
	path = verified_path(info, 0);
	if (!path)
	{
		write(2, "command not found\n", 18);
		cleanup_pipex(info);
	}
	execve(path, info.cmds[0], info.env);
	perror("execve");
	if (path)
		free(path);
	cleanup_pipex(info);
}

void	parent(t_pipex info)
{
	char	*path;

	if (info.outfile < 0)
	{
		perror("open");
		cleanup_pipex(info);
	}
	waitpid(info.pid, NULL, WNOHANG);
	dup_fds(info, info.outfile, info.fd, STDOUT_FILENO);
	path = verified_path(info, 1);
	if (!path)
	{
		write(2, "command not found\n", 18);
		cleanup_pipex(info);
	}
	execve(path, info.cmds[1], info.env);
	perror("execve");
	if (path)
		free(path);
	cleanup_pipex(info);
}
