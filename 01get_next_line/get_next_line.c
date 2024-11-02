/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/02 00:58:48 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../00libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*gnl(int fd)
{
	char		*buffer;
	static char	*stash;
	int			nread;

	stash = "";
	buffer = (char *)malloc(sizeof(char) * (int)BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(buffer, '\n'))
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		buffer[nread] = '\0';
		if (nread == -1)
			return (0);
		stash = ft_strjoin(stash, buffer);
		printf("read=%i, buffer=%s\n", nread, buffer); ///
	}
	printf("stash=|%s|\n" ,stash);
	return (stash);
}

int main(void)
{
	int fd;

	fd = open("hello.txt", O_RDONLY);
	gnl(fd);
	close(fd);
}
