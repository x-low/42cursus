/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:33:30 by xlow              #+#    #+#             */
/*   Updated: 2023/09/21 13:14:47 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int			ft_printf(const char *str, ...);
//static void	checkplaceholder(const char *str, va_list *args, int *count);
void		ft_putstr(char *str, int *count);
void		ft_putint(int number, int *count);
void		ft_putuint(unsigned int number, int *count);
void		ft_puthex(void *ptr, int *count);
void		ft_dectohex(unsigned int number, char *base, int *count);
void		ft_ulldectohex(unsigned long long number, char *base, int *count);

#endif
