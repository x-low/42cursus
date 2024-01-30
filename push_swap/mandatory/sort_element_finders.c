/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_element_finders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:20:25 by xlow              #+#    #+#             */
/*   Updated: 2024/01/23 20:20:26 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_smallest(t_stack *stack, int prev)
{
	int	i;
	int	next;
	int	curr;

	i = 0;
	next = 2147483647;
	while (i < stack->count)
	{
		curr = stack->stack[i];
		if (curr > prev && curr < next)
			next = curr;
		i++;
	}
	return (next);
}

int	next_biggest(t_stack *stack, int prev)
{
	int	i;
	int	next;
	int	curr;

	i = 0;
	next = -2147483648;
	while (i < stack->count)
	{
		curr = stack->stack[i];
		if (curr < prev && curr > next)
			next = curr;
		i++;
	}
	return (next);
}

int	spot_in_stack(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < stack->count)
	{
		if (n == stack->stack[i])
			return (i);
		i++;
	}
	return (-1);
}

int	smallest(t_stack *stack)
{
	int	i;
	int	res;

	i = 0;
	res = stack->stack[0];
	while (i < stack->count)
	{
		if (stack->stack[i] < res)
			res = stack->stack[i];
		i++;
	}
	return (res);
}

int	biggest(t_stack *stack)
{
	int	i;
	int	res;

	i = 0;
	res = stack->stack[0];
	while (i < stack->count)
	{
		if (stack->stack[i] > res)
			res = stack->stack[i];
		i++;
	}
	return (res);
}
