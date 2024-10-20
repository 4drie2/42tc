/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:32:50 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/17 18:39:36 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest_str, const void *src_str, t_size numBytes)
{
	unsigned char	*s;
	unsigned char	*d;
	t_size			i;

	s = (char *)src_str;
	d = (char *)dest_str;
	if (d > s)
	{
		while (numBytes > 0)
		{
			numBytes--;
			d[numBytes] = s[numBytes];
		}
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
