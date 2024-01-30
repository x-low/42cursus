/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:17:44 by xlow              #+#    #+#             */
/*   Updated: 2024/01/24 21:44:12 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	count;
	int	middle;
}	t_stack;

// arg_validation
//static int	is_number(char *argv);
//static int	valid_number(char **argv);
//static t_stack	stack_init(int argc, char **argv);
//static int	non_duplicated_integer(int argc, char **argv);
t_stack	valid_arg_init(char **input);

// operations
void	s(t_stack *stack, t_stack *a);
void	p(t_stack *p_from, t_stack *p_to, t_stack *a);
void	r(t_stack *rot, t_stack *a);
void	rr(t_stack *rot, t_stack *a);
void	operation_parser(char *c_op);

// push_swap_utils
void	error(void *a, void *b, void *c, void *d);
int		ft_sortedness(t_stack a, t_stack b);
void	sort_assignment(t_stack *a, t_stack *b);
void	take_and_push(t_stack *from, t_stack *to, t_stack *a, int n);
void	push_into_chunk(t_stack *a, t_stack *b, int cutoff);

// sort_big
void	regroup(t_stack *a, t_stack *b);
void	partition(t_stack *a, t_stack *b, int set_size);

// sort_element_finders
int		next_smallest(t_stack *stack, int prev);
int		next_biggest(t_stack *stack, int prev);
int		spot_in_stack(t_stack *stack, int n);
int		smallest(t_stack *stack);
int		biggest(t_stack *stack);

// sort_small
void	sort2(t_stack *a);
void	sort3(t_stack *a);
void	sort4(t_stack *a, t_stack *b);
void	sort5(t_stack *a, t_stack *b);

#endif
