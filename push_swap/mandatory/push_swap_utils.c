/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:18:37 by xlow              #+#    #+#             */
/*   Updated: 2024/01/26 19:35:38 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_sortedness(t_stack a, t_stack b)
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

void	sort_assignment(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (ft_sortedness(*a, *b))
		return ;
	if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
	else if (size <= 100)
		partition(a, b, 21);
	else
		partition(a, b, 50);
	operation_parser("END");
}

void	take_and_push(t_stack *from, t_stack *to, t_stack *a, int n)
{
	int	i;

	i = 0;
	if (from->count <= 0)
		return ;
	while (i < from->count)
	{
		if (n == from->stack[i])
			break ;
		i++;
	}
	if (i <= from->count / 2)
		while (from->stack[0] != n)
			r(from, a);
	else
		while (from->stack[0] != n)
			rr(from, a);
	p(from, to, a);
}

void	push_into_chunk(t_stack *a, t_stack *b, int cutoff)
{
	int	i;

	i = 0;
	while (i < a->count)
	{
		if (a->stack[i] <= cutoff)
			break ;
		i++;
	}
	take_and_push(a, b, a, a->stack[i]);
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
