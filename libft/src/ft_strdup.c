/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:38:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/23 17:16:44 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*cpy;
	t_size len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	cpy = (char *)malloc(len_s + 1);
	if (cpy == NULL)
		return (NULL);
	ft_memcpy(cpy, s, len_s);
	cpy[len_s] = '\0';
	return (cpy);
}