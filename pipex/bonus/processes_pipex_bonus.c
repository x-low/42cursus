/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_pipex_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:12:06 by xlow              #+#    #+#             */
/*   Updated: 2024/02/29 21:22:24 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	dup_fds(t_pipex *info, int file, int *new, int io)
{
	if (file)
	{
		if (dup2(file, io) < 0 || dup2(info->fd[!io], !io) < 0)
			cleanup_pipex(*info, "dup2");
		cleanup_fd(&info->fd[0]);
		cleanup_fd(&info->fd[1]);
	}
	else
	{
		if (dup2(info->fd[1], !io) < 0)
			cleanup_pipex(*info, "dup2");
		cleanup_fd(&info->fd[0]);
		cleanup_fd(&info->fd[1]);
		if (dup2(new[0], io))
			cleanup_pipex(*info, "dup2");
		cleanup_fd(&new[0]);
		cleanup_fd(&new[1]);
	}
	cleanup_fd(&info->infile);
	cleanup_fd(&info->outfile);
}

/*
static void	dup_fds(t_pipex *info, int file, int *fd, int io)
{
	int	new[2];

	if (file)
	{
		if (dup2(file, io) < 0 || dup2(fd[!io], !io) < 0)
			cleanup_pipex(*info, "dup2");
		cleanup_fd(fd[0]);
		cleanup_fd(fd[1]);
	}
	else
	{
		if (dup2(fd[1], !io) < 0)
			cleanup_pipex(*info, "dup2");
		if (pipe(new) < 0)
			cleanup_pipex(*info, "pipe");
		if (dup2(new[0], io))
			cleanup_pipex(*info, "dup2");
		cleanup_fd(info->fd[0]);
		cleanup_fd(info->fd[1]);
		info->fd[0] = new[0];
		info->fd[1] = new[1];
	}
	cleanup_fd(info->infile);
	cleanup_fd(info->outfile);
}*/

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

static void	final_fork(t_pipex info)
{
	char	*path;

	if (info.infile < 0)
		cleanup_pipex(info, "open");
	path = verified_path(info, info.cmd_index);
	if (!path)
	{
		flush_err("command not found: %s\n", info.cmds[0][0]);
		cleanup_pipex(info, NULL);
	}
	dup_fds(&info, info.infile, 0, STDIN_FILENO);
	execve(path, info.cmds[0], info.env);
	free(path);
	cleanup_pipex(info, "execve");
}

void	child(t_pipex info)
{
	char	*path;
	int		new[2];

	if (!info.cmd_index)
		final_fork(info);
	if (pipe(new) < 0)
		cleanup_pipex(info, "pipe");
	info.cmd_index--;
	info.pid = fork();
	if (info.pid < 0)
		cleanup_pipex(info, "fork");
	if (!info.pid)
	{
		info.fd[0] = new[0];
		info.fd[1] = new[1];
		child(info);
	}
	waitpid(info.pid, NULL, WNOHANG);
	path = verified_path(info, info.cmd_index + 1);
	if (!path)
	{
		flush_err("command not found: %s\n", info.cmds[info.cmd_index + 1][0]);
		cleanup_pipex(info, NULL);
	}
	dup_fds(&info, 0, new, STDIN_FILENO);
	execve(path, info.cmds[info.cmd_index + 1], info.env);
	free(path);
	cleanup_pipex(info, "execve");
}

void	parent(t_pipex info)
{
	char	*path;

	waitpid(info.pid, NULL, WNOHANG);
	if (info.outfile < 0)
		cleanup_pipex(info, "open");
	unlink("here_doc");
	dup_fds(&info, info.outfile, 0, STDOUT_FILENO);
	path = verified_path(info, info.cmd_index);
	if (!path)
	{
		flush_err("command not found: %s\n", info.cmds[info.cmd_index][0]);
		cleanup_pipex(info, NULL);
	}
	execve(path, info.cmds[info.cmd_index], info.env);
	if (path)
		free(path);
	cleanup_pipex(info, "execve");
}
