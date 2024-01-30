/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:26:50 by xlow              #+#    #+#             */
/*   Updated: 2024/01/26 21:40:56 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(void *a, void *b, void *c, void *d)
{
	if (a)
	{
		free(a);
		a = NULL;
	}
	if (b)
	{
		free(b);
		b = NULL;
	}
	if (c)
	{
		free(c);
		c = NULL;
	}
	if (d)
	{
		free(d);
		d = NULL;
	}
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_sortedness(t_stack a, t_stack b)
{
	int	i;

	i = 0;
	if (b.count != 0)
		return (0);
	while (i < a.count - 1)
	{
		if (a.stack[i] > a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	dual_command(char *input, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(input, "ss\n"))
	{
		s(a);
		s(b);
	}
	else if (!ft_strcmp(input, "rr\n"))
	{
		r(a);
		r(b);
	}
	else if (!ft_strcmp(input, "rrr\n"))
	{
		rr(a);
		rr(b);
	}
	else
		return (0);
	return (1);
}

static void	call_operations(char *input, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(input, "sa\n"))
		s(a);
	else if (!ft_strcmp(input, "sb\n"))
		s(b);
	else if (!ft_strcmp(input, "pa\n"))
		p(b, a);
	else if (!ft_strcmp(input, "pb\n"))
		p(a, b);
	else if (!ft_strcmp(input, "ra\n"))
		r(a);
	else if (!ft_strcmp(input, "rb\n"))
		r(b);
	else if (!ft_strcmp(input, "rra\n"))
		rr(a);
	else if (!ft_strcmp(input, "rrb\n"))
		rr(b);
	else if (!dual_command(input, a, b))
		error(input, a->stack, b->stack, NULL);
}

void	check_input(t_stack *a, t_stack *b)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		call_operations(input, a, b);
		free(input);
	}
	if (ft_sortedness(*a, *b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a->stack);
	free(b->stack);
}

/*
int	main(void)
{
	t_stack	a;
	t_stack	b;

	a.stack = malloc(16);
	b.stack = malloc(16);
	a.stack[0] = 5, a.stack[1] = 2, a.stack[2] = 6;
	b.stack[0] = 3, b.stack[1] = 1, b.stack[2] = 4;
	a.count = 3;
	b.count = 3;
	a.size = 4;
	b.size = 4;

	printf("%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]);
	printf("%d%d%d\n", b.stack[0], b.stack[1], b.stack[2]);
	take_and_push(&a, &b, &a, 6);
	printf("%d%d%d%d\n", a.stack[0], a.stack[1], a.stack[2], a.stack[3]);
	printf("%d%d%d%d\n", b.stack[0], b.stack[1], b.stack[2], b.stack[3]);
	take_and_push(&b, &a, &a, 4);
	printf("%d%d%d%d\n", a.stack[0], a.stack[1], a.stack[2], a.stack[3]);
	printf("%d%d%d%d\n", b.stack[0], b.stack[1], b.stack[2], b.stack[3]);
	return (0);
}
*/
