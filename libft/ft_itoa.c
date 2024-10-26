/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:28:42 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 17:38:58 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*make_nb(int n)
{
	int		i;
	char	*nb;

	i = 0;
	while (n >= 1)
	{
		++i;
		n /= 10;
	}
	nb = (char *)malloc(n + 1);
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = make_nb(n);
	i = 0;
	while (n > 10)
	{
		nb[i] = (n % 10) + '0';
		n /= 10;
	}
	nb[i] = (n % 10) + '0';
	nb[i + 1] = '\0';
	return (nb);
}

int main(void)
{
	printf("%s", ft_itoa(123456));
}
