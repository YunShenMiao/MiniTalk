/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:08:07 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/12 16:24:38 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(char c);
int					ft_isalpha(char c);
int					ft_isascii(char c);
int					ft_isdigit(char c);
int					ft_isprint(char c);
void				*ft_memset(void *str, int d, size_t n);
int					ft_strlen(char const *stri);
int					ft_atoi(const char *str);
void				*ft_bzero(void *str, unsigned int nbyte);
void				*ft_memchr(const void *str, int c, unsigned int nbytes);
int					ft_memcmp(void *str1, void *str2, unsigned int nbytes);
void				*ft_memcpy(void *dest, const void *source,
						unsigned int nbytes);
void				*ft_memmove(void *dest, const void *source,
						unsigned int nbytes);
char				*ft_strchr(char *str, int c);
size_t				ft_strlcat(char *dest, const char *src, size_t nbytes);
size_t				ft_strlcpy(char *dest, const char *src, size_t nbytes);
int					ft_strncmp(const char *str1, const char *str2,
						unsigned int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strnstr(const char *source, const char *sm, size_t len);
void				*ft_calloc(size_t nitems, size_t size);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strrchr(const char *str, int c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char				**ft_split(char const *s, char c);

#endif
