/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:12:02 by xlow              #+#    #+#             */
/*   Updated: 2024/02/01 20:57:25 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**init_paths(char **env)
{
	char	**paths;
	char	*env_path;
	int		i;

	env_path = NULL;
	i = 0;
	while (!env_path && env[i])
	{
		env_path = ft_strnstr(env[i], "PATH=", 5);
		i++;
	}
	paths = ft_split(env_path + 5, ':');
	return (paths);
}

static char	***init_cmds(char **argv)
{
	char	***cmds;

	cmds = ft_calloc(sizeof(char **), 3);
	if (!cmds)
		return (NULL);
	cmds[0] = ft_split(argv[2], ' ');
	if (!cmds[0])
	{
		free(cmds);
		return (NULL);
	}
	cmds[1] = ft_split(argv[3], ' ');
	if (!cmds[1])
	{
		free(cmds[1]);
		free(cmds);
		return (NULL);
	}
	cmds[2] = NULL;
	return (cmds);
}

t_pipex	init_pipex_info(char **argv, char **env)
{
	t_pipex	info;

	info.infile = open(argv[1], O_RDONLY);
	info.outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipe(info.fd) < 0)
		error_on_exit("pipe");
	info.env = env;
	info.paths = init_paths(env);
	if (!info.paths)
		error_on_exit("paths");
	info.cmds = init_cmds(argv);
	if (!info.cmds)
	{
		ft_free_split(info.paths);
		error_on_exit("cmds");
	}
	return (info);
}
