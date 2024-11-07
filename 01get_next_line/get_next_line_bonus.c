/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/07 22:20:44 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		nread;

	nread = 1;
	while (!ft_strchr(stash, '\n') && nread != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		nread = read(fd, buffer, BUFFER_SIZE);
		if ((!stash && nread == 0) || nread == -1)
			return (free(buffer), NULL);
		buffer[nread] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

char	*ft_line(char *temp)
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

char	*ft_rest_line(char *temp, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen(line);
	if (!temp[i])
		return (free(temp), NULL);
	rest = malloc(sizeof(char) * (ft_strlen(temp) + 1));
	if (!rest)
		return (NULL);
	i = ft_strlen(line);
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
		return (NULL);
	temp = ft_read(fd, stash[fd]);
	if (!temp)
	{
		if (stash[fd])
			free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_line(temp);
	stash[fd] = ft_rest_line(temp, line);
	return (line);
}

int main(void)
{
	int fd1, fd2, fd3;
	char *line;

	fd1 = open("hello.txt", O_RDONLY);
	fd2 = open("hello1.txt", O_RDONLY);
	fd3 = open("hello2.txt", O_RDONLY);
	printf("Reading from hello.txt:\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\nReading from hello1.txt:\n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\nReading from hello2.txt:\n");
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
