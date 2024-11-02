/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:11 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/02 17:59:40 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../00libft/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}

char	*gnl(int fd)
{
	char		*buffer;
	char		*temp;
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
	printf("\npretemp=|%s|\n", ft_strchr(stash, '\n'));
	temp = stash;
	stash = malloc(ft_strlen(stash) - ft_strlen(ft_strchr(stash, '\n')) + 1);
	ft_strlcpy(stash, ft_strchr(stash, '\n'), ft_strlen(ft_strchr(stash, '\n')));
	printf("temp=|%s|\n" ,temp);
	printf("stash=|%s|\n" ,stash);
	return (temp);
}

int main(void)
{
	int fd;

	fd = open("hello.txt", O_RDONLY);
	gnl(fd);
	close(fd);
}
