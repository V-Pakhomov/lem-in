/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:25:36 by rciera            #+#    #+#             */
/*   Updated: 2020/09/02 17:18:17 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "colors.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../ft_queue/includes/ft_queue.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define BUFF_SIZE 32

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isnum(char *str);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
char			*ft_strrev(char *str);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strcat(char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_bzero(void *arr, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, void *src, size_t len);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
char			*ft_strdup(const char *str);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str1, const char *str2);
char			*ft_strnstr(const char *str1, const char *str2, size_t len);
int				ft_atoi(const char *str);
long long		ft_atoll(const char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(long long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_itoa_base(size_t num, size_t base);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lst_push_back(t_list **lst, t_list *new);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_swap(char *a, char *b);
void			ft_lstrev(t_list **list);
size_t			ft_lstsize(t_list *list);
int				ft_sqrt(int nb);
int				get_next_line(const int fd, char **line);
long long		ft_abs(long long n);
int				ft_min(int n, int m);
int				ft_max(int n, int m);
long long		ft_pow(int n, int p);
int				ft_arrsize(char **arr);
int				ft_isinteger(char *nbr);
int				ft_arraylen(char **arr);
int				ft_arrayfree(char **arr);

#endif
