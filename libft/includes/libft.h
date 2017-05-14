/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:56 by jmoucade          #+#    #+#             */
/*   Updated: 2017/03/16 00:05:46 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <colors.h>

# define ABS(x) (x<0) ? (x*-1) : (x)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

void			*ft_memset (void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, int nb);
size_t			ft_strlcat(char *dest, const char *src, unsigned int size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strdelnew(char **addr, char *value);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);

void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putendl(char const *s);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

void			ft_putcharcolor(char c, char *color);
void			ft_putstrcolor(const char *str, char *color);
void			ft_putendlcolor(char const *s, char *color);
void			ft_putnbrcolor(int nb, char *color);
void			ft_putcharcolor_fd(char c, int fd, char *color);
void			ft_putstrcolor_fd(char const *s, int fd, char *color);
void			ft_putendlcolor_fd(char const *s, int fd, char *color);
void			ft_putnbrcolor_fd(int n, int fd, char *color);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelfirst(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdelnext(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd_start(t_list **alst, t_list *new);
void			ft_lstadd_end(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstselect(t_list **l, char *elem, int (*f)(t_list*, char*));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstrev(t_list **alst);
size_t			ft_lstlen(t_list *lst);

size_t			ft_nbrlen(int nbr);
void			*ft_memrcpy(void *dst, const void *src, size_t n);
int				ft_is_space(char c);
void			ft_swap(int *a, int *b);
int				*ft_range(int min, int max);
void			ft_foreach(int *tab, int length, void (*f)(int));
int				ft_count_if(char **tab, int (*f)(char*));
void			ft_putstrtab(char **tab);
void			ft_delstrtab(char **tab);
void			ft_putnbr_base(int nbr, char *base);
char			*ft_itoa_base(int nbr, char *base);
int				ft_stracat(char **dst, char *src);
int				ft_addchar(char **dst, char c);
char			***ft_get_triple_tab(int line, int columm, int len);
void			ft_print_triple_tab(char ***tab);
void			ft_delete_triple_tab(char ***tab);
int				ft_strpadding_right(char **str, int len_max);
int				ft_strpadding_left(char **str, int len_max);
char			*ft_str3join(char const *s1, char const *s2, char const *s3);

#endif
