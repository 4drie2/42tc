/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:56:26 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 23:43:14 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_isspace(char s)
{
	if ((s >= 9 && s <= 13) || s == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	index;
	int		sign;
	int		nbr;

	index = 0;
	sign = 1;
	nbr = 0;
	while (ft_is_isspace(nptr[index]))
		++index;
	if (nptr[index] == '+')
		++index;
	else if (nptr[index] == '-')
	{
		sign = -1;
		++index;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		nbr = nbr * 10 + (nptr[index] - '0');
		++index;
	}
	return (nbr * sign);
}
