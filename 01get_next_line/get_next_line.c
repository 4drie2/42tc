/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/04 21:34:04 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;

	if (!s1 || !s2)
		return ("");
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *)malloc(size_s1 + size_s2 + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, (size_s1 + size_s2 + 1));
	ft_strlcat(dest, (char *)s2, (size_s1 + size_s2 + 1));
	return (dest);
}

/* char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*stash = NULL;
	int			nread;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
			free(buffer);
		if (nread == -1)
			return (NULL);
		if (nread != 0)
			buffer[nread] = '\0';
		if (nread != 0)
			stash = ft_strjoin(stash, buffer);
	}
	temp = ft_strdup(stash);
	char *newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
	{
		char *new_stash = ft_strdup(newline_pos + 1);
		free(stash);
		stash = new_stash;
		if (!stash)
			free(temp);
	}
	else
		free(stash);
	return (temp);
} */

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
	}
	temp = ft_strdup(stash);
	*(temp + ft_strlen(stash) - ft_strlen(ft_strchr(stash, '\n'))) = 0;
	ft_strlcpy(stash, (ft_strchr(stash, '\n') + 1), ft_strlen(stash));
	return (temp);
}

int main(void)
{
	int fd;

	fd = open("hello.txt", O_RDONLY);
	printf("----main1: gnl=|%s|\n\n", get_next_line(fd));
	printf("----main2: gnl=|%s|\n\n", get_next_line(fd));
	printf("----main3: gnl=|%s|\n\n", get_next_line(fd));
	printf("----main4: gnl=|%s|\n\n", get_next_line(fd));
	//printf("\n\n----main5:----\ngnl=%s\n---------\n", get_next_line(fd));
	close(fd);
}
