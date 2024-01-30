/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:25:36 by xlow              #+#    #+#             */
/*   Updated: 2024/01/26 21:36:22 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**quotes;
	int		i;

	if (argc == 1)
		return (0);
	i = -1;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		quotes = ft_split(argv[1], ' ');
		a = valid_arg_init(quotes);
		while (quotes[++i])
			free(quotes[i]);
		free(quotes);
	}
	else
		a = valid_arg_init(argv + 1);
	b.stack = ft_calloc(sizeof(int), a.size);
	b.count = 0;
	b.size = a.size;
	if (!b.stack)
		error(a.stack, NULL, NULL, NULL);
	check_input(&a, &b);
	return (0);
}
