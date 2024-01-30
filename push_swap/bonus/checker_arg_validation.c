/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_arg_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:26:29 by xlow              #+#    #+#             */
/*   Updated: 2024/01/26 18:40:47 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_number(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (ft_isdigit(input[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	valid_number(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i][0]))
		{
			if (input[i][0] != '-'
					|| (input[i][0] == '-' && !input[i][++j]))
				return (0);
			while (input[i][j])
			{
				if (!ft_isdigit(input[i][j]))
					return (0);
				j++;
			}
		}
		else if (is_number(input[i]) == 0)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

static t_stack	stack_init(int count, char **input)
{
	t_stack	a;
	int		i;

	i = 0;
	a.size = count;
	a.stack = ft_calloc(sizeof(int), a.size);
	if (!a.stack)
		error(NULL, NULL, NULL, NULL);
	a.count = count;
	if (!input)
		return (a);
	while (i < count)
	{
		a.stack[i] = ft_atoi(input[i]);
		i++;
	}
	return (a);
}

static int	non_duplicated_integer(int count, char **input)
{
	long	i;
	long	j;

	i = 0;
	while (i < count)
	{
		j = ft_atol(input[i]);
		if (j > 2147483647 || j < -2147483648)
			return (0);
		i++;
	}
	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	valid_arg_init(char **input)
{
	t_stack	a;
	int		count;

	if (!input)
		error(NULL, NULL, NULL, NULL);
	count = 0;
	while (input[count])
		count++;
	if (valid_number(input) == 0)
		error(NULL, NULL, NULL, NULL);
	a = stack_init(count, input);
	if (non_duplicated_integer(count, input) == 0)
		error(a.stack, NULL, NULL, NULL);
	return (a);
}

/*
int	main(int argc, char **input)
{
	t_stack	a;

	a = valid_arg_init(argc, input);
	printf("%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]);
	r(&a, &a);
	printf("%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]);
	rev_r(&a, &a);
	printf("%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]);
	return (0);
}*/
