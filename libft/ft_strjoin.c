/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:17:43 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/25 16:55:56 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_size	size_s1;
	t_size	size_s2;
	char	*dest;

	if (!s1 || !s2)
		return (0);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *)malloc(size_s1 + size_s2 + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, (size_s1 + size_s2 + 1));
	ft_strlcat(dest, (char *)s2, (size_s1 + size_s2 + 1));
	return (dest);
}
