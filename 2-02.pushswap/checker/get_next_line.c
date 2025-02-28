/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2025/02/28 14:58:18 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	static char	*stash;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), NULL);
	temp = gnl_read(fd, stash);
	if (!temp)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	line = gnl_line(temp);
	stash = gnl_rest_line(temp, line);
	return (line);
}

/* int main(void)
{
	int fd;

	fd = open("hello.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
} */
