/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:07:45 by xlow              #+#    #+#             */
/*   Updated: 2024/01/23 20:16:39 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack, t_stack *a)
{
	int	tmp;

	if (stack->count < 2)
		return ;
	tmp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp;
	if (stack == a)
		operation_parser("sa");
	else
		operation_parser("sb");
}

/*
void	p(t_stack *pushed_from, t_stack *pushed_to, t_stack *a)
{
	t_stack	new_from;
	t_stack	new_to;

	if (pushed_from->count < 1)
		return ;
	if (pushed_to == a)
		operation_parser("pa");
	else
		operation_parser("pb");
	new_to.count = pushed_to->count + 1;
	new_to.size = pushed_to->size;
	new_to.stack = malloc(new_to.size * sizeof(int));
	new_from.count = pushed_from->count - 1;
	new_from.size = pushed_from->size;
	new_from.stack = malloc(pushed_from->size * sizeof(int));
	if (!new_to.stack || !new_from.stack)
		error(new_to.stack, new_from.stack, pushed_from->stack, pushed_to->stack);
	new_to.stack[0] = pushed_from->stack[0];
	while (pushed_to->count-- > 0)
		new_to.stack[pushed_to->count + 1] = pushed_to->stack[pushed_to->count];
	free(pushed_to->stack);
	*pushed_to = new_to;
	while(new_from.count-- > 0)
		new_from.stack[new_from.count] = pushed_from->stack[new_from.count + 1];
	new_from.count = pushed_from->count - 1;
	free(pushed_from->stack);
	pushed_from->stack = new_from.stack;
}*/

void	p(t_stack *p_from, t_stack *p_to, t_stack *a)
{
	t_stack	new_from;
	t_stack	new_to;

	if (p_from->count < 1)
		return ;
	if (p_to == a)
		operation_parser("pa");
	else
		operation_parser("pb");
	new_from.count = --p_from->count;
	new_to.count = p_to->count;
	new_from.stack = ft_calloc(p_from->size, sizeof(int));
	new_to.stack = ft_calloc(p_to->size, sizeof(int));
	if (!new_from.stack || !new_to.stack)
		error(new_from.stack, new_to.stack, p_from->stack, p_to->stack);
	while (new_from.count-- > 0)
		new_from.stack[new_from.count] = p_from->stack[new_from.count + 1];
	new_to.stack[0] = p_from->stack[0];
	while (new_to.count-- > 0)
		new_to.stack[new_to.count + 1] = p_to->stack[new_to.count];
	p_to->count++;
	free(p_from->stack);
	free(p_to->stack);
	p_from->stack = new_from.stack;
	p_to->stack = new_to.stack;
}

void	r(t_stack *rotate, t_stack *a)
{
	int	tmp;
	int	i;

	if (rotate->count < 2)
		return ;
	tmp = rotate->stack[0];
	i = 0;
	while (i < rotate->count - 1)
	{
		rotate->stack[i] = rotate->stack[i + 1];
		i++;
	}
	rotate->stack[i] = tmp;
	if (rotate == a)
		operation_parser("ra");
	else
		operation_parser("rb");
}

void	rr(t_stack *rot, t_stack *a)
{
	int	tmp;
	int	i;

	if (rot->count < 2)
		return ;
	tmp = rot->stack[rot->count - 1];
	i = 0;
	while (i < rot->count - 1)
	{
		rot->stack[rot->count - 1 - i] = rot->stack[rot->count - 2 - i];
		i++;
	}
	rot->stack[0] = tmp;
	if (rot == a)
		operation_parser("rra");
	else
		operation_parser("rrb");
}

