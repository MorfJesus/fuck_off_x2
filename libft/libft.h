/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleanna <eleanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:48:40 by eleanna           #+#    #+#             */
/*   Updated: 2019/10/12 16:45:57 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *strl);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isprint(int c);

int					ft_isascii(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

void				ft_putchar(char c);

void				ft_putstr(char *str);

void				ft_putendl(char *str);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *str, int fd);

void				ft_putendl_fd(char *str, int fd);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **as);

char				*ft_strchr(const char *str, int c);

void				ft_strclr(char *s);

void				ft_strdel(char **as);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f) (unsigned int, char *));

char				*ft_strmap(char *s, char (*f)(char));

char				*ft_strmapi(char *s, char (*f)(unsigned int, char));

char				*ft_strnew(size_t size);

char				*ft_strrchr(const char *str, int c);

char				*ft_strsub(char const *s, unsigned int start, size_t size);

void				*ft_memset(void *str, int c, size_t n);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t count);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *str1, const void *str2, size_t n);

void				*ft_memchr(const void *ptr, int ch, size_t count);

int					ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t n);

char				*ft_strcat(char	*dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dest, const char *src, size_t n);

char				*ft_strstr(const char *hay, const char *needle);

int					ft_atoi(const char *c);

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				ft_putnbr(int n);

int					ft_strcmp(const char *str1, const char *str2);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

char				*ft_strjoin(char *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

void				ft_putnbr_fd(int n, int fd);

char				*ft_itoa(int n);

char				*ft_strnstr(const char *src, const char *targ, size_t len);

size_t				ft_abs(long int n);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstadd_last(t_list **alst, t_list *new);
#	endif
