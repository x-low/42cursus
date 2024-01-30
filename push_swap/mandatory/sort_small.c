/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:21:51 by xlow              #+#    #+#             */
/*   Updated: 2024/01/23 20:23:08 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *a)
{
	if (a->stack[0] > a->stack[1])
		s(a, a);
}

void	sort3(t_stack *a)
{
	int	index_smallest;

	index_smallest = spot_in_stack(a, smallest(a));
	if (index_smallest == 0)
		r(a, a);
	if (index_smallest == 1)
		rr(a, a);
	sort2(a);
	rr(a, a);
}

void	sort4(t_stack *a, t_stack *b)
{
	take_and_push(a, b, a, smallest(a));
	sort3(a);
	p(b, a, a);
}

void	sort5(t_stack *a, t_stack *b)
{
	take_and_push(a, b, a, smallest(a));
	sort4(a, b);
	p(b, a, a);
}

/*
int	main(void)
{
	t_stack	a;
	t_stack	b;

	a.stack = malloc(16);
	b.stack = malloc(16);
	a.stack[0] = 5, a.stack[1] = 1, a.stack[2] = 3, a.stack[3] = 2;
	//b.stack[0] = 3, b.stack[1] = 1, b.stack[2] = 4;
	a.count = 5;
	b.count = 0;
	a.size = 5;
	b.size = 5;

	printf("%d%d%d%d\n", a.stack[0], a.stack[1], a.stack[2], a.stack[3]);
	sort4(&a, &b);
	operation_parser("END");
	printf("%d%d%d%d\n", a.stack[0], a.stack[1], a.stack[2], a.stack[3]);
	free(a.stack);
	free(b.stack);
	return (0);
}*/

/*
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	(void) argc;
	a.stack = malloc(20);
	b.stack = malloc(20);
	a.stack[0] = ft_atoi(argv[1]), a.stack[1] = ft_atoi(argv[2]);
	a.stack[2] = ft_atoi(argv[3]), a.stack[3] = ft_atoi(argv[4]);
	a.stack[4] = ft_atoi(argv[5]);
	a.count = 5;
	a.size = 5;
	b.count = 0;
	b.size = 5;

	printf("%d%d%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]
	a.stack[3], a.stack[4]);
	sort5(&a, &b);
	printf("%d%d%d%d%d\n", a.stack[0], a.stack[1]
	a.stack[2], a.stack[3], a.stack[4]);
	free(a.stack);
	free(b.stack);
	operation_parser("END");
	return (0);
}*/
