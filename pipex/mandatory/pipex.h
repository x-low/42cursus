/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:59:54 by xlow              #+#    #+#             */
/*   Updated: 2024/02/01 19:07:02 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid;
	char	**paths;
	char	***cmds;
	char	**env;
	int		infile;
	int		outfile;
	int		fd[2];
}	t_pipex;

// INIT_PIPEX

//static char	**init_paths(char **env);
//static char	***init_cmds(char **argv);
t_pipex	init_pipex_info(char **argv, char **env);

// CLEANUP_PIPEX

void	error_on_exit(char *msg);
void	cleanup_fd(int fd);
void	cleanup_pipex(t_pipex info);

// PROCESSES_PIPEX

//static void	dup_fds(t_pipex info, int file, int *pipe, int io);
//static char	*verified_path(t_pipex info, int cmd);
void	child(t_pipex info);
void	parent(t_pipex info);

#endif
