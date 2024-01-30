/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:25:48 by xlow              #+#    #+#             */
/*   Updated: 2024/01/26 18:40:10 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
//static int	is_number(char *input);
//static int	valid_number(char **input);
//static t_stack	stack_init(int count, char **input);
//static int	non_duplicated_integer(int count, char **input);
t_stack	valid_arg_init(char **input);

// operations
void	s(t_stack *stack);
void	p(t_stack *p_from, t_stack *p_to);
void	r(t_stack *rotate);
void	rr(t_stack *rot);

// push_swap_utils
//static int	ft_sortedness(t_stack a, t_stack b);
//static int	dual_command(char *input, t_stack *a, t_stack *b);
//static void	call_operations(char *input, t_stack *a, t_stack *b);
void	error(void *a, void *b, void *c, void *d);
void	check_input(t_stack *a, t_stack *b);

#endif
