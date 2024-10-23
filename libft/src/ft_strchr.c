/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:45:21 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/21 17:27:10 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	while (*string)
	{
		if (*string == (char)searchedChar)
			return ((char *)string);
		string++;
	}
	if (searchedChar == '\0')
		return ((char *)string);
	return (0);
}
