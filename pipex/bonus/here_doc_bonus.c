/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:31:28 by xlow              #+#    #+#             */
/*   Updated: 2024/02/06 15:44:48 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_pipex *info, char **argv)
{
	char	*read;

	info->infile = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		read = get_next_line(0);
		if (!ft_strncmp(read, argv[2], ft_strlen(argv[2]))
			&& !ft_strncmp(read + ft_strlen(argv[2]), "\n", 1))
		{
			free(read);
			cleanup_fd(&info->infile);
			info->infile = open("here_doc", O_RDONLY);
			return ;
		}
		ft_putstr_fd(read, info->infile);
		free(read);
	}
}
