/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:59:54 by xlow              #+#    #+#             */
/*   Updated: 2024/02/05 15:40:45 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	char	**argv;
	char	**paths;
	char	***cmds;
	char	**env;
	int		infile;
	int		outfile;
	int		openflags;
	int		cmd_index;
	int		fd[2];
}	t_pipex;

// CLEANUP_PIPEX

void	flush_err(char *msg, char *cmd);
void	error_on_exit(char *msg);
void	cleanup_fd(int *fd);
void	cleanup_pipex(t_pipex info, char *msg);

// HERE_DOC

void	here_doc(t_pipex *info, char **argv);

// INIT_PIPEX

//static char	**init_paths(char **env);
//static char	***init_cmds(int argc, char **argv);
void	init_files(t_pipex *info, int argc, char **argv);
void	init_pipex_info(t_pipex *info, int argc, char **argv, char **env);

// PIPEX_BONUS

//static void	pipex_limiter(t_pipex *info, int argc, char **argv, char **env);

// PROCESSES_PIPEX

//static void	dup_fds(t_pipex info, int file, int *pipe, int io);
//static char	*verified_path(t_pipex info, int cmd);
//static void	final_fork(t_pipex info);
void	child(t_pipex info);
void	parent(t_pipex info);

#endif
