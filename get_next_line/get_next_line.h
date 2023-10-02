/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 07:43:17 by xlow              #+#    #+#             */
/*   Updated: 2023/09/30 05:37:27 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
void	to_assign(char **storage, char *hold, char **res);
char	*to_save(char *hold);
char	*to_print(char *hold);
void	to_retrieve(int fd, char **storage, char **hold);
void	ft_free(char **s1, char **s2, char **s3);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		is_there_nl(char *s);

#endif
