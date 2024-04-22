/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:59:06 by xlow              #+#    #+#             */
/*   Updated: 2024/02/05 15:47:17 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	pipex_limiter(t_pipex *info, int argc, char **argv, char **env)
{
	info->cmd_index = argc - 5;
	info->openflags = O_CREAT | O_WRONLY | O_APPEND;
	here_doc(info, argv);
	init_pipex_info(info, argc - 1, argv + 1, env);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	info;

	if (argc >= 5)
	{
		if (!ft_strncmp(argv[1], "here_doc", 8) && argc >= 6)
			pipex_limiter(&info, argc, argv, env);
		else
		{
			info.openflags = O_CREAT | O_WRONLY | O_TRUNC;
			info.cmd_index = argc - 4;
			init_pipex_info(&info, argc, argv, env);
		}
		info.pid = fork();
		if (info.pid < 0)
			cleanup_pipex(info, "fork");
		if (!info.pid)
		{
			info.cmd_index--;
			child(info);
		}
		parent(info);
	}
	ft_printf("Provide at least 4 arguments\n");
	return (0);
}
