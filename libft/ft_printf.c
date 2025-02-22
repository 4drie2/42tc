/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:11:27 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/15 01:19:09 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
//#include "libft/libft.h"

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	string_fd(const char *str, int fd)
{
	int	len;

	if (!str)
		return (write(fd, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
	return (len);
}

int	put_nbr_base_fd(unsigned long long nbr, int base, int fd)
{
	char	*digits;
	int		count;

	count = 0;
	digits = "0123456789abcdef";
	if (nbr == (unsigned long long)(-2147483648))
		return (string_fd("-2147483648", fd));
	if (nbr >= (unsigned long long)base)
		count += put_nbr_base_fd(nbr / base, base, fd);
	count += write(fd, &digits[nbr % base], 1);
	return (count);
}

int	adress_fd(unsigned long long nbr, int fd)
{
	if (nbr == 0)
		return (write(fd, "(nil)", 5));
	write(fd, "0x", 2);
	return (put_nbr_base_fd(nbr, 16, fd) + 2);
}

int	ft_type(char type, va_list args)
{
	if (type == 's')
		return (string_fd(va_arg(args, const char *), 1));
	else if (type == 'd' || type == 'i')
		return (put_nbr_base_fd((va_arg(args, int)), 10, 1));
	else if (type == 'c')
		return (write(1, &(char){va_arg(args, int)}, 1));
	else if (type == 'p')
		return (adress_fd((unsigned long long)va_arg(args, void *), 1));
	else if (type == 'u')
		return (put_nbr_base_fd(((unsigned int)va_arg(args, int)), 10, 1));
	return (0);
}

int	ft_printf(const char *god, ...)
{
	int		return_value;
	va_list	args;

	va_start(args, god);
	return_value = 0;
	while (*god)
	{
		if (*god == '%')
			return_value += ft_type(*++god, args);
		else
			return_value += write(1, god, 1);
		++god;
	}
	va_end(args);
	return (return_value);
}
