/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:22:46 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/18 21:10:05 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	int		pipefd[2];
	int		pid;
	char	*buff;

	if (pipe(pipefd) == -1)
		return(write(2, "erreur 0", 8), 0);
	pid = fork();
	if (pid == -1)
		return(write(2, "erreur 1", 8), 0);
	if (pid == 0)
	{
		close (pipefd[0]);
		write(pipefd[1], "hello", 5);
		close(pipefd[1]);
	}
	else
	{
		close(pipefd[1]);
		read(pipefd[0], buff, 100);
		write(1, &buff, 100);
		close(pipefd[0]);
	}
	return (0);
}
