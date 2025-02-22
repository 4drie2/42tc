/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:01:29 by abidaux           #+#    #+#             */
/*   Updated: 2025/01/11 16:20:57 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>

typedef struct cellule
{
	int				a;
	struct cellule	*next;
}	t_lsc;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen( const char *theString );
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest_str, const void *src_str, size_t numBytes);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size);
int			ft_toupper(int chara);
int			ft_tolower(int chara);
char		*ft_strchr(const char *string, int searchedChar);
char		*ft_strrchr(const char *string, int searchedChar);
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
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_freestr(char **str);
void		new_end(t_lsc **head, int value);
void		free_list(t_lsc *head);
int			ft_printf(const char *god, ...);
