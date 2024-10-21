/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:01:29 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/21 16:56:45 by abidaux          ###   ########.fr       */
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
int			ft_strncmp(char *s1, char *s2, unsigned int n);
