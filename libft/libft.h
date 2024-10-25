/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:01:29 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/25 17:18:12 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef unsigned int	t_size;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
t_size		ft_strlen( const char *theString );
void		*ft_memset(void *s, int c, t_size n);
void		ft_bzero(void *s, t_size n);
void		*ft_memcpy(void *dest, const void *src, t_size n);
void		*ft_memmove(void *dest_str, const void *src_str, t_size numBytes);
t_size		ft_strlcpy(char *dst, const char *src, t_size dstsize);
unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size);
int			ft_toupper(int chara);
int			ft_tolower(int chara);
char		*ft_strchr(const char *string, int searchedChar);
char		*ft_strrchr(const char *string, int searchedChar);
int			ft_strncmp(const char *s1, const char *s2, t_size n);
void		*ft_memchr(const void *s, int c, t_size n);
int			ft_memcmp(const void *s1, const void *s2, t_size n);
char		*ft_strnstr(const char *big, const char *little, t_size len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(t_size nmemb, t_size size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, t_size len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
