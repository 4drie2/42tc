/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:32:50 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 23:43:09 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src_str;
	d = (unsigned char *)dest_str;
	if (!src_str && !dest_str)
		return (0);
	if (d > s)
	{
		while (numBytes-- > 0)
			d[numBytes] = s[numBytes];
	}
	else
	{
		i = 0;
		while (i < numBytes)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest_str);
}
