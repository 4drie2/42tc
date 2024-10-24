/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:16:20 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/24 18:36:27 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*dest;
	t_size	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (0);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	while (len > i && s[start + i])
	{
		dest[i] = s[start + i];
		++i;
	}
	dest[start + i] = '\0';
	return (dest);
}
