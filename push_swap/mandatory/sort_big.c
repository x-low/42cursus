/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:19:18 by xlow              #+#    #+#             */
/*   Updated: 2024/01/23 20:19:58 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	regroup(t_stack *a, t_stack *b)
{
	int	largest;
	int	next_largest;

	while (b->count >= 2)
	{
		largest = spot_in_stack(b, biggest(b));
		next_largest = spot_in_stack(b, next_biggest(b, biggest(b)));
		if (largest > b->count / 2)
			largest = b->count - largest;
		if (next_largest > b->count / 2)
			next_largest = b->count - next_largest;
		if (largest <= next_largest)
		{
			take_and_push(b, a, a, biggest(b));
			take_and_push(b, a, a, biggest(b));
		}
		else
		{
			take_and_push(b, a, a, next_biggest(b, biggest(b)));
			take_and_push(b, a, a, biggest(b));
			s(a, a);
		}
	}
}

void	partition(t_stack *a, t_stack *b, int set_size)
{
	int	i;
	int	min;

	min = smallest(a);
	while (a->count)
	{
		i = 0;
		while (i < set_size)
		{
			min = next_smallest(a, min);
			if (i == set_size / 2)
				a->middle = min;
			i++;
		}
		i = 0;
		while (i++ < set_size && a->count)
		{
			push_into_chunk(a, b, min);
			if (b->stack[0] < a->middle)
				r(b, a);
		}
	}
	regroup(a, b);
	if (b->count)
		p(b, a, a);
}