void	operation_parser(char *c_op)
{
	static char	*p_op;

	if (!p_op && ft_strncmp(c_op, "E", 1))
		p_op = ft_strdup(c_op);
	else if (p_op)
	{
		if (!ft_strncmp(p_op, "s", 1) && !ft_strncmp(c_op, "s", 1))
			ft_printf("ss\n");
		else if ((!ft_strncmp(p_op, "ra", 2) && !ft_strncmp(c_op, "rb", 2))
			|| (!ft_strncmp(p_op, "rb", 2) && !ft_strncmp(c_op, "ra", 2)))
			ft_printf("rr\n");
		else if ((!ft_strncmp(p_op, "rra", 3) && !ft_strncmp(c_op, "rrb", 3))
			|| (!ft_strncmp(p_op, "rrb", 3) && !ft_strncmp(c_op, "rra", 3)))
			ft_printf("rrr\n");
		else
		{
			ft_printf("%s\n", p_op);
			if (ft_strncmp(c_op, "E", 1))
				ft_printf("%s\n", c_op);
		}
		free(p_op);
		p_op = NULL;
	}
}

/*
int	main(void)
{
	t_stack	a;
	t_stack	b;

	a.stack = malloc(12);
	b.stack = malloc(16);
	a.stack[0] = 5, a.stack[1] = 2, a.stack[2] = 6;
	b.stack[0] = 3, b.stack[1] = 1, b.stack[2] = 4;
	a.count = 3;
	b.count = 3;

	printf("%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]);
	printf("%d%d%d\n", b.stack[0], b.stack[1], b.stack[2]);
	s(&a, &a);
	s(&b, &a);
	printf("%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]);
	printf("%d%d%d\n", b.stack[0], b.stack[1], b.stack[2]);
	p(&a, &a, &b);
	printf("%d%d%d\n", a.stack[0], a.stack[1], a.stack[2]);
	printf("%d%d%d\n", b.stack[0], b.stack[1], b.stack[2]);
	return (0);
}*/

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
	p(&a, &a, &b);
	printf("%d%d%d%d\n", a.stack[0], a.stack[1], a.stack[2], a.stack[3]);
	printf("%d%d%d%d\n", b.stack[0], b.stack[1], b.stack[2], b.stack[3]);
	p(&a, &b, &a);
	printf("%d%d%d%d\n", a.stack[0], a.stack[1], a.stack[2], a.stack[3]);
	printf("%d%d%d%d\n", b.stack[0], b.stack[1], b.stack[2], b.stack[3]);
	return (0);
}*/

/*
int	main(void)
{
	t_stack	a;
	t_stack b;

	a.size = 5;
	a.count = 5;
	a.stack = malloc(5 * sizeof(int));
	a.stack[0] = 7, a.stack[1] = 2, a.stack[2] = 4, a.stack[3] = 0, a.stack[4] = 9;
	b.size = 5;
	b.count = 5;
	b.stack = malloc(5 * sizeof(int));
	b.stack[0] = 1, b.stack[1] = 2, b.stack[2] = 3, b.stack[3] = 4, b.stack[4] = 5;
	int i = 0;
	int j = 0;
	while (j < 6)
	{
		i = 0;
		while (i < 5)
		{
			printf("a:%d", a.stack[i]);
			printf("\n");
			printf("b:%d\n", b.stack[i]);
			i++;
		}
		printf("\n");
		rr(&a, &b);
		j++;
	}
	return (0);
}*/

/*
int	main(void)
{
	t_stack	a;
	t_stack	b;
	int i = 0;
	int j = 0;
	int k = 0;
	a.size = 5;
	a.count = 5;
	a.stack = malloc(5 * sizeof(int));
	a.stack[0] = 7, a.stack[1] = 2, a.stack[2] = 4, a.stack[3] = 0, a.stack[4] = 9;
	b.size = 5;
	b.count = 5;
	b.stack = malloc(5 * sizeof(int));
	b.stack[0] = 1, b.stack[1] = 2, b.stack[2] = 3, b.stack[3] = 4, b.stack[4] = 5;


	while (j < 5)
	{
		printf("a on run %d\n", j);
		while (i < 5)
		{
			printf("%d", a.stack[i]);
			i++;
		}
		printf("\n");
		printf("b on run %d\n", j);
		while (k < 5)
		{
			printf("%d", b.stack[k]);
			k++;
		}
		printf("\n");
		i = 0;
		k = 0;
		j++;
		rev_r(&a, &a);
		rev_r(&b, &a);
	}
	return (0);
}*/
