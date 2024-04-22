/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:12:02 by xlow              #+#    #+#             */
/*   Updated: 2024/02/29 17:42:18 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_files(t_pipex *info, int argc, char **argv)
{
	if (info->openflags == (O_CREAT | O_WRONLY | O_TRUNC))
		info->infile = open(argv[1], O_RDONLY);
	info->outfile = open(argv[argc - 1], info->openflags, 0644);
}

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
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path + 5, ':');
	return (paths);
}

static char	***init_cmds(int argc, char **argv)
{
	char	***cmds;
	int		i;
	int		j;

	i = 2;
	j = 0;
	cmds = ft_calloc(sizeof(char **), argc - 2);
	if (!cmds)
		return (NULL);
	while (i < argc - 1)
	{
		cmds[j] = ft_split(argv[i], ' ');
		if (!cmds[j])
		{
			while (--j >= 0)
			{
				ft_free_split(cmds[j]);
				return (NULL);
			}
		}
		i++;
		j++;
	}
	return (cmds);
}

void	init_pipex_info(t_pipex *info, int argc, char **argv, char **env)
{
	info->argv = argv;
	info->env = env;
	init_files(info, argc, argv);
	if (pipe(info->fd) < 0)
		error_on_exit("pipe");
	info->paths = init_paths(env);
	if (!info->paths)
		error_on_exit("paths");
	info->cmds = init_cmds(argc, argv);
	if (!info->cmds)
	{
		ft_free_split(info->paths);
		error_on_exit("cmds");
	}
}
