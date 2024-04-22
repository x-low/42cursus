/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:53:32 by xlow              #+#    #+#             */
/*   Updated: 2024/02/08 21:54:52 by xlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <assert.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void						*content;
	struct s_list				*next;
}	t_list;

// initial libft
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// printf
int			ft_printf(const char *str, ...);
void		ft_putstr(char *str, int *count);
void		ft_putint(int number, int *count);
void		ft_putuint(unsigned int number, int *count);
void		ft_puthex(void *ptr, int *count);
void		ft_dectohex(unsigned int number, char *base, int *count);
void		ft_ulldectohex(unsigned long long number, char *base, int *count);

// printf_fd
int			ft_printf_fd(int fd, const char *str, ...);
void		pf_fd_putstr(int fd, char *str, int *count);
void		pf_fd_putint(int fd, int number, int *count);
void		pf_fd_putuint(int fd, unsigned int number, int *count);
void		pf_fd_puthex(int fd, void *ptr, int *count);
void		pf_fd_dectohex(int f, unsigned int number, char *base, int *count);
void		pf_fd_ullhex(int fd, unsigned long long number, char *base, int *count);

// gnl
char		*get_next_line(int fd);
void		to_assign(char **storage, char *hold, char **res);
char		*to_save(char *hold);
char		*to_print(char *hold);
void		to_retrieve(int fd, char **storage, char **hold);
void		ft_free(char **s1, char **s2, char **s3);
int			is_there_nl(char *s);
void		*gnl_calloc(size_t nmemb, size_t size);
char		*gnl_strjoin(char *s1, char *s2);
char		*gnl_strdup(char *s);

// add-on
int			atoi_with_counter(const char *nptr, int *i, int *sign);
double		ft_atof(const char *s);
long		ft_atol(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_free_split(char **split);

#endif
