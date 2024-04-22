/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:59:06 by xlow              #+#    #+#             */
/*   Updated: 2024/02/01 20:06:02 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	info;

	if (argc != 5)
		ft_printf("Provide exactly 4 arguments\n");
	else if (argc == 5)
	{
		info = init_pipex_info(argv, env);
		info.pid = fork();
		if (info.pid < 0)
		{
			perror("fork");
			cleanup_pipex(info);
		}
		if (!info.pid)
			child(info);
		parent(info);
	}
	return (0);
}
