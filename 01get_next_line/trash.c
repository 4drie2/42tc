#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*str_join(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = (s1) ? ft_strlen(s1) : 0;
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, len1 + 1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	free(s1);
	return (result);
}

static char	*read_line(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nread;

	while (1)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread < 0)
			return (NULL);
		if (nread == 0)
			break;
		buffer[nread] = '\0';
		*stash = str_join(*stash, buffer);
		if (!*stash)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (*stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*newline_pos;

	newline_pos = ft_strchr(*stash, '\n');
	if (newline_pos)
	{
		line = ft_substr(*stash, 0, newline_pos - *stash + 1);
		*stash = ft_strdup(newline_pos + 1);
	}
	else
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_line(fd, &stash))
		return (NULL);
	if (!stash)
		return (NULL);
	return (extract_line(&stash));
}


//----------------------------

char *get_next_line(int fd)
{
	char *buffer;
	char *temp;
	static char *stash = NULL;
	int nread;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

	while (1)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (nread == 0) // Fin de fichier
			break;

		buffer[nread] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash) // Vérifiez si ft_strjoin a échoué
		{
			free(buffer);
			return (NULL);
		}

		if (ft_strchr(stash, '\n'))
			break;
	}

	free(buffer);
	if (!stash || !*stash) // Si stash est vide ou NULL
		return (NULL);

	temp = ft_strdup(stash);
	if (!temp) // Vérifiez si ft_strdup a échoué
	{
		free(stash);
		return (NULL);
	}

	char *newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
	{
		size_t len_after_newline = ft_strlen(newline_pos + 1);
		char *new_stash = ft_strdup(newline_pos + 1);
		free(stash);
		stash = new_stash;
		if (!stash) // Vérifiez si l'allocation a échoué
		{
			free(temp);
			return (NULL);
		}
	}
	else
	{
		free(stash);
		stash = NULL; // Réinitialisez stash si c'est la fin
	}

	return (temp);
}
