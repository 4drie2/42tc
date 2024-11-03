/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/03 17:30:39 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	cpy = (char *)malloc(len_s + 1);
	if (cpy == NULL)
		return (NULL);
	i = -1;
	if (!cpy && !cpy)
		return (0);
	while (++i < len_s)
		((unsigned char *)cpy)[i] = ((unsigned char *)s)[i];
	cpy[len_s] = '\0';
	return (cpy);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*stash;
	int			nread;

	if (!stash)
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
//		printf("read=%i, buffer=%s\n", nread, buffer); ///
	}
//	printf("\npretemp=|%s|\n", ft_strchr(stash, '\n'));
	temp = ft_strdup(stash);
	*(temp + ft_strlen(stash) - ft_strlen(ft_strchr(stash, '\n'))) = 0;
	ft_strlcpy(stash, (ft_strchr(stash, '\n') + 1), ft_strlen(stash));
//	printf("temp=|%s|\n" ,temp);
//	printf("stash=|%s|\n" ,stash);
	return (temp);
}

/* int main(void)
{
	int fd;

	fd = open("hello.txt", O_RDONLY);
	printf("\n\n----main1:----\ngnl=%s\n---------\n", gnl(fd));
	printf("\n\n----main2:----\ngnl=%s\n---------\n", gnl(fd));
	printf("\n\n----main3:----\ngnl=%s\n---------\n", gnl(fd));
	close(fd);
} */
