/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/28 15:25:31 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../00libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int	main(void)
{
	char	*buffer;
	int		nread;
	int		fd;

	fd = open("hello.txt", O_RDONLY);
	buffer = (char *)malloc(sizeof(char) * (int)BUFFER_SIZE);
	if (!buffer)
		return (0);
	nread = read(fd, buffer, 32);
	if (nread == -1)
		ft_putstr_fd("Erreur", 1);
	ft_putstr_fd("read=", 1);
	ft_putnbr_fd(nread, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(buffer, 1);
	close(fd);
	return (0);
}
