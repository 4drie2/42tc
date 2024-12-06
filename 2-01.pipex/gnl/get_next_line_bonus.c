/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/12/06 13:08:55 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_read(int fd, char *stash)
{
	char	*buffer;
	int		nread;

	nread = 1;
	while (!gnl_strchr(stash, '\n') && nread != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		nread = read(fd, buffer, BUFFER_SIZE);
		if ((!stash && nread == 0) || nread == -1)
			return (free(buffer), NULL);
		buffer[nread] = '\0';
		stash = gnl_strjoin(stash, buffer);
	}
	return (stash);
}

char	*gnl_line(char *temp)
{
	char	*line;
	int		i;

	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (temp[++i] && temp[i] != '\n')
		line[i] = temp[i];
	line[i] = temp[i];
	if (temp[i] == '\n')
		++i;
	line[i] = '\0';
	return (line);
}

char	*gnl_rest_line(char *temp, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = gnl_strlen(line);
	if (!temp[i])
		return (free(temp), NULL);
	rest = malloc(sizeof(char) * (gnl_strlen(temp) + 1));
	if (!rest)
		return (NULL);
	i = gnl_strlen(line);
	j = 0;
	while (temp[i])
		rest[j++] = temp[i++];
	rest[j] = '\0';
	return (free(temp), rest);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (free(stash), NULL);
	temp = gnl_read(fd, stash[fd]);
	if (!temp)
	{
		if (stash[fd])
			free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = gnl_line(temp);
	stash[fd] = gnl_rest_line(temp, line);
	return (line);
}

/* int	main(void)
{
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("hello.txt", O_RDONLY);
	fd2 = open("hello1.txt", O_RDONLY);
	fd3 = open("hello2.txt", O_RDONLY);
	i = 0;
	while (++i <= 4)
	{
		printf("line [%d]: %s", i, get_next_line(fd1));
		printf("line [%d]: %s", i, get_next_line(fd2));
		printf("line [%d]: %s", i, get_next_line(fd3));
		printf("--------------------\n");
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
