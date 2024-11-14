/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:11:27 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/14 21:59:10 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
//#include "libft/libft.h"

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	string_fd(const char *str, int fd)
{
	int len = 0;
	while (str[len])
		len++;
	return write(fd, str, len);
}

int	nbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		string_fd("-2147483648", fd);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			count += write(fd, &(char){('-')}, 1);
		}
		if (n < 10)
			count += write(fd, &(char){(n + '0')}, 1);
		if (n > 9)
		{
			nbr_fd((n / 10), fd);
			nbr_fd((n % 10), fd);
		}
	}
	return (count);
}

int ft_type(char type, va_list args)
{
	if (type == 's')
		return (string_fd(va_arg(args, const char *), 1));
	else if (type == 'd')
		return (nbr_fd((va_arg(args, int)), 1));
	else if (type == 'c')
		return (write(1, &(char){va_arg(args, int)}, 1));
	return (0);
}

int ft_printf(const char *god, ...)
{
	int return_value;
	va_list args;
	va_start(args, god);

	return_value = 0;
	while (*god)
	{
		if (*god == '%')
			return_value += ft_type(*++god, args);
		else
			write(1, god, 1);
		++god;
	}
	va_end(args);
	return (return_value);
}

int main()
{
	char *god = "Hello !";

	while (*god)
	{
		write(1, god, 1);
		++god;
	}
}
