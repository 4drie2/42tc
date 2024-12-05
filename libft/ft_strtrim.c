/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:17:43 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 23:32:34 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dest;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_mem(set, s1[start]))
		start++;
	while (ft_strncmp(s1 + (end - ft_strlen(set)), set, ft_strlen(set)))
		end -= ft_strlen(set);
	dest = (char *)malloc(ft_strlen(s1) - (start + end));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1 + start, ft_strlen(s1) - (start + end));
	return (dest);
} */

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	dest = (char *)malloc(end - start + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + start, end - start + 1);
	return (dest);
}
