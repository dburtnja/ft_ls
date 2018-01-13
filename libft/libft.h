/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:21:17 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 09:21:20 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "./get_next_line.h"
# include "ft_printf/ft_printf.h"

# define TRUE		1
# define FALSE		0

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_node
{
	void			*data;
	size_t			data_size;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_doubly_list
{
	size_t			size;
	t_node			*head;
	t_node			*tail;
	int				(*sort_func)(t_node *, t_node *, int);
	int				sort_data;
	int				revers;
	int				sort;
	t_node			*current;
	size_t			current_id;
}					t_doubly_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *restrict dest, const void *restrict src,
		int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *str, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
		size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_atoi_move(char **buf, int *error, int move);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_array(char **str);
int					ft_lentoc(char *s, char c);
int					ft_nbrlen(int i);
void				ft_lstprint_str(t_list *p);
t_list				*ft_strsplit_lst(char const *s, char c);
void				*ft_memalloc_error(size_t size);
long				ft_abs(long nbr);
t_doubly_list		*new_doubly_list(t_node *node,
		int (*sort_func)(t_node *, t_node *, int), int sort_flags, int revers);
t_node				*new_node(void *data, size_t data_size);
void				add_to_front(t_doubly_list *list, t_node *node);
void				add_to_back(t_doubly_list *list, t_node *node);
int					ft_sort_doubly_list(t_doubly_list *list,
		int (*f)(t_node *, t_node *, int), int reverse, int type);
void				*ft_double_list_to_array(t_doubly_list *list);
int					swap_nodes(t_node *first, t_node *second);
int					add_after_node(t_doubly_list *list, t_node *after,
		t_node *node);
void				ft_add_with_sort(t_doubly_list *sort_list, t_node *node);

#endif
