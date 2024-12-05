/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:27:29 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 21:02:05 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	const char	*last;

	last = 0;
	while (*string)
	{
		if (*string == (unsigned char)searchedChar)
			last = string;
		string++;
	}
	if ((unsigned char)searchedChar == '\0')
		return ((char *)string);
	return ((char *)last);
}
